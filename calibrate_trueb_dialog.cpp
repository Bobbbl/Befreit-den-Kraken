#include "calibrate_trueb_dialog.h"
#include "ui_calibrate_trueb_dialog.h"

calibrate_trueb_dialog::calibrate_trueb_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calibrate_trueb_dialog)
{
    ui->setupUi(this);

    /*Initialise PushButton Text*/
    ui->pushButtonHigh->setText("");
    ui->pushButtonLow->setText("");
    ui->pushButtonOK->setText("OK");

    /*Connect Slots&Signals*/
    connect(((MainWindow*)parent)->trueb_sensor, SIGNAL(newValueSignal(int)), this, SLOT(setUpperBoundary(int)));
    connect(((MainWindow*)parent)->trueb_sensor, SIGNAL(newValueSignal(int)), this, SLOT(setLowerBoundary(int)));
    connect(ui->pushButtonOK, SIGNAL(pressed()), this, SLOT(close()));
    connect(ui->pushButtonHigh, SIGNAL(pressed()), this, SLOT(pushButtonHighPressed()));
	connect(ui->pushButtonLow, SIGNAL(pressed()), this, SLOT(pushButtonLowPressed()));
}

calibrate_trueb_dialog::~calibrate_trueb_dialog()
{
    delete ui;
}

void calibrate_trueb_dialog::setUpperBoundary(int value)
{
    double volt = value*3.3/1024;
    ui->pushButtonHigh->setText(QString::number(volt));
    this->uvolt = volt;

}

void calibrate_trueb_dialog::setLowerBoundary(int value)
{
    double volt = value*3.3/1024;
    ui->pushButtonLow->setText(QString::number(volt));
    this->dvolt = volt;
}

void calibrate_trueb_dialog::pushButtonHighPressed()
{
    this->upb = this->uvolt;
    this->upflag = true;
    ui->pushButtonHigh->setStyleSheet("border: 1px; border-radius: 6px;background-color: green");
}

void calibrate_trueb_dialog::pushButtonLowPressed()
{
    this->lob = this->dvolt;
    this->downflag = true;
    ui->pushButtonLow->setStyleSheet("border: 1px; border-radius: 6px;background-color: green");
}


