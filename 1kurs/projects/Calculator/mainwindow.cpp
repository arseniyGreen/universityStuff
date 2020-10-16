#include "mainwindow.h"
#include "ui_mainwindow.h"
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


void MainWindow::on_countButton_clicked()
{
    QString op1 = ui->firstInput->text();
    QString op2 = ui->secondInput->text();
    QPalette errorPalette;

    bool okX, okY;
    double x = op1.toDouble(&okX);
    double y = op2.toDouble(&okY);

    if(okX && okY)
    {
        if(ui->plusButton->isChecked())
        {
            double res = x + y;
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
        }
        if(ui->minusButton->isChecked())
        {
            double res = x - y;
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
        }

        if(ui->multiplyButton->isChecked())
        {
            double res = x * y;
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
        }
        if(ui->expButton->isChecked())
        {
            double res = pow(x, y);
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
        }
        if(ui->logButton->isChecked())
        {
            if(x < 0)
            {
                ui->outputLine->setText("ERROR! WATCH ABOVE!");
                ui->firstInput->setText("VALUE MUST BE POSITIVE");
            }
            else if(y == 1)
            {
                ui->outputLine->setText("ERROR! WATCH ABOVE!");
                ui->secondInput->setText("LOG BASE CAN'T BE 1");
            }
            else if(y < 0)
            {
                ui->outputLine->setText("ERROR! WATCH ABOVE!");
                ui->secondInput->setText("LOG BASE MUST BE POSITIVE");
            }
            else
            {
            double res = logCount(y, x);
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
            }
        }
    }
    //errors trace
    if(!okX && !okY) //both are incorrect
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("NOT A NUMBER INPUT!");
        ui->secondInput->setText("NOT A NUMBER INPUT!");
    }
    if(!okX)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("NOT A NUMBER INPUT!");
    }
    if(!okY)
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->secondInput->setText("NOT A NUMBER INPUT!");
    }
    if(ui->firstInput->text() == "" && ui->secondInput->text() == "")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("EMPTY INPUT!");
        ui->secondInput->setText("EMPTY INPUT!");
    }
    if(ui->firstInput->text() == "")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("EMPTY INPUT!");
    }
    if(ui->secondInput->text() == "")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE");
        ui->firstInput->setText("EMPTY INPUT!");
    }
    if(ui->divideButton->isChecked() && ui->secondInput->text() == "0")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->secondInput->setText("DIVISION BY NULL!");
    }
    if(ui->expButton->isChecked() && ui->firstInput->text() == "0" && ui->secondInput->text() == "0")
    {
        ui->outputLine->setText("ERROR! WATCH ABOVE!");
        ui->firstInput->setText("UNCERTAINTY 0^0");
        ui->secondInput->setText("UNCERTAINTY 0^0");
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->firstInput->clear();
    ui->secondInput->clear();
    ui->outputLine->clear();
}
