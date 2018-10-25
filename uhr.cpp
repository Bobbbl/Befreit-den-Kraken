#include "uhr.h"

Uhr::Uhr(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();


}

void Uhr::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // handle left mouse button here
        QFileDialog dialog;
        dialog.setFileMode(QFileDialog::Directory);
        dialog.setOption(QFileDialog::ShowDirsOnly);
        dialog.setModal(true);

        QString path = dialog.getExistingDirectory(this);
        emit pathReadySignal(path);
    } else {
        // pass on other buttons to base class
        QLCDNumber::mousePressEvent(event);
    }
}

void Uhr::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if((time.second() % 2) == 0){
        text[2] = ' ';
        display(text);
    }
}
