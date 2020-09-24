#ifndef CALCWIDGET_H
#define CALCWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calcWidget; }
QT_END_NAMESPACE

class calcWidget : public QMainWindow
{
    Q_OBJECT

public:
    calcWidget(QWidget *parent = nullptr);
    ~calcWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::calcWidget *ui;
};
#endif // CALCWIDGET_H
