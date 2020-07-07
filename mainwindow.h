#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fpga.h"
#include "hps.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tajmerbt_clicked();

    void UpdateTime();

    void UpdateTime2();

    void on_startbt_clicked();

    void on_stopbt_clicked();

private:
    Ui::MainWindow *ui;
    FPGA* fpga;
    HPS* hps;
    QTimer *timer;
    u_int64_t m_ir_rx_timeout[24];
    QTimer *timer_1s;
    QTimer *timer_100ms;
    long stoperica;
};

#endif // MAINWINDOW_H
