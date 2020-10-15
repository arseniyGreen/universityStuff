/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *secondInput;
    QLineEdit *firstInput;
    QLineEdit *outputLine;
    QLabel *secondLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *plusButton;
    QRadioButton *multiplyButton;
    QRadioButton *divideButton;
    QRadioButton *minusButton;
    QLabel *firstLabel;
    QPushButton *countButton;
    QLabel *outLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(244, 387);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        secondInput = new QLineEdit(centralwidget);
        secondInput->setObjectName(QString::fromUtf8("secondInput"));

        gridLayout->addWidget(secondInput, 3, 0, 1, 1);

        firstInput = new QLineEdit(centralwidget);
        firstInput->setObjectName(QString::fromUtf8("firstInput"));

        gridLayout->addWidget(firstInput, 1, 0, 1, 1);

        outputLine = new QLineEdit(centralwidget);
        outputLine->setObjectName(QString::fromUtf8("outputLine"));
        outputLine->setReadOnly(true);

        gridLayout->addWidget(outputLine, 7, 0, 1, 1);

        secondLabel = new QLabel(centralwidget);
        secondLabel->setObjectName(QString::fromUtf8("secondLabel"));

        gridLayout->addWidget(secondLabel, 2, 0, 1, 1, Qt::AlignHCenter);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plusButton = new QRadioButton(groupBox);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setChecked(true);

        gridLayout_2->addWidget(plusButton, 0, 0, 1, 1);

        multiplyButton = new QRadioButton(groupBox);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));

        gridLayout_2->addWidget(multiplyButton, 1, 0, 1, 1);

        divideButton = new QRadioButton(groupBox);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));

        gridLayout_2->addWidget(divideButton, 1, 1, 1, 1);

        minusButton = new QRadioButton(groupBox);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));

        gridLayout_2->addWidget(minusButton, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 4, 0, 1, 1);

        firstLabel = new QLabel(centralwidget);
        firstLabel->setObjectName(QString::fromUtf8("firstLabel"));

        gridLayout->addWidget(firstLabel, 0, 0, 1, 1, Qt::AlignHCenter);

        countButton = new QPushButton(centralwidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));

        gridLayout->addWidget(countButton, 5, 0, 1, 1);

        outLabel = new QLabel(centralwidget);
        outLabel->setObjectName(QString::fromUtf8("outLabel"));

        gridLayout->addWidget(outLabel, 6, 0, 1, 1, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 244, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        secondLabel->setText(QCoreApplication::translate("MainWindow", "Second Summand", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Operands", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divideButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        firstLabel->setText(QCoreApplication::translate("MainWindow", "First Summand", nullptr));
        countButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        outLabel->setText(QCoreApplication::translate("MainWindow", "Sum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
