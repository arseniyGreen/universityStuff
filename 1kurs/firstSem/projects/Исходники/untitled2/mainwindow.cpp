#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(2, 200);
    ui->tableWidget->setColumnWidth(3, 200);

    ui->tableWidget->setRowCount(5);

//    QTableWidgetItem *item = new QTableWidgetItem("Pen");
  //  ui->tableWidget->setItem(0, 0, item);
    //item->setBackgroundColor(Qt::yellow);
    //item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    //QTableWidgetItem *item1 = new QTableWidgetItem("Cock");
    //ui->tableWidget->setItem(1, 0, item1);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addButton_clicked()
{
    int n = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(n+1);
}

void MainWindow::on_removeButton_clicked()
{
    int i = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(i);
}

void MainWindow::on_calcButton_clicked()
{
    for (int r = 0; r < ui->tableWidget->rowCount(); r++)
    {
        QTableWidgetItem * item1 = ui->tableWidget->item(r,1);
        QTableWidgetItem * item2 = ui->tableWidget->item(r,2);

        if(item1 != nullptr && item2 != nullptr)
        {
            //nice sluchiy
            QString str1 = item1->text();
            QString str2 = item2->text();
            bool ok1, ok2;
            double d1 = str1.toDouble(&ok1);
            double d2 = str2.toDouble(&ok2);

            if(ok1 && ok2)
            {
                //nice dick
                ui->tableWidget->setItem(r, 3,
                                         new QTableWidgetItem(QString::number(d1 * d2)));

                continue;
            }
            if(!ok1)
            {
                item1->setBackgroundColor(Qt::magenta);
            }
            if(!ok2)
            {
                item2->setBackgroundColor(Qt::magenta);
            }
        }
    }
}



void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    QTableWidgetItem * item1 = ui->tableWidget->item(row,1);
    QTableWidgetItem * item2 = ui->tableWidget->item(row,2);

    if(item1 != nullptr && item2 != nullptr)
    {
        //nice sluchiy
        QString str1 = item1->text();
        QString str2 = item2->text();
        bool ok1, ok2;
        double d1 = str1.toDouble(&ok1);
        double d2 = str2.toDouble(&ok2);

        if(ok1 && ok2)
        {
            ui->tableWidget->setItem(row, 3,
                                     new QTableWidgetItem(QString::number(d1 * d2)));

        }
        if(!ok1)
        {
            item1->setBackgroundColor(Qt::magenta);
        }
        if(!ok2)
        {
            item2->setBackgroundColor(Qt::magenta);
        }
    }
}
