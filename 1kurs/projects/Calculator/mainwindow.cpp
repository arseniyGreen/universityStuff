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
