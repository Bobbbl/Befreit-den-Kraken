#ifndef WLAN_DIALOG_H
#define WLAN_DIALOG_H

#include <QWidget>
#include <QDialog>
#include "ui_wlan_dialog.h"
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QDebug>
#include <QList>
#include <iostream>
#include <iwlib.h>
#include <stdio.h>
#include <time.h>
#include <QList>



namespace Ui {
class WLAN_Dialog;
}

class WLAN_Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit WLAN_Dialog(QWidget *parent = 0);
private:
    Ui::Dialog *ui;
    void scanSSIDs();
    int connectNetwork(QString*, QString*);

    QList<QString> SSIDList;
    QString currentSSID, pwd;

signals:

public slots:
    void SSIDChanged(int );
    void connectButtonPressed();
    void setupButtonPressed();
};

#endif // WLAN_DIALOG_H
