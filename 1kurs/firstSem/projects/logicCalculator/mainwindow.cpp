#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->outputLine->setText("0");
    this->setStyleSheet("background-color: rgb(255,0,125);");
}

MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::removeX() //remove first comboBox items for inversion operation
{
    ui->firstOperand->setItemText(0, " ");
    ui->firstOperand->setItemText(1, " ");
}

void MainWindow::setX() //set them back for others
{
    ui->firstOperand->setItemText(0, "0");
    ui->firstOperand->setItemText(1, "1");
}

void MainWindow::calculateResult(bool result)
{
    if(result == true)
    {
        ui->outputLine->setText("1");
        this->setStyleSheet("background-color: rgb(0,255,125);");
    }
    else
    {
        ui->outputLine->setText("0");
        this->setStyleSheet("background-color: rgb(255,0,125);");
    }
}

/*
Index designation

0 - AND
1 - OR
2 - Inversion
3 - Implication
4 - Equivalence
5 - Excluding OR

*/

bool MainWindow::calculate(bool firstValue, bool secondValue, int operIndex)
{
    bool result;

    if(operIndex == 0)
    {
        setX();
        result = firstValue && secondValue;
    }

    else if(operIndex == 1)
    {
        setX();
        result = firstValue || secondValue;
    }

    else if(operIndex == 2)
    {
        removeX();
        result = !secondValue;
    }

    else if(operIndex == 3)
    {
        setX();
        result = !firstValue + secondValue;
    }

    else if(operIndex == 4)
    {
        setX();
        result = firstValue == secondValue;
    }

    else if(operIndex == 5)
    {
        setX();
        result = firstValue ^ secondValue;
    }

    return result;
}


void MainWindow::on_firstOperand_currentIndexChanged(int index)
{
    calculateResult(calculate(index, ui->secondOperand->currentIndex(), ui->operationBox->currentIndex()));
}

void MainWindow::on_operationBox_currentIndexChanged(int index)
{
    calculateResult(calculate(ui->firstOperand->currentIndex(), ui->secondOperand->currentIndex(), index));
}

void MainWindow::on_secondOperand_currentIndexChanged(int index)
{
    calculateResult(calculate(ui->firstOperand->currentIndex(), index, ui->operationBox->currentIndex()));
}
