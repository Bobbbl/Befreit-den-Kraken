/*Author: Sebastian Draxinger*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wlan_dialog.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this)),
    ph_sensor(new SensorScanner(this, PH_Sensor)),
    trueb_sensor(new SensorScanner(this, Truebungssensor)),
    TempSensor(new QTimer(this))
{
    ui->setupUi(this);
	
    this->backupPath = QCoreApplication::applicationDirPath().append("/Backup");
    Uhr *clock = new Uhr(this);

    //Set Titles & Labels
    ui->pushButtonWLAN->setText("Configure WLAN");
    ui->pushButtonCalibratePH->setText("Calibrate PH");
    ui->pushButtonPH->setText(QString::number(0));
    ui->pushButtonTemp->setText(QString::number(0));
    ui->pushButtonTrueb->setText(QString::number(0));
    ui->gridLayout_6->addWidget(clock);

    this->setWindowTitle("Krake");
	/*Temp sensor timer*/
    TempSensor->start(7000);
    /*Timer credentials*/
    timer->start(6000);
    //timer->start(1);

    this->ph_sensor->start();
    this->trueb_sensor->start();

    //Connect Signals&Slots
    connect(ui->pushButtonWLAN, SIGNAL(pressed()), this, SLOT(WLAN_Button_Pressed()));
    connect(ui->pushButtonCalibratePH, SIGNAL(pressed()), this, SLOT(CalibratePH_Pressed()));
    connect(this->ph_sensor, SIGNAL(newValueSignal(int)), this, SLOT(readPHSensor(int)));
    connect(this->trueb_sensor, SIGNAL(newValueSignal(int)), this, SLOT(readTruebSensor(int)));
	connect(this->timer, SIGNAL(timeout()), this, SLOT(saverSlot()));
    connect(ui->pushButtonTrueb, SIGNAL(pressed()), this, SLOT(pushButtonTruebPressed()));
	connect(clock, SIGNAL(pathReadySignal(QString)), this, SLOT(refreshPath(QString)));
	connect(this->TempSensor, SIGNAL(timeout()), this, SLOT(readTemp()));
	
    readInitFile();

}

double MainWindow::readTemp(){
	/*Check if Sensor is available*/
    QString path = "/sys/bus/w1/devices/28-05176011f3ff/w1_slave";
	QFile file(path);
	QTextStream stream(&file);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		qDebug() << "Temperature Sensor not found... exit";
        return -1;
	}
	else{
		/*Read whole Sensor File*/
		QStringList lines;
        int linecount = 0;
        while(linecount < 5){
			lines.append(stream.readLine());
            linecount++;
	}
	/*Now easy read second line*/
	QStringList line = lines.at(1).split("t=");
	/*Search for substring t=*/
	QString temp_string = line.at(1);
	qDebug() << temp_string;

    this->tempValue = temp_string.toDouble();
    ui->pushButtonTemp->setText(QString::number(this->tempValue/1000));
    }
    return 1;
}

void MainWindow::refreshPath(QString ppath){
	/*Check if Path is valid*/
	QString inipath = QCoreApplication::applicationDirPath();
	inipath.append("/Init_Kraken");
	QFile file(inipath);
	if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
		qDebug() << "Error writing Init_Kraken - File";
		return;
	}
	else{
		QTextStream stream(&file);
		qint64 pos = stream.pos();
		QString line[50];
		int linecount = 0;
        while(linecount < 49){
			line[linecount] = stream.readLine();
			linecount++;
		}
		line[1] = ppath;
		stream.seek(pos);
		for(int i = 0; i<=linecount;i++){
			stream << line[i] << endl;
			this->path = ppath;
		}
		file.close();
		
	}
}



void MainWindow::saverSlot(){
	/*Retrieve file path for saving*/
    QString inipath = QCoreApplication::applicationDirPath();
    inipath.append("/Init_Kraken");
    QFile file(inipath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Error loading Init_Kraken. Quit program...";
        QApplication::quit();
	}
	else{
		QTextStream stream(&file);
        QString line[50];
        int linecount = 0;
        while(linecount < 49){
            line[linecount] = stream.readLine();
            linecount++;
        }
        file.close();
        this->path = line[1];
	}
		

	this->saveAndCheck(this->path, QString::number(this->phValue));
	this->saveAndCheck(this->path, QString::number(this->truebValue));
	this->saveAndCheck(this->path, QString::number(this->tempValue));
    qDebug() << "Schreibe in Datenbank";
	logKrake("/var/www/krakelog.db", "krake", this->tempValue, this->truebValue, this->phValue);
	
}

