#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QtGlobal>

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

double sideCount(double ax, double ay, double bx, double by)
{
    return sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
}

bool MainWindow::errorsTrace(bool ax, bool ay, bool bx, bool by, bool cx, bool cy)
{
    bool okAx = false, okAy = false;
    bool okBx = false, okBy = false;
    bool okCx = false, okCy = false;
    bool res;

    QPalette errorPalette;
    QPalette defaultPalette;
    errorPalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));
    defaultPalette.setColor(QPalette::Base, QColor::fromRgb(255,255,255));


    if(ax && ay && bx && by && cx && cy)
    {
        ui->axInput->setPalette(defaultPalette);
        ui->ayInput->setPalette(defaultPalette);
        ui->bxInput->setPalette(defaultPalette);
        ui->byInput->setPalette(defaultPalette);
        ui->cxInput->setPalette(defaultPalette);
        ui->cyInput->setPalette(defaultPalette);
        ui->perimOut->setPalette(defaultPalette);
        ui->squareOut->setPalette(defaultPalette);

        ui->errorOutput->clear();
        res = true;
    }
    else
    {
        if(!ax)
        {
            ui->axInput->setPalette(errorPalette);
            okAx = true;
        }
        if(!ay)
        {
            ui->ayInput->setPalette(errorPalette);
            okAy = true;
        }
        if(!bx)
        {
            ui->bxInput->setPalette(errorPalette);
            okBx = true;
        }
        if(!by)
        {
            ui->byInput->setPalette(errorPalette);
            okBy = true;
        }
        if(!cx)
        {
            ui->cxInput->setPalette(errorPalette);
            okCx = true;
        }
        if(!cy)
        {
            ui->cyInput->setPalette(errorPalette);
            okCy = true;
        }

        ui->squareOut->setPalette(defaultPalette);
        ui->perimOut->setPalette(defaultPalette);
        res = false;
    }
    if(!okAx) ui->axInput->setPalette(defaultPalette);
    if(!okAy) ui->ayInput->setPalette(defaultPalette);
    if(!okBx) ui->bxInput->setPalette(defaultPalette);
    if(!okBy) ui->byInput->setPalette(defaultPalette);
    if(!okCx) ui->cxInput->setPalette(defaultPalette);
    if(!okCy) ui->cyInput->setPalette(defaultPalette);

    return res;
}

void MainWindow::on_countButton_clicked()
{
    ui->perimOut->clear();
    ui->squareOut->clear();

    QPalette errorPalette;
    QPalette defaultPalette;
    errorPalette.setColor(QPalette::Base, QColor::fromRgb(255,0,125));
    defaultPalette.setColor(QPalette::Base, QColor::fromRgb(255,255,255));

    bool okax, okay, okbx, okby, okcx, okcy;

    QString Qax = ui->axInput->text();
    QString Qay = ui->ayInput->text();
    QString Qbx = ui->bxInput->text();
    QString Qby = ui->byInput->text();
    QString Qcx = ui->cxInput->text();
    QString Qcy = ui->cyInput->text();

    double ax = Qax.toDouble(&okax);
    double ay = Qay.toDouble(&okay);
    double bx = Qbx.toDouble(&okbx);
    double by = Qby.toDouble(&okby);
    double cx = Qcx.toDouble(&okcx);
    double cy = Qcy.toDouble(&okcy);

    double square = -1;
    double perimeter = -1;

    bool ok = errorsTrace(okax, okay, okbx, okby, okcx, okcy);

    if(ok)
    {
        square = 0.5 * abs((ax - cx) * (by - cy) - (bx - cx) * (ay -cy));
        perimeter = sideCount(ax, ay, bx, by) + sideCount(ax, ay, cx, cy) + sideCount(bx, by, cx, cy);
    }
    //errors check since here

    //for square:
    if(qIsInf(square)) ui->errorOutput->setText("TRIANGLE IS INFITE!"); //infinity check
    else if(qIsNaN(square)) ui->errorOutput->setText("SQUARE IS NOT A NUMBER!"); //not a number check
    else if(ok && square <= 1e-17) ui->errorOutput->setText("SQUARE IS TOO SMALL!"); //small number check
    else if(square < 0) ui->errorOutput->setText("FIX HIGHLIGHTED COORDS!");
    else //no errors
    {
        QString squareOut = QString::number(square);
        ui->squareOut->setText(squareOut);
        ui->errorOutput->clear();
    }

    //for perimeter
    if(qIsInf(perimeter)) ui->errorOutput->setText("TRIANGLE IS INFITE!"); //infinity check
    else if(qIsNaN(perimeter)) ui->errorOutput->setText("PERIMETER IS NOT A NUMBER!"); //not a number check
    else if(ok && perimeter <= 1e-17) ui->errorOutput->setText("PERIMETER IS TOO SMALL!"); //small number check
    else if(perimeter < 0) ui->errorOutput->setText("FIX HIGHLIGHTED COORDS!");
    else if(qIsNull(perimeter)) ui->errorOutput->setText("PERIMETER EQUALS NULL!"); //null check
    else //no errors
    {
        QString perimOut = QString::number(perimeter);
        ui->perimOut->setText(perimOut);
        ui->errorOutput->clear();
    }

}

void MainWindow::on_clearButton_clicked()
{
    QPalette defaultPalette;
    defaultPalette.setColor(QPalette::Base, QColor::fromRgb(255,255,255));

    ui->axInput->clear();
    ui->ayInput->clear();
    ui->bxInput->clear();
    ui->byInput->clear();
    ui->cxInput->clear();
    ui->cyInput->clear();

    ui->axInput->setPalette(defaultPalette);
    ui->ayInput->setPalette(defaultPalette);
    ui->bxInput->setPalette(defaultPalette);
    ui->byInput->setPalette(defaultPalette);
    ui->cxInput->setPalette(defaultPalette);
    ui->cyInput->setPalette(defaultPalette);

    ui->squareOut->clear();
    ui->perimOut->clear();

}
