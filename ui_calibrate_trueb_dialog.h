/********************************************************************************
** Form generated from reading UI file 'calibrate_trueb_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATE_TRUEB_DIALOG_H
#define UI_CALIBRATE_TRUEB_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_calibrate_trueb_dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonHigh;
    QPushButton *pushButtonLow;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *calibrate_trueb_dialog)
    {
        if (calibrate_trueb_dialog->objectName().isEmpty())
            calibrate_trueb_dialog->setObjectName(QString::fromUtf8("calibrate_trueb_dialog"));
        calibrate_trueb_dialog->resize(400, 300);
        horizontalLayout = new QHBoxLayout(calibrate_trueb_dialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButtonHigh = new QPushButton(calibrate_trueb_dialog);
        pushButtonHigh->setObjectName(QString::fromUtf8("pushButtonHigh"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonHigh->sizePolicy().hasHeightForWidth());
        pushButtonHigh->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButtonHigh);

        pushButtonLow = new QPushButton(calibrate_trueb_dialog);
        pushButtonLow->setObjectName(QString::fromUtf8("pushButtonLow"));
        sizePolicy.setHeightForWidth(pushButtonLow->sizePolicy().hasHeightForWidth());
        pushButtonLow->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButtonLow);


        horizontalLayout->addLayout(verticalLayout);

        pushButtonOK = new QPushButton(calibrate_trueb_dialog);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        sizePolicy.setHeightForWidth(pushButtonOK->sizePolicy().hasHeightForWidth());
        pushButtonOK->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonOK);


        retranslateUi(calibrate_trueb_dialog);

        QMetaObject::connectSlotsByName(calibrate_trueb_dialog);
    } // setupUi

    void retranslateUi(QDialog *calibrate_trueb_dialog)
    {
        calibrate_trueb_dialog->setWindowTitle(QApplication::translate("calibrate_trueb_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButtonHigh->setText(QApplication::translate("calibrate_trueb_dialog", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButtonLow->setText(QApplication::translate("calibrate_trueb_dialog", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("calibrate_trueb_dialog", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calibrate_trueb_dialog: public Ui_calibrate_trueb_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATE_TRUEB_DIALOG_H
