/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *operandLeftInput;
    QLabel *operandLeftLabel;
    QLabel *operandRightLabel;
    QLineEdit *operandRightInput;
    QGroupBox *actionsBox;
    QRadioButton *divButton;
    QRadioButton *sumButton;
    QRadioButton *difButton;
    QRadioButton *multButton;
    QPushButton *countButton;
    QTextEdit *resultOutput;
    QLabel *resaultLabel;
    QLabel *errorLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(419, 330);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        operandLeftInput = new QLineEdit(centralWidget);
        operandLeftInput->setObjectName(QString::fromUtf8("operandLeftInput"));
        operandLeftInput->setGeometry(QRect(20, 70, 113, 20));
        operandLeftLabel = new QLabel(centralWidget);
        operandLeftLabel->setObjectName(QString::fromUtf8("operandLeftLabel"));
        operandLeftLabel->setGeometry(QRect(50, 50, 71, 16));
        operandRightLabel = new QLabel(centralWidget);
        operandRightLabel->setObjectName(QString::fromUtf8("operandRightLabel"));
        operandRightLabel->setGeometry(QRect(310, 50, 71, 16));
        operandRightInput = new QLineEdit(centralWidget);
        operandRightInput->setObjectName(QString::fromUtf8("operandRightInput"));
        operandRightInput->setGeometry(QRect(280, 70, 113, 20));
        actionsBox = new QGroupBox(centralWidget);
        actionsBox->setObjectName(QString::fromUtf8("actionsBox"));
        actionsBox->setGeometry(QRect(150, 40, 120, 101));
        divButton = new QRadioButton(actionsBox);
        divButton->setObjectName(QString::fromUtf8("divButton"));
        divButton->setGeometry(QRect(10, 70, 82, 17));
        sumButton = new QRadioButton(actionsBox);
        sumButton->setObjectName(QString::fromUtf8("sumButton"));
        sumButton->setGeometry(QRect(10, 10, 82, 17));
        difButton = new QRadioButton(actionsBox);
        difButton->setObjectName(QString::fromUtf8("difButton"));
        difButton->setGeometry(QRect(10, 30, 82, 17));
        multButton = new QRadioButton(actionsBox);
        multButton->setObjectName(QString::fromUtf8("multButton"));
        multButton->setGeometry(QRect(10, 50, 82, 17));
        countButton = new QPushButton(centralWidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));
        countButton->setGeometry(QRect(150, 140, 121, 23));
        resultOutput = new QTextEdit(centralWidget);
        resultOutput->setObjectName(QString::fromUtf8("resultOutput"));
        resultOutput->setGeometry(QRect(130, 170, 181, 31));
        resultOutput->setReadOnly(true);
        resaultLabel = new QLabel(centralWidget);
        resaultLabel->setObjectName(QString::fromUtf8("resaultLabel"));
        resaultLabel->setGeometry(QRect(30, 180, 91, 21));
        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(0, 250, 441, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 419, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        operandLeftLabel->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264 1", nullptr));
        operandRightLabel->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264 2", nullptr));
        actionsBox->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        divButton->setText(QApplication::translate("MainWindow", "/", nullptr));
        sumButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        difButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        multButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        countButton->setText(QApplication::translate("MainWindow", "=", nullptr));
        resaultLabel->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
