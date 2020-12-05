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

double sideCount(double ax, double ay, double bx, double by)
{
    return sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
}

bool MainWindow::errorsTrace(bool ax, bool ay, bool bx, bool by, bool cx, bool cy)
{

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

    double square, perimeter;

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

    if(okax && okay && okbx && okby && okcx && okcy)
    {
        square = 0.5 * abs((ax - cx) * (by - cy) - (bx - cx) * (ay -cy));
        QString squareText = QString::number(square);
        ui->squareOut->setText(squareText);
    }

}