void MainWindow::saveAndCheck(QString path, QString inhalt){
	//Try Saving to used Path
    if(path.trimmed().isEmpty()){   // Deletes whitespaces before and behind the path and checks then if empty
		this->writingerrorflag = true; 
		qDebug() << "Error: Path Empty";    
		return;
	}
    path = path.trimmed().append("/Kraken_Data.txt");   // append file name to path with trimmed whitespaces
    QFile file(path);
	
	if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)){ // try to open file for Read AND Write Operations
		writingerrorflag = true;
        qDebug() << "Error: " << path << " - Path not Found" << endl << "Backing Up Data";
        file.setFileName(this->backupPath);
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)){
            qDebug() << "Critical Error";
            QApplication::quit();
        }

	}
	writingerrorflag = false;
	QTextStream out(&file); // make text stream for convinient text write 
	out << QDate::currentDate().toString() << " " << QTime::currentTime().toString() << " " << inhalt << endl;
	
	file.flush();
	file.close();
}




void MainWindow::readPHSensor(int value)
{
    this->ph_direct_values.push_back(value);
    if(ph_direct_values.size() >= 10){
        ph_direct_values.erase(ph_direct_values.begin());
    }
    double avrg = this->avarageValues(&this->ph_direct_values);
    double volt = this->adcToVolts(avrg);
    /*Get PH Value by searching for volts from table*/
    std::map<double, double>::iterator low;
    low = ph_sensor->phmap.lower_bound(volt);   //iterator now points to right value +1
    if(low != ph_sensor->phmap.begin()){
        low--;
    }

    //double ph = volt*3.5 + ph7offset;
    /*First Read Look Up Table*/
    interpolation_inputs iinputs = readPHLookUpTable();
    std::vector<double> volts;
    std::vector<double>  ph;
    if(iinputs.x.size() != 0 && iinputs.y.size() != 0){


    if(iinputs.x[0] == -1 || iinputs.y[0] == -1){
        /*Look Up Table kann gerade nicht geöffnet werden, weil 
        1. nicht vorhanden oder defekt
        2. wird gerade modifiziert
        benutze statdessen 
        andere Formel*/
        ph.push_back(volt*3.5 + ph7offset);
    }else{
        volts.push_back(volt);
        /*Then get interpolatet value*/
        ph = interpolation(iinputs, volts);

    }
    
	this->phValue = ph[0] + ph7offset;
    ui->pushButtonPH->setText(QString::number(ph[0] + ph7offset));

    }

}

void MainWindow::readTruebSensor(int value){
    this->trueb_direct_values.push_back(value);

    if(trueb_direct_values.size() >= 10){
        trueb_direct_values.erase(trueb_direct_values.begin());
    }
    double avrg = this->avarageValues(&this->trueb_direct_values);
    double volt = this->adcToVolts(avrg);
    double trueb_backup = (volt-this->lob)/(this->upb - this->lob) * 100.0;
    if(trueb_backup <= 0 ){
        trueb_backup = 0;
    }
    /*First Read Look Up Table*/
    interpolation_inputs iinputs = readTruebLookUpTable();
    std::vector<double> volts;
    std::vector<double>  trueb;
    if(iinputs.x[0] == -1 || iinputs.y[0] == -1){
        /*Look Up Table kann gerade nicht geöffnet werden, weil 
        1. nicht vorhanden oder defekt
        2. wird gerade modifiziert
        benutze statdessen 
        andere Formel*/
        trueb.push_back(trueb_backup);
    }else{
        
        volts.push_back(volt);
        /*Then get interpolatet value*/
        trueb = interpolation(iinputs, volts);
    }
    if(isinf(trueb[0])){
        trueb[0] = 0;
    }
    this->truebValue = trueb[0];
    ui->pushButtonTrueb->setText(QString::number(trueb[0]));
}

void MainWindow::readTempSensor(int value)
{
    this->temp_direct_values.push_back(value);
    if(temp_direct_values.size() >= 10){
        temp_direct_values.erase(temp_direct_values.begin());
    }
    double avrg = this->avarageValues(&this->temp_direct_values);
    double volt = this->adcToVolts(avrg);
    ui->pushButtonTemp->setText(QString::number(volt));
	double temp = volt;
	this->tempValue = temp;
}

void MainWindow::CalibratePH_Pressed()
{
    Calibrate_PH_dialog dialog(this);
    dialog.setModal(true);
    dialog.showFullScreen();
    dialog.exec();
    this->ph4offset = dialog.ph4Offset;
    this->ph7offset = dialog.ph7Offset;
    savePHInit(this->ph7offset, this->ph4offset);
}

