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
    void on_plusButton_toggled(bool checked);

    void on_minusButton_toggled(bool checked);

    void on_multiplyButton_toggled(bool checked);

    void on_divideButton_toggled(bool checked);

    void on_countButton_clicked();

    void on_expButton_toggled(bool checked);

    void on_logButton_toggled(bool checked);

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
