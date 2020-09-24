/********************************************************************************
** Form generated from reading UI file 'calcwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCWIDGET_H
#define UI_CALCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calcWidget
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *romanLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calcWidget)
    {
        if (calcWidget->objectName().isEmpty())
            calcWidget->setObjectName(QString::fromUtf8("calcWidget"));
        calcWidget->resize(800, 600);
        centralwidget = new QWidget(calcWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 120, 321, 131));
        romanLabel = new QLabel(centralwidget);
        romanLabel->setObjectName(QString::fromUtf8("romanLabel"));
        romanLabel->setGeometry(QRect(290, 290, 221, 91));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        romanLabel->setFont(font);
        calcWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calcWidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        calcWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(calcWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        calcWidget->setStatusBar(statusbar);

        retranslateUi(calcWidget);

        QMetaObject::connectSlotsByName(calcWidget);
    } // setupUi

    void retranslateUi(QMainWindow *calcWidget)
    {
        calcWidget->setWindowTitle(QApplication::translate("calcWidget", "calcWidget", nullptr));
        pushButton->setText(QApplication::translate("calcWidget", "\320\234\320\276\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 \320\264\320\260\320\277 \320\264\320\260\320\277", nullptr));
        romanLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class calcWidget: public Ui_calcWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCWIDGET_H
