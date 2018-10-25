#include "calibrate_ph_dialog.h"
#include "ui_calibrate_ph_dialog.h"

Calibrate_PH_dialog::Calibrate_PH_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calibrate_PH_dialog)
{
    ui->setupUi(this);

    /*Delete PushButton Text*/
    ui->pushButtonPH4->setText("OK");
    ui->pushButtonPH7->setText("");

    connect(((MainWindow*)parent)->ph_sensor, SIGNAL(newValueSignal(int)), this, SLOT(setTextPH7(int)));
//    connect(((MainWindow*)parent)->ph_sensor, SIGNAL(newValueSignal(int)), this, SLOT(setTextPH4(int)));
    connect(ui->pushButtonPH7, SIGNAL(pressed()), this, SLOT(pH7Pressed()));
    connect(ui->pushButtonPH4, SIGNAL(pressed()), this, SLOT(close()));


}

Calibrate_PH_dialog::~Calibrate_PH_dialog()
{
    delete ui;
}

void Calibrate_PH_dialog::setTextPH7(int value)
{

    double volt = value*3.3/1024;
    double ph = volt*3.5;
    ui->pushButtonPH7->setText(QString::number(ph));
    this->ph7Offset = 7-ph;
}

void Calibrate_PH_dialog::setTextPH4(int value)
{

    double volt = value*3.3/1024;
    this->ph4Offset = volt*3.5;
    ui->pushButtonPH4->setText(QString::number(this->ph4Offset));
}

void Calibrate_PH_dialog::pH7Pressed()
{
    ui->pushButtonPH7->setStyleSheet("border: 1px; border-radius: 6px;background-color: green");
    emit ph7Changed(this->ph7Offset);
}

void Calibrate_PH_dialog::pH4Pressed()
{
    ui->pushButtonPH4->setStyleSheet("border: 1px; border-radius: 6px;background-color: green");
    emit ph4Changed(this->ph4Offset);

}
