#ifndef CALIBRATE_PH_DIALOG_H
#define CALIBRATE_PH_DIALOG_H

#include <QDialog>
#include <QPalette>
#include <QColor>
#include "mainwindow.h"

namespace Ui {
class Calibrate_PH_dialog;
}

class Calibrate_PH_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Calibrate_PH_dialog(QWidget *parent = 0);
    ~Calibrate_PH_dialog();
    double ph7Offset;
    double ph4Offset;

private:
    Ui::Calibrate_PH_dialog *ui;

public slots:
    void setTextPH7(int value);
    void setTextPH4(int value);
    void pH7Pressed();
    void pH4Pressed();

signals:
    void ph7Changed(double value);
    void ph4Changed(double value);
};

#endif // CALIBRATE_PH_DIALOG_H
