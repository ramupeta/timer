#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTime>
#include<QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int minu=0,sece=0;
    int numbr=0,k=1,mk=0,bny=0;
    double remai_uv=1000,total_uv=1000,dislc,lkj,sam;

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();
private slots:
    void addhere();
    void subhere();
    void countdownstart();
    void currenttime();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_start_clicked();

    void on_reset_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* adf;
    QTimer* suf;
    QTimer* sta;
    QTimer*curti;
    //QTimer *tmr=new QTimer();
    QTime *t;

};

#endif // MAINWINDOW_H
