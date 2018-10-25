#include "sensorscanner.h"



SensorScanner::SensorScanner(QWidget *parent, Channel channel):
    QThread(parent),
    _channel(channel)
{
    phmap[414.12] = 0.00;
    phmap[354.96] = 1.00;
    phmap[295.80] = 2.00;
    phmap[236.64] = 3.00;
    phmap[177.48] = 4.00 ;
    phmap[118.32] = 5.00;
    phmap[59.16] = 6.00;
    phmap[0.00] = 7.00;
    phmap[-59.16] = 8.00 ;
    phmap[-118.32] = 9.00;
    phmap[-177.48] = 10.00;
    phmap[-236.64] = 11.00;
    phmap[-295.80] = 12.00;
    phmap[-354.96] =  13.00;
    phmap[-414.12] = 14.00;
}

void SensorScanner::run()
{
    while(true){
    emit this->newValueSignal(readADC(_channel));
    msleep(200);
    }
}


