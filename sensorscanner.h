#ifndef SENSORSCANNER_H
#define SENSORSCANNER_H

#include <stdio.h>
#include <QDebug>
#include <QString>
#include <QWidget>
#include <QThread>
#include "mcp3008Spi.h"




enum read_channel{
    Temperatursensor = 1,
    Truebungssensor = 5,
    PH_Sensor = 3
};

typedef enum read_channel Channel;

class SensorScanner : public QThread
{
    Q_OBJECT
public:
    SensorScanner(QWidget *parent, Channel);
    std::map <double, double> phmap;
private:
    Channel _channel;
    void run();
public slots:


signals:
    void newValueSignal(int value);

};

#endif // SENSORSCANNER_H
