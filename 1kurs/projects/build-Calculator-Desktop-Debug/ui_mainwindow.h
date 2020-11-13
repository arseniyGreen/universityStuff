/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *outLabel;
    QLabel *firstLabel;
    QLineEdit *outputLine;
    QPushButton *countButton;
    QPushButton *clearButton;
    QGroupBox *operationsBox;
    QRadioButton *plusButton;
    QRadioButton *expButton;
    QRadioButton *multiplyButton;
    QRadioButton *minusButton;
    QRadioButton *sqrtButton;
    QRadioButton *divideButton;
    QLabel *secondLabel;
    QLineEdit *secondInput;
    QLineEdit *firstInput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1088, 763);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        outLabel = new QLabel(centralwidget);
        outLabel->setObjectName(QString::fromUtf8("outLabel"));
        outLabel->setGeometry(QRect(230, 400, 101, 41));
        firstLabel = new QLabel(centralwidget);
        firstLabel->setObjectName(QString::fromUtf8("firstLabel"));
        firstLabel->setGeometry(QRect(11, 88, 221, 24));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        firstLabel->setFont(font);
        outputLine = new QLineEdit(centralwidget);
        outputLine->setObjectName(QString::fromUtf8("outputLine"));
        outputLine->setGeometry(QRect(360, 400, 241, 51));
        outputLine->setReadOnly(true);
        countButton = new QPushButton(centralwidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));
        countButton->setGeometry(QRect(340, 290, 261, 61));
        countButton->setMinimumSize(QSize(205, 0));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(430, 360, 93, 28));
        operationsBox = new QGroupBox(centralwidget);
        operationsBox->setObjectName(QString::fromUtf8("operationsBox"));
        operationsBox->setGeometry(QRect(340, 80, 261, 211));
        plusButton = new QRadioButton(operationsBox);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(12, 62, 35, 20));
        plusButton->setChecked(true);
        expButton = new QRadioButton(operationsBox);
        expButton->setObjectName(QString::fromUtf8("expButton"));
        expButton->setGeometry(QRect(93, 62, 110, 20));
        multiplyButton = new QRadioButton(operationsBox);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));
        multiplyButton->setGeometry(QRect(12, 123, 35, 20));
        minusButton = new QRadioButton(operationsBox);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(54, 62, 32, 20));
        sqrtButton = new QRadioButton(operationsBox);
        sqrtButton->setObjectName(QString::fromUtf8("sqrtButton"));
        sqrtButton->setGeometry(QRect(93, 123, 47, 20));
        divideButton = new QRadioButton(operationsBox);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));
        divideButton->setGeometry(QRect(54, 123, 32, 20));
        secondLabel = new QLabel(centralwidget);
        secondLabel->setObjectName(QString::fromUtf8("secondLabel"));
        secondLabel->setGeometry(QRect(690, 90, 261, 24));
        secondLabel->setFont(font);
        secondInput = new QLineEdit(centralwidget);
        secondInput->setObjectName(QString::fromUtf8("secondInput"));
        secondInput->setGeometry(QRect(680, 160, 241, 51));
        firstInput = new QLineEdit(centralwidget);
        firstInput->setObjectName(QString::fromUtf8("firstInput"));
        firstInput->setGeometry(QRect(0, 150, 240, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1088, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", nullptr));
        outLabel->setText(QApplication::translate("MainWindow", "Sum", nullptr));
        firstLabel->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264 1", nullptr));
        countButton->setText(QApplication::translate("MainWindow", "=", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        operationsBox->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        plusButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        expButton->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\320\277\320\265\320\275\321\214", nullptr));
        multiplyButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        minusButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        sqrtButton->setText(QApplication::translate("MainWindow", "sqrt", nullptr));
        divideButton->setText(QApplication::translate("MainWindow", "/", nullptr));
        secondLabel->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264 2", nullptr));
#ifndef QT_NO_WHATSTHIS
        firstInput->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
