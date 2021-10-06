#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtGlobal>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plusButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("First Summand");
        ui->secondLabel->setText("Second Summand");
        ui->outLabel->setText("Sum");
        ui->secondInput->setReadOnly(false);

    }
}

void MainWindow::on_minusButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Minuend");
        ui->secondLabel->setText("Subtrahend");
        ui->outLabel->setText("Difference");
        ui->secondInput->setReadOnly(false);
    }
}

void MainWindow::on_multiplyButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Multiplicand");
        ui->secondLabel->setText("Multiplier");
        ui->outLabel->setText("Composition");
        ui->secondInput->setReadOnly(false);
    }
}

void MainWindow::on_divideButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Dividend");
        ui->secondLabel->setText("Divider");
        ui->outLabel->setText("Private");
        ui->secondInput->setReadOnly(false);
    }
}



void MainWindow::on_expButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Base");
        ui->secondLabel->setText("Degree");
        ui->outLabel->setText("Result");
        ui->secondInput->setReadOnly(false);
    }
}

void MainWindow::on_logButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Number");
        ui->secondLabel->setText("Log base");
        ui->outLabel->setText("Result");
        ui->secondInput->setReadOnly(false);
    }
}

double logCount(double a, double b)
{
    return log(b)/log(a);
}

// Update here. Made this function for checking base in both inputs
// Also added separate line for base errors trace in UI

void MainWindow::BaseChecks()
{
    int Base = ui->numberingBaseInput->text().toInt();

    QString op1 = ui->firstInput->text();
    QString op2 = ui->secondInput->text();
    QPalette errorPalette;
    QPalette defaultPalette;
    errorPalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));
    defaultPalette.setColor(QPalette::Base, QColor::fromRgb(255,255,255));


     bool okX, okY;

    int x = op1.toInt(&okX, Base);
    int y = op2.toInt(&okY, Base);

    if(okX && okY)
    {
        ui->baseError->setText("All ok!");
        ui->firstInput->setPalette(defaultPalette);
        ui->secondInput->setPalette(defaultPalette);
    }
    else if(!okX && !okY)
    {
        ui->baseError->setText("BASE ERROR AT BOTH INPUTS!");
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->firstInput->setPalette(errorPalette);
        ui->secondInput->setPalette(errorPalette);
    }
    else if(!okX)
    {
        ui->baseError->setText("BASE ERROR AT FIRST INPUT");
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->firstInput->setPalette(errorPalette);
    }
    else
    {
        ui->outputLine->setText("BASE ERROR AT SECOND INPUT");
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->secondInput->setPalette(errorPalette);
    }
}


