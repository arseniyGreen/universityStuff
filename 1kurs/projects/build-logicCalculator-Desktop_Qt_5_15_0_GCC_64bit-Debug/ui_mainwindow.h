/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QComboBox *secondOperand;
    QLineEdit *outputLine;
    QLabel *firstLabel;
    QLabel *secondLabel;
    QComboBox *operationBox;
    QLabel *operationLabel;
    QComboBox *firstOperand;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(348, 204);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        secondOperand = new QComboBox(centralwidget);
        secondOperand->addItem(QString());
        secondOperand->addItem(QString());
        secondOperand->setObjectName(QString::fromUtf8("secondOperand"));

        gridLayout->addWidget(secondOperand, 1, 2, 1, 1);

        outputLine = new QLineEdit(centralwidget);
        outputLine->setObjectName(QString::fromUtf8("outputLine"));
        outputLine->setAlignment(Qt::AlignCenter);
        outputLine->setReadOnly(true);

        gridLayout->addWidget(outputLine, 2, 0, 1, 3);

        firstLabel = new QLabel(centralwidget);
        firstLabel->setObjectName(QString::fromUtf8("firstLabel"));
        QFont font;
        font.setPointSize(24);
        firstLabel->setFont(font);
        firstLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(firstLabel, 0, 0, 1, 1);

        secondLabel = new QLabel(centralwidget);
        secondLabel->setObjectName(QString::fromUtf8("secondLabel"));
        secondLabel->setFont(font);
        secondLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(secondLabel, 0, 2, 1, 1);

        operationBox = new QComboBox(centralwidget);
        operationBox->addItem(QString());
        operationBox->addItem(QString());
        operationBox->addItem(QString());
        operationBox->addItem(QString());
        operationBox->addItem(QString());
        operationBox->addItem(QString());
        operationBox->setObjectName(QString::fromUtf8("operationBox"));

        gridLayout->addWidget(operationBox, 1, 1, 1, 1);

        operationLabel = new QLabel(centralwidget);
        operationLabel->setObjectName(QString::fromUtf8("operationLabel"));
        operationLabel->setFont(font);
        operationLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(operationLabel, 0, 1, 1, 1);

        firstOperand = new QComboBox(centralwidget);
        firstOperand->addItem(QString());
        firstOperand->addItem(QString());
        firstOperand->setObjectName(QString::fromUtf8("firstOperand"));

        gridLayout->addWidget(firstOperand, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 348, 20));
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
        secondOperand->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        secondOperand->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));

        firstLabel->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        secondLabel->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        operationBox->setItemText(0, QCoreApplication::translate("MainWindow", "AND", nullptr));
        operationBox->setItemText(1, QCoreApplication::translate("MainWindow", "OR", nullptr));
        operationBox->setItemText(2, QCoreApplication::translate("MainWindow", "INVERSION", nullptr));
        operationBox->setItemText(3, QCoreApplication::translate("MainWindow", "IMPLICATION", nullptr));
        operationBox->setItemText(4, QCoreApplication::translate("MainWindow", "EQUIVALENCE", nullptr));
        operationBox->setItemText(5, QCoreApplication::translate("MainWindow", "EXCLUDING OR", nullptr));

        operationLabel->setText(QCoreApplication::translate("MainWindow", "Operation", nullptr));
        firstOperand->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        firstOperand->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
