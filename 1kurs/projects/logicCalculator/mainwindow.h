#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void count();

    void removeX();

    void setX();

    bool calculate(bool firstValue, bool secondValue, int operIndex);

    void calculateResult(bool result);

    void on_firstOperand_currentIndexChanged(int index);

    void on_operationBox_currentIndexChanged(int index);

    void on_secondOperand_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
