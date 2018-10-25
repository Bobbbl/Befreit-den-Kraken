/********************************************************************************
** Form generated from reading UI file 'calibrate_ph_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATE_PH_DIALOG_H
#define UI_CALIBRATE_PH_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Calibrate_PH_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelPH7;
    QPushButton *pushButtonPH7;
    QPushButton *pushButtonPH4;

    void setupUi(QDialog *Calibrate_PH_dialog)
    {
        if (Calibrate_PH_dialog->objectName().isEmpty())
            Calibrate_PH_dialog->setObjectName(QString::fromUtf8("Calibrate_PH_dialog"));
        Calibrate_PH_dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(Calibrate_PH_dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelPH7 = new QLabel(Calibrate_PH_dialog);
        labelPH7->setObjectName(QString::fromUtf8("labelPH7"));

        verticalLayout->addWidget(labelPH7);

        pushButtonPH7 = new QPushButton(Calibrate_PH_dialog);
        pushButtonPH7->setObjectName(QString::fromUtf8("pushButtonPH7"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonPH7->sizePolicy().hasHeightForWidth());
        pushButtonPH7->setSizePolicy(sizePolicy);
        pushButtonPH7->setFlat(true);

        verticalLayout->addWidget(pushButtonPH7);

        pushButtonPH4 = new QPushButton(Calibrate_PH_dialog);
        pushButtonPH4->setObjectName(QString::fromUtf8("pushButtonPH4"));
        sizePolicy.setHeightForWidth(pushButtonPH4->sizePolicy().hasHeightForWidth());
        pushButtonPH4->setSizePolicy(sizePolicy);
        pushButtonPH4->setFlat(false);

        verticalLayout->addWidget(pushButtonPH4);


        retranslateUi(Calibrate_PH_dialog);

        QMetaObject::connectSlotsByName(Calibrate_PH_dialog);
    } // setupUi

    void retranslateUi(QDialog *Calibrate_PH_dialog)
    {
        Calibrate_PH_dialog->setWindowTitle(QApplication::translate("Calibrate_PH_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        labelPH7->setText(QApplication::translate("Calibrate_PH_dialog", "PH 7", 0, QApplication::UnicodeUTF8));
        pushButtonPH7->setText(QApplication::translate("Calibrate_PH_dialog", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButtonPH4->setText(QApplication::translate("Calibrate_PH_dialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calibrate_PH_dialog: public Ui_Calibrate_PH_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATE_PH_DIALOG_H
