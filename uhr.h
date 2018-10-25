#ifndef UHR_H
#define UHR_H

#include <QWidget>
#include <QLCDNumber>
#include <QObject>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include <QMouseEvent>
#include <QFileDialog>
#include <QString>

class Uhr : public QLCDNumber
{
    Q_OBJECT

public:
    Uhr(QWidget *parent = 0);
    QString selectedFolderPath;
protected:
    void mousePressEvent(QMouseEvent *event);


private slots:
    void showTime();

signals:
    void pathReadySignal(QString path);

};

#endif // UHR_H