void MainWindow::pushButtonTruebPressed()
{
    calibrate_trueb_dialog dialog(this);
    dialog.setModal(true);
    dialog.showFullScreen();
    dialog.exec();
    if(dialog.upflag == true){
        this->upb = dialog.upb;
    }
    if(dialog.downflag == true){
        this->lob = dialog.lob;
    }

    saveTruebInit(this->upb, this->lob);
}

void MainWindow::uhrPressed()
{

}

double MainWindow::avarageValues(std::vector<int> *array)
{
    int sum = 0;
    for (int i = 0; i < array->size(); ++i) {
        sum += array->at(i);
    }
    double avrg = sum / array->size();
    return avrg;
}

void MainWindow::savePHInit(double ph7offset, double ph4offset)
{
    QString inipath = QCoreApplication::applicationDirPath();
    inipath.append("/Init_Kraken");
    QFile file(inipath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Error loading Init_Kraken. Quit program...";
        QApplication::quit();
    }
    else{
        QTextStream stream(&file);
        qint64 pos = stream.pos();
        QString line[50];
        int linecount = 0;
        while(linecount < 49){
            line[linecount] = stream.readLine();
            linecount++;
        }
        line[6] = QString::number(ph7offset);
        line[7] = QString::number(ph4offset);
        stream.seek(pos);
        for(int i = 0; i<=linecount;i++){
            stream << line[i] << endl;
        }

        file.close();
    }
}

void MainWindow::saveTruebInit(double upper, double lower)
{
    QString inipath = QCoreApplication::applicationDirPath();
    inipath.append("/Init_Kraken");
    QFile file(inipath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Error loading Init_Kraken. Quit program...";
        QApplication::quit();
    }
    else{
        QTextStream stream(&file);
        qint64 pos = stream.pos();
        QString line[50];
        int linecount = 0;
        while(linecount < 49){
            line[linecount] = stream.readLine();
            linecount++;
        }
        line[3] = QString::number(upper);
        line[4] = QString::number(lower);
        stream.seek(pos);
        for(int i = 0; i<=linecount;i++){
            stream << line[i] << endl;
        }

        file.close();
    }
}

void MainWindow::WLAN_Button_Pressed(){
        WLAN_Dialog *dialog = new WLAN_Dialog(this);
        dialog->setModal(true);
        dialog->exec();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::readInitFile()
{
    QString inipath = QCoreApplication::applicationDirPath();
    inipath.append("/Init_Kraken");
    QFile file(inipath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Error loading Init_Kraken. Quit program...";
        QApplication::quit();
    }
    else{
        QTextStream stream(&file);
        QString line[50];
        int linecount = 0;
        while(linecount<49){
            line[linecount] = stream.readLine();
            linecount++;
        }
        file.close();
        this->path = line[1];
        this->upb = line[3].toDouble();
        this->lob = line[4].toDouble();
        this->ph7offset = line[6].toDouble();
        this->ph4offset = line[7].toDouble();
    }
}

template<typename T>
double MainWindow::adcToVolts(T &value)
{
    return value*3.3/1024;
}


template<typename T1>
T1 MainWindow::searchNearest(std::vector<T1> anArray, T1 key)
{
    T1 value = abs(key - anArray.at(0));
    T1 num = anArray.at(0);

    for (int i = 0; i < anArray.size(); ++i) {
        if(value > abs(key - anArray.at(i)))
        {
            value = abs(key - anArray.at(i));
            num = anArray.at(i);
        }
    }

    return num;
}

template<typename T1>
int* MainWindow::searchTwoNearest(std::vector<T1> anArray, T1 key)
{
    /* Fuelle die Variable mit dem ersten Wert */
    T1 value = abs(key - anArray.at(0));
    T1 num = anArray.at(0);
    int index = 0;

    for(int i=0; i<anArray.size(); i++)
    {
        if(value > abs(key - anArray.at(i)))
        {
            value = abs(key - anArray.at(i));
            num = anArray.at(i);
            index = i;
        }
    }

    /* Wenn der gefundene Wert größer ist, als der, der sich im Array befindet, dann befindet sich der reale Wert zwischen 
    dem Wert an der Stelle "index" und dem Wert an der Stelle "index -1" und umgekehrt */
    int index2 = -1;
    if(key < value)
    {
        index2 = index - 1;

    }
    
    else
    {
        index2 = index + 1;
    }

    static int rArray[2];
    if(anArray.at(index) > anArray.at(index2))
    {
        rArray[0] = index2;
        rArray[1] = index;
    
    }
    
    else
    {
        rArray[0] = index;
        rArray[1] = index2;
        
    }
    

    return rArray;
}

interpolation_inputs MainWindow::readTruebLookUpTable()
{
    
    const unsigned short int strlength = 50;
    /* Open File */
    QString inipath = QCoreApplication::applicationDirPath();
    inipath.append("/TruebLookUpTable.txt");
    QFile file("TruebLookUpTable.txt");
    qDebug() << "Path: " << inipath;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        interpolation_inputs tmp;
        tmp.x.push_back(-1);
        tmp.y.push_back(-1);
        return tmp;
    }
    
    /* Load whole Text File in array "line" */
    QTextStream stream(&file);
    qint64 pos = stream.pos();
    QString line[strlength];
    int linecount = 0;
    while(linecount < strlength){
        line[linecount] = stream.readLine();
        linecount++;
    }
    /* Close File Connection*/
    file.close();

    /* Find Data File Marker in File "#Truebung" */
    int trueb_line = -1;
    for(int i=0; i<strlength; i++){
        if(!QString::compare(line[i], "#TRUEBUNG", Qt::CaseInsensitive))
        {
            trueb_line = i;
        }
    }

    /* Read all lines until reaching the next '#' - marker in file */
    interpolation_inputs v;
    QStringList pieces;
    QString l;
    double x, y;
    trueb_line++;
    while(trueb_line <= strlength){
        if(line[trueb_line].contains("#"))
        {
            break;
        }
        pieces = line[trueb_line].split(";");
        x = pieces.value(pieces.length()-2).toDouble();
        y = pieces.value(pieces.length()-1).toDouble();
        
        v.x.push_back(x);
        v.y.push_back(y);
        trueb_line++;
    }

   return v;
 
}

