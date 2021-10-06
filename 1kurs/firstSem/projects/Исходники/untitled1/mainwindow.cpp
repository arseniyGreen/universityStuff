#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int n = ui->comboBox->count();

    for(int i = 0; i < n; i++)
    {
        QString s = ui->comboBox->itemText(n - i - 1);
        ui->listWidget->addItem(s);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->listWidget->setCurrentRow(index);
    QString current = ui->comboBox->itemText(index);
    int i = 0;
    for (; i < ui->listWidget->count(); i++)
    {
        QString rowText = ui->listWidget->item(i)->text();
        if (current == rowText) break;
    }
    if (i < ui->listWidget->count())
    {
        ui->listWidget->setCurrentRow(i);
    }
    else
    {
        ui->listWidget->setCurrentRow(-1);
    }
}


void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ui->comboBox->setCurrentIndex(currentRow);
}
