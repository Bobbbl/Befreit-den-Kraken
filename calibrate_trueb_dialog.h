#ifndef CALIBRATE_TRUEB_DIALOG_H
#define CALIBRATE_TRUEB_DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class calibrate_trueb_dialog;
}

class calibrate_trueb_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit calibrate_trueb_dialog(QWidget *parent = 0);
    ~calibrate_trueb_dialog();
    double lob;
    double upb;
    double uvolt;
    double dvolt;
    bool upflag = false;
    bool downflag = false;

private:
    Ui::calibrate_trueb_dialog *ui;

public slots:
    void setUpperBoundary(int value);
    void setLowerBoundary(int value);
    void pushButtonHighPressed();
    void pushButtonLowPressed();

};

#endif // CALIBRATE_TRUEB_DIALOG_H