interpolation_inputs MainWindow::readPHLookUpTable(){
    const unsigned short int strlength = 50;
    /*Open File*/
    QString inipath = QCoreApplication::applicationDirPath();
    inipath.append("/PhLookUpTable.txt");
    QFile file(inipath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        interpolation_inputs tmp;
        tmp.x.push_back(-1);
        tmp.y.push_back(-1);
        return tmp;
    }

    /*Load whole Text File in array "line"*/
    QTextStream stream(&file);
    qint64 pos = stream.pos();
    QString line[strlength];
    int linecount = 0;
    while(linecount < strlength){
        line[linecount] = stream.readLine();
        linecount++;
    }
    /*Close File Connection*/
    file.close();

    /*Find Data File Marker in File "#PH"*/
    int ph_line = -1;
    for(int i=0; i<strlength; i++)
    {
        if(!QString::compare(line[i], "#PH", Qt::CaseSensitive))
        {
            ph_line = i;
        }
    }
    /*Read all lines until reaching the nex '#' - marker in file*/
    interpolation_inputs v;
    QStringList pieces;
    QString l;
    double x, y;
    ph_line++;
    while(ph_line <= strlength){
        if(line[ph_line].contains("#"))
        {
            break;
        }
        pieces = line[ph_line].split(";");
        x = pieces.value(pieces.length()-2).toDouble();
        y = pieces.value(pieces.length()-1).toDouble();
        
        v.x.push_back(x);
        v.y.push_back(y);
        ph_line++;
    }

   return v;
}

int MainWindow::findNearestLowerNeighbourIndex(const double ac_dfValue, std::vector<double> x){
    double lv_dfDistance = DBL_MAX;
    int lv_nIndex = -1;

    for (unsigned int i = 0; i < x.size(); i++) { 
    double newDist = ac_dfValue - x[i]; 
    if (newDist >= 0 && newDist < lv_dfDistance) {
        lv_dfDistance = newDist;
        lv_nIndex = i;
        }
    }
    return lv_nIndex;
}

std::vector<double> MainWindow::interpolation(interpolation_inputs inputs, std::vector<double> xx){
    double dx, dy;
    std::vector<double> x, y;
    x = inputs.x;
    y = inputs.y;
    std::vector<double> slope, intercept, result;
    slope.resize(x.size());
    intercept.resize(x.size());
    result.resize(xx.size());
    int indiceEnVector;

    for (unsigned i = 0; i < x.size(); i++){
    if (i < x.size() - 1){
        dx = x[i + 1] - x[i];
        dy = y[i + 1] - y[i];
        slope[i] = dy / dx;
        intercept[i] = y[i] - x[i] * slope[i];
    }
    else{
        slope[i] = slope[i - 1];
        intercept[i] = intercept[i - 1];
    }
    }

    for (unsigned i = 0; i < xx.size(); i++) {
    indiceEnVector = findNearestLowerNeighbourIndex(xx[i], x);
    if (indiceEnVector != -1){
        result[i] = slope[indiceEnVector] * 
                    xx[i] + intercept[indiceEnVector];
        }
    else
        result[i] = DBL_MAX;
    }
    return result;
}
