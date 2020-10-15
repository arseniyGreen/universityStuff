#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    }
}

void MainWindow::on_minusButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Minuend");
        ui->secondLabel->setText("Subtrahend");
        ui->outLabel->setText("Difference");
    }
}

void MainWindow::on_multiplyButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Multiplicand");
        ui->secondLabel->setText("Multiplier");
        ui->outLabel->setText("Composition");
    }
}

void MainWindow::on_divideButton_toggled(bool checked)
{
    if(checked)
    {
        ui->firstLabel->setText("Dividend");
        ui->secondLabel->setText("Divider");
        ui->outLabel->setText("Private");
    }
}

void MainWindow::on_countButton_clicked()
{
    QString op1 = ui->firstInput->text();
    QString op2 = ui->secondInput->text();

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
        if(ui->divideButton->isChecked())
        {
            double res = x / y;
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
        }
        if(ui->multiplyButton->isChecked())
        {
            double res = x * y;
            QString resText = QString::number(res);
            ui->outputLine->setText(resText);
        }
    }
}
