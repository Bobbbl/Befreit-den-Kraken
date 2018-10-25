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
#include <cfloat>
#include <cmath>

typedef struct {
    std::vector<double> x;
    std::vector<double> y;
}interpolation_inputs;

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
    /*@Inputs
     anArray: An vector with the values to search in
     key: The value to search for (find nearest two possible values)
     @Output
     pointer to int Array with 2 values of the indexes of the values from Arrray.
     The value in index 0 is the index of the lower found value.
     The value in index 1 is the index of the higher found value.*/
    template <typename T1>
    int* searchTwoNearest(std::vector<T1> anArray, T1 key);

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
    interpolation_inputs readPHLookUpTable();
    interpolation_inputs readTruebLookUpTable();


    int findNearestLowerNeighbourIndex(const double value, std::vector<double> array);
    std::vector<double> interpolation(interpolation_inputs inputs, std::vector<double> xx);

};

#endif // MAINWINDOW_H
