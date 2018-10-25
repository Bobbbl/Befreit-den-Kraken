#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <qtimer.h>
#include "mcp3008Spi.h"
#include <vector>
#include <queue>
#include <sensorscanner.h>
#include "calibrate_ph_dialog.h"
#include <map>
#include <QFile>
#include <QTextStream>
#include "uhr.h"
#include "calibrate_trueb_dialog.h"
#include <QFileDialog>
#include <QDate>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    SensorScanner *ph_sensor, *trueb_sensor;

    template <typename T1>
    T1 searchNearest(std::vector<T1>, T1 key);
    template <typename T1>
    int* searchTwoNearest(std::vector<T1>, T1 key);

    ~MainWindow();
	
	void readInitFile();

public slots:
	void saveAndCheck(QString path, QString inhalt);
	void saverSlot();
    void WLAN_Button_Pressed();
    void readPHSensor(int);
    void readTruebSensor(int);
    void readTempSensor(int value);
    void CalibratePH_Pressed();
    void pushButtonTruebPressed();
    void uhrPressed();
	void refreshPath(QString path);
	double readTemp();

private:
	double phValue;
	double truebValue;
	double tempValue;
    double upb = 2.5;
    double lob = 0;
    Ui::MainWindow *ui;
	QString path;
    QString backupPath;
	QString IniFile;
    QTimer *timer;
	QTimer *TempSensor;
    double ph4offset, ph7offset;
    std::vector<int> ph_direct_values, trueb_direct_values,temp_direct_values;
    double avarageValues(std::vector<int>* array);
    template <typename T>
    double adcToVolts(T &value);
	bool writingerrorflag = false;
    void savePHInit(double ph7offset, double ph4offset);
    void saveTruebInit(double upper, double lower);
    
    void readLookUpTable();
    void readPHLookUpTable();

};

#endif // MAINWINDOW_H
