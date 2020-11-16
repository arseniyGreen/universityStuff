#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette falsePalette;
    falsePalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));
    ui->outputLine->setPalette(falsePalette);
    ui->outputLine->setText("0");
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

void MainWindow::count()
{
    //declaring varaibles
    int indX = ui->firstOperand->currentIndex();
    int indY = ui->secondOperand->currentIndex();
    int opIndex = ui->operationBox->currentIndex();
    QPalette truePalette;
    QPalette falsePalette;
    truePalette.setColor(QPalette::Base, QColor::fromRgb(0,255,125));
    falsePalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));

    bool x = 0;
    bool y = 0;
    bool resault = 0;

    if (indX == 1) x = 1;
    if (indY == 1) y = 1;

    //Count section
    if(opIndex == 0) //AND statement count
    {
        setX();
        resault = x && y;
    }
    else if(opIndex == 1) //OR statement count
    {
        setX();
        resault = x || y;
    }
    else if(opIndex == 2)//INVERSION statement count
    {
        removeX();
        resault = !y;
    }
    else if(opIndex == 3)//IMPLICATION statement count
    {
        setX();
        resault = !x + y;
    }
    else if(opIndex == 4)//EQUIVALENCE statement count
    {
        setX();
        resault = x == y;
    }
    else if(opIndex == 5)//EXCLUDING OR statement count
    {
        setX();
        resault = x ^ y;
    }

    //Resault output section
    if(resault == 0)
    {
        ui->outputLine->setText("0");
        ui->outputLine->setPalette(falsePalette);
    }
    else
    {
        ui->outputLine->setText("1");
        ui->outputLine->setPalette(truePalette);
    }

}


void MainWindow::on_firstOperand_currentIndexChanged(int index)
{
    count();
}

void MainWindow::on_operationBox_currentIndexChanged(int index)
{
    count();
}

void MainWindow::on_secondOperand_currentIndexChanged(int index)
{
    count();
}
