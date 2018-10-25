/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonCalibratePH;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonTrueb;
    QLabel *label_2;
    QPushButton *pushButtonWLAN;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonPH;
    QLabel *label_3;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_6;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QPushButton *pushButtonTemp;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(246, 157);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonCalibratePH = new QPushButton(centralWidget);
        pushButtonCalibratePH->setObjectName(QString::fromUtf8("pushButtonCalibratePH"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonCalibratePH->sizePolicy().hasHeightForWidth());
        pushButtonCalibratePH->setSizePolicy(sizePolicy);
        pushButtonCalibratePH->setFlat(false);

        gridLayout->addWidget(pushButtonCalibratePH, 0, 1, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButtonTrueb = new QPushButton(frame);
        pushButtonTrueb->setObjectName(QString::fromUtf8("pushButtonTrueb"));
        sizePolicy.setHeightForWidth(pushButtonTrueb->sizePolicy().hasHeightForWidth());
        pushButtonTrueb->setSizePolicy(sizePolicy);
        pushButtonTrueb->setFlat(true);

        gridLayout_2->addWidget(pushButtonTrueb, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        pushButtonWLAN = new QPushButton(centralWidget);
        pushButtonWLAN->setObjectName(QString::fromUtf8("pushButtonWLAN"));
        sizePolicy.setHeightForWidth(pushButtonWLAN->sizePolicy().hasHeightForWidth());
        pushButtonWLAN->setSizePolicy(sizePolicy);
        pushButtonWLAN->setFlat(false);

        gridLayout->addWidget(pushButtonWLAN, 0, 0, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButtonPH = new QPushButton(frame_2);
        pushButtonPH->setObjectName(QString::fromUtf8("pushButtonPH"));
        sizePolicy.setHeightForWidth(pushButtonPH->sizePolicy().hasHeightForWidth());
        pushButtonPH->setSizePolicy(sizePolicy);
        pushButtonPH->setFlat(true);

        gridLayout_3->addWidget(pushButtonPH, 1, 0, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);


        gridLayout->addWidget(frame_2, 2, 0, 1, 1);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));

        gridLayout_4->addLayout(gridLayout_6, 0, 0, 1, 1);


        gridLayout->addWidget(frame_3, 2, 1, 1, 1);

        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButtonTemp = new QPushButton(frame_4);
        pushButtonTemp->setObjectName(QString::fromUtf8("pushButtonTemp"));
        sizePolicy.setHeightForWidth(pushButtonTemp->sizePolicy().hasHeightForWidth());
        pushButtonTemp->setSizePolicy(sizePolicy);
        pushButtonTemp->setFlat(true);

        gridLayout_5->addWidget(pushButtonTemp, 1, 0, 1, 1);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(frame_4, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButtonCalibratePH->setText(QApplication::translate("MainWindow", "PH", 0, QApplication::UnicodeUTF8));
        pushButtonTrueb->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Tr\303\274b", 0, QApplication::UnicodeUTF8));
        pushButtonWLAN->setText(QApplication::translate("MainWindow", "WLAN", 0, QApplication::UnicodeUTF8));
        pushButtonPH->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "PH", 0, QApplication::UnicodeUTF8));
        pushButtonTemp->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Temp.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
