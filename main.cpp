#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "mcp3008Spi.h"
#include "database.h"


int testSPI();


int main(int argc, char *argv[])
{
    //testDatabase();
    // logKrake("/home/pi/Befreit_den_Kraken/krakelog.db", "krake", 1,2123123123,31234567);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    //return 1;
}

int testSPI(){
    mcp3008Spi a2d("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);
    int i = 20;
    int a2dVal = 0;
    int a2dChannel = 0;
    unsigned char data[3];

    while(i>0){
        data[0] = 1;
        data[1] = 0b10000000|(((a2dChannel&7)<<4));
        data[2] = 0;
        a2d.spiWriteRead(data, sizeof(data));

        a2dVal = 0;
        a2dVal = (data[1]<< 8) & 0b1100000000;
        a2dVal |=  (data[2] & 0xff);
        sleep(1);
        qDebug() << "Result: " << a2dVal << endl;
        i--;
    }
    return 0;
}
