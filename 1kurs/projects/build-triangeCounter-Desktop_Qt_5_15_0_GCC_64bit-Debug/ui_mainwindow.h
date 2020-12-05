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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *perimLabel;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *bxInput;
    QLineEdit *squareOut;
    QLineEdit *cxInput;
    QLineEdit *perimOut;
    QPushButton *clearButton;
    QLineEdit *axInput;
    QLabel *squareLabel;
    QLineEdit *ayInput;
    QPushButton *countButton;
    QLineEdit *cyInput;
    QLineEdit *byInput;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(405, 291);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        perimLabel = new QLabel(centralwidget);
        perimLabel->setObjectName(QString::fromUtf8("perimLabel"));
        perimLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(perimLabel, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        bxInput = new QLineEdit(centralwidget);
        bxInput->setObjectName(QString::fromUtf8("bxInput"));
        bxInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(bxInput, 1, 1, 1, 1);

        squareOut = new QLineEdit(centralwidget);
        squareOut->setObjectName(QString::fromUtf8("squareOut"));
        squareOut->setReadOnly(true);

        gridLayout->addWidget(squareOut, 5, 1, 1, 2);

        cxInput = new QLineEdit(centralwidget);
        cxInput->setObjectName(QString::fromUtf8("cxInput"));
        cxInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cxInput, 1, 2, 1, 1);

        perimOut = new QLineEdit(centralwidget);
        perimOut->setObjectName(QString::fromUtf8("perimOut"));
        perimOut->setReadOnly(true);

        gridLayout->addWidget(perimOut, 4, 1, 1, 2);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 3, 0, 1, 1);

        axInput = new QLineEdit(centralwidget);
        axInput->setObjectName(QString::fromUtf8("axInput"));
        axInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(axInput, 1, 0, 1, 1);

        squareLabel = new QLabel(centralwidget);
        squareLabel->setObjectName(QString::fromUtf8("squareLabel"));
        squareLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(squareLabel, 5, 0, 1, 1);

        ayInput = new QLineEdit(centralwidget);
        ayInput->setObjectName(QString::fromUtf8("ayInput"));
        ayInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ayInput, 2, 0, 1, 1);

        countButton = new QPushButton(centralwidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));

        gridLayout->addWidget(countButton, 3, 1, 1, 2);

        cyInput = new QLineEdit(centralwidget);
        cyInput->setObjectName(QString::fromUtf8("cyInput"));
        cyInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cyInput, 2, 2, 1, 1);

        byInput = new QLineEdit(centralwidget);
        byInput->setObjectName(QString::fromUtf8("byInput"));
        byInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(byInput, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 405, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "calculator Arsen", nullptr));
        perimLabel->setText(QCoreApplication::translate("MainWindow", "Perimeter", nullptr));
        bxInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Bx", nullptr));
        cxInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cx", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        axInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ax", nullptr));
        squareLabel->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        ayInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ay", nullptr));
        countButton->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        cyInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cy", nullptr));
        byInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "By", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
