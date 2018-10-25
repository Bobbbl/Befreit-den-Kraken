#include "wlan_dialog.h"

WLAN_Dialog::WLAN_Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scanSSIDs();

    //Connect Signals & Slots
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SSIDChanged(int)));
    connect(ui->pushButtonConnect, SIGNAL(pressed()), this, SLOT(connectButtonPressed()));
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT(setupButtonPressed()));
}

void WLAN_Dialog::setupButtonPressed(){
    system("sudo sh Einrichten.sh");
}

void WLAN_Dialog::connectButtonPressed(){
    this->pwd = ui->plainTextEdit->toPlainText();
    this->connectNetwork(&this->currentSSID, &this->pwd);
}

void WLAN_Dialog::SSIDChanged(int index){
    QString ssid;
    ssid.append(ui->comboBox->currentText());
    this->currentSSID = ssid;
}


int WLAN_Dialog::connectNetwork(QString *ssid, QString *pwd){
    QString command("sudo sh NewCredentials.sh ");
    qDebug(QString(command + "\""+ ssid->toLatin1()+"\"" + " " + pwd->toLatin1()).toLatin1());
    return system(QString(command + "\"" + ssid->toLatin1() +"\""+ + " " + pwd->toLatin1()).toLatin1());
}

void WLAN_Dialog::scanSSIDs(){

    wireless_scan_head head;
    wireless_scan *result;
    iwrange range;
    int sock;

    //Open Socket to Kernel
    sock = iw_sockets_open();

    /*get metadata for scanning*/
    if(iw_get_range_info(sock, "wlan0", &range)<0){
        printf("Error during iw_get_range_info. Aborting.");
        exit(2);
    }

    /*Perform Scan*/
    if(iw_scan(sock, "wlan0", range.we_version_compiled, &head)<0){
        printf("Error during scan. Aborting...");
        exit(2);
    }

    SSIDList.clear();
    /*Results*/
    result = head.result;
    while(NULL != result){
        qDebug("%s", result->b.essid);
        SSIDList.append(QString(result->b.essid));
        ui->comboBox->addItem(QString(result->b.essid));
        result = result->next;

    }
    ui->comboBox->setCurrentIndex(0);
    this->currentSSID = ui->comboBox->currentText();

}
