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
#include <QtWidgets/QHBoxLayout>
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
    QLineEdit *firstInput;
    QLabel *firstLabel;
    QGroupBox *operationsBox;
    QGridLayout *gridLayout_2;
    QRadioButton *plusButton;
    QRadioButton *expButton;
    QRadioButton *multiplyButton;
    QRadioButton *logButton;
    QRadioButton *minusButton;
    QRadioButton *divideButton;
    QLabel *outLabel;
    QLineEdit *outputLine;
    QLabel *secondLabel;
    QLineEdit *secondInput;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *countButton;
    QPushButton *clearButton;
    QLineEdit *numberingBaseInput;
    QLabel *numberingLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(371, 413);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        firstInput = new QLineEdit(centralwidget);
        firstInput->setObjectName(QString::fromUtf8("firstInput"));
        firstInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(firstInput, 2, 1, 1, 1);

        firstLabel = new QLabel(centralwidget);
        firstLabel->setObjectName(QString::fromUtf8("firstLabel"));
        firstLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(firstLabel, 1, 1, 1, 1, Qt::AlignHCenter);

        operationsBox = new QGroupBox(centralwidget);
        operationsBox->setObjectName(QString::fromUtf8("operationsBox"));
        gridLayout_2 = new QGridLayout(operationsBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plusButton = new QRadioButton(operationsBox);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setChecked(true);

        gridLayout_2->addWidget(plusButton, 0, 0, 1, 1);

        expButton = new QRadioButton(operationsBox);
        expButton->setObjectName(QString::fromUtf8("expButton"));

        gridLayout_2->addWidget(expButton, 0, 2, 1, 1);

        multiplyButton = new QRadioButton(operationsBox);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));

        gridLayout_2->addWidget(multiplyButton, 1, 0, 1, 1);

        logButton = new QRadioButton(operationsBox);
        logButton->setObjectName(QString::fromUtf8("logButton"));

        gridLayout_2->addWidget(logButton, 1, 2, 1, 1);

        minusButton = new QRadioButton(operationsBox);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));

        gridLayout_2->addWidget(minusButton, 0, 1, 1, 1);

        divideButton = new QRadioButton(operationsBox);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));

        gridLayout_2->addWidget(divideButton, 1, 1, 1, 1);


        gridLayout->addWidget(operationsBox, 5, 1, 1, 2);

        outLabel = new QLabel(centralwidget);
        outLabel->setObjectName(QString::fromUtf8("outLabel"));
        outLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(outLabel, 8, 1, 1, 2);

        outputLine = new QLineEdit(centralwidget);
        outputLine->setObjectName(QString::fromUtf8("outputLine"));
        outputLine->setAlignment(Qt::AlignCenter);
        outputLine->setReadOnly(true);

        gridLayout->addWidget(outputLine, 9, 1, 1, 2);

        secondLabel = new QLabel(centralwidget);
        secondLabel->setObjectName(QString::fromUtf8("secondLabel"));
        secondLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(secondLabel, 1, 2, 1, 1);

        secondInput = new QLineEdit(centralwidget);
        secondInput->setObjectName(QString::fromUtf8("secondInput"));
        secondInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(secondInput, 2, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        countButton = new QPushButton(centralwidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));
        countButton->setMinimumSize(QSize(205, 0));

        horizontalLayout_3->addWidget(countButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_3->addWidget(clearButton);


        gridLayout->addLayout(horizontalLayout_3, 6, 1, 1, 2);

        numberingBaseInput = new QLineEdit(centralwidget);
        numberingBaseInput->setObjectName(QString::fromUtf8("numberingBaseInput"));
        numberingBaseInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(numberingBaseInput, 0, 2, 1, 1);

        numberingLabel = new QLabel(centralwidget);
        numberingLabel->setObjectName(QString::fromUtf8("numberingLabel"));
        numberingLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(numberingLabel, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 371, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
#if QT_CONFIG(whatsthis)
        firstInput->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        firstLabel->setText(QCoreApplication::translate("MainWindow", "First Summand", nullptr));
        operationsBox->setTitle(QCoreApplication::translate("MainWindow", "Operands", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        expButton->setText(QCoreApplication::translate("MainWindow", "Exponentiation", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        logButton->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        divideButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        outLabel->setText(QCoreApplication::translate("MainWindow", "Sum", nullptr));
        secondLabel->setText(QCoreApplication::translate("MainWindow", "Second Summand", nullptr));
        countButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        numberingBaseInput->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        numberingBaseInput->setPlaceholderText(QString());
        numberingLabel->setText(QCoreApplication::translate("MainWindow", "Numbering Base", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
