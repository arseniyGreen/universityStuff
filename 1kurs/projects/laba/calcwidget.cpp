#include "calcwidget.h"
#include "ui_calcwidget.h"

calcWidget::calcWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calcWidget)
{
    ui->setupUi(this);
}

calcWidget::~calcWidget()
{
    delete ui;
}


void calcWidget::on_pushButton_clicked()
{
    ui->romanButton->setText("PAjiloy Romanb");
}