void MainWindow::on_countButton_clicked()
{
    QString op1 = ui->firstInput->text();
    QString op2 = ui->secondInput->text();
    QString baseString = ui->numberingBaseInput->text(); //Numbering base input
    QPalette errorPalette;
    QPalette defaultPalette;
    errorPalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));
    defaultPalette.setColor(QPalette::Base, QColor::fromRgb(255,255,255));

    bool okX, okY, okS;
    double x = op1.toDouble(&okX);
    double y = op2.toDouble(&okY);
    double res = -1;
    int base; //Numbering base varaible
    int resBase;

    if (baseString.isEmpty()) base = 10;
        else base = baseString.toInt(&okS);


    if(okX && okY && okS && base > 0)
    {
        ui->firstInput->setPalette(defaultPalette);
        ui->secondInput->setPalette(defaultPalette);
        ui->numberingBaseInput->setPalette(defaultPalette);
        if(ui->plusButton->isChecked())
        {
            if(base != 10)
            {
                x = op1.toInt();
                y = op2.toInt();
                resBase = x + y;
                QString resText = QString::number(resBase, base);
                ui->outputLine->setText(resText);
            }
            else
            {
                res = x + y;
                QString resText = QString::number(res);
                ui->outputLine->setText(resText);
            }
        }
        if(ui->minusButton->isChecked())
        {
            if(base != 10)
            {
                x = op1.toInt();
                y = op2.toInt();
                resBase = x - y;
                QString resText = QString::number(resBase, base);
                ui->outputLine->setText(resText);
            }
            else
            {
                res = x - y;
                QString resText = QString::number(res);
                ui->outputLine->setText(resText);
            }
        }

        if(ui->multiplyButton->isChecked())
        {
            if(base != 10)
            {
                x = op1.toInt();
                y = op2.toInt();
                resBase = x * y;
                QString resText = QString::number(resBase, base);
                ui->outputLine->setText(resText);
            }
            else
            {
                res = x * y;
                QString resText = QString::number(res);
                ui->outputLine->setText(resText);
            }
        }
        if(ui->expButton->isChecked())
        {
            if(base != 10)
            {
                x = op1.toInt();
                y = op2.toInt();
                resBase = pow(x,y);
                QString resText = QString::number(resBase, base);
                ui->outputLine->setText(resText);
            }
            else
            {
                res = pow(x,y);
                QString resText = QString::number(res);
                ui->outputLine->setText(resText);
            }
        }
        if(ui->logButton->isChecked())
        {
            if(x < 0)
            {
                ui->outputLine->setText("ERROR! WATCH ABOVE!");
                ui->firstInput->setText("VALUE MUST BE POSITIVE");
                ui->firstInput->setPalette(errorPalette);
            }
            else if(y == 1)
            {
                ui->outputLine->setText("ERROR! WATCH ABOVE!");
                ui->secondInput->setText("LOG BASE CAN'T BE 1");
                ui->secondInput->setPalette(errorPalette);
            }
            else if(y < 0)
            {
                ui->outputLine->setText("ERROR! WATCH ABOVE!");
                ui->secondInput->setText("LOG BASE MUST BE POSITIVE");
                ui->secondInput->setPalette(errorPalette);
            }
            else
            {
                if(base != 10)
                {
                    x = op1.toInt();
                    y = op2.toInt();
                    resBase = logCount(y, x);
                    QString resText = QString::number(resBase, base);
                    ui->outputLine->setText(resText);
                }
                else
                {
                    res = logCount(y,x);
                    QString resText = QString::number(res);
                    ui->outputLine->setText(resText);
                }
            }
        }
        if(ui->divideButton->isChecked())
        {
            if(base != 10)
            {
                if(y == 0)
                {
                    ui->outputLine->setText("ERROR! WATCH ABOVE!");
                    ui->secondInput->setText("DIVISION BY NULL!");
                    ui->secondInput->setPalette(errorPalette);
                }
                else
                {
                    x = op1.toInt();
                    y = op2.toInt();
                    resBase = x / y;
                    QString resText = QString::number(resBase, base);
                    ui->outputLine->setText(resText);
                }
            }
            else
            {
                if(y == 0)
                {
                    ui->outputLine->setText("ERROR! WATCH ABOVE!");
                    ui->secondInput->setText("DIVISION BY NULL!");
                    ui->secondInput->setPalette(errorPalette);
                }
                else
                {
                    res = x / y;
                    QString resText = QString::number(res);
                    ui->outputLine->setText(resText);
                }
            }
        }

    }
    //errors trace
    if(!okX && !okY) //both are incorrect
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("NOT A NUMBER INPUT!");
        ui->secondInput->setText("NOT A NUMBER INPUT!");
        ui->firstInput->setPalette(errorPalette);
        ui->secondInput->setPalette(errorPalette);
    }
    if(!okX)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("NOT A NUMBER INPUT!");
        ui->firstInput->setPalette(errorPalette);
    }
    if(!okY)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->secondInput->setText("NOT A NUMBER INPUT!");
        ui->secondInput->setPalette(errorPalette);
    }
    if(!okX && okY)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("NOT A NUMBER INPUT!");
        ui->firstInput->setPalette(errorPalette);
        ui->secondInput->setPalette(defaultPalette);
    }
    if(okX && !okY)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->secondInput->setText("NOT A NUMBER INPUT!");
        ui->secondInput->setPalette(errorPalette);
        ui->firstInput->setPalette(defaultPalette);
    }
    if(ui->firstInput->text() == "" && ui->secondInput->text() == "")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("EMPTY INPUT!");
        ui->secondInput->setText("EMPTY INPUT!");
        ui->firstInput->setPalette(errorPalette);
        ui->secondInput->setPalette(errorPalette);
    }
    if(ui->firstInput->text() == "")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("EMPTY INPUT!");
        ui->firstInput->setPalette(errorPalette);
    }
    if(ui->secondInput->text() == "")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("EMPTY INPUT!");
        ui->firstInput->setPalette(errorPalette);
    }
    if(ui->expButton->isChecked() && ui->firstInput->text() == "0" && ui->secondInput->text() == "0")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->firstInput->setText("UNCERTAINTY 0^0");
        ui->secondInput->setText("UNCERTAINTY 0^0");
        ui->firstInput->setPalette(errorPalette);
        ui->secondInput->setPalette(errorPalette);
    }
    if(ui->numberingBaseInput->text().isEmpty())
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->numberingBaseInput->setText("EMPTY INPUT!");
        ui->numberingBaseInput->setPalette(errorPalette);
    }
    else if(!okS)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->numberingBaseInput->setText("NOT A NUMBER INPUT!");
        ui->numberingBaseInput->setPalette(errorPalette);
    }
    else if(base <= 0)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->numberingBaseInput->setText("MUST BE POSITIVE!");
        ui->numberingBaseInput->setPalette(errorPalette);
    }
    if(qIsInf(res))
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->firstInput->setText("NUMBER IS OUT OF RANGE");
        ui->secondInput->setText("NUMBER IS OUT OF RANGE");
        ui->firstInput->setPalette(errorPalette);
        ui->secondInput->setPalette(errorPalette);
    }
    BaseChecks(); //Invoking new function here
}



void MainWindow::on_clearButton_clicked()
{
    QPalette defaultPalette;
    QPalette errorPalette;
    errorPalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));
    defaultPalette.setColor(QPalette::Base, QColor::fromRgb(255,255,255));
    ui->firstInput->clear();
    ui->secondInput->clear();
    ui->outputLine->clear();
    ui->firstInput->setPalette(defaultPalette);
    ui->secondInput->setPalette(defaultPalette);
    if(ui->numberingBaseInput->palette() == errorPalette)
    {
        ui->numberingBaseInput->setPalette(defaultPalette);
        ui->numberingBaseInput->setText("10");
    }
}
