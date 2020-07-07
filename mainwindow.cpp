#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    memset(m_ir_rx_timeout, 0, sizeof(m_ir_rx_timeout));

    fpga = new FPGA;
    hps = new HPS;

    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTime()
{
    if(ui->tabWidget->currentIndex()==0){
        
        ui->vrijemelb->setText(QTime::currentTime().toString("hh:mm:ss"));
        fpga->CustomHexSet(5, QTime::currentTime().toString("hh").toInt()/10);
        fpga->CustomHexSet(4, QTime::currentTime().toString("hh").toInt()%10);
        fpga->CustomHexSet(3, QTime::currentTime().toString("mm").toInt()/10);
        fpga->CustomHexSet(2, QTime::currentTime().toString("mm").toInt()%10);
        fpga->CustomHexSet(1, QTime::currentTime().toString("ss").toInt()/10);
        fpga->CustomHexSet(0, QTime::currentTime().toString("ss").toInt()%10);
        
    }
}

void MainWindow::on_tajmerbt_clicked()
{
    int numSec=ui->txtNumber->text().toInt();
    for(;numSec>=0;numSec--)
    {
        {
            int h=numSec/3600;
            int m=(numSec%3600)/60;
            int s=numSec%60;
            int h1=h/10;
            int h2=h%10;
            int m1=m/10;
            int m2=m%10;
            int s1=s/10;
            int s2=s%10;
            qDebug()<<"\n"<<h1<<h2<<":"<<m1<<m2<<":"<<s1<<s2;


            fpga->CustomHexSet(5, h1);
            fpga->CustomHexSet(4, h2);
            fpga->CustomHexSet(3, m1);
            fpga->CustomHexSet(2, m2);
            fpga->CustomHexSet(1, s1);
            fpga->CustomHexSet(0, s2);


            sleep(1);
        }
    }
    qDebug()<<"VRIJEME JE ISTEKLO!!!\n";
}

void MainWindow::UpdateTime2(){
    long sek=stoperica/10;
    int m=sek/60;
    int s=sek%60;
    int ds=stoperica%10;
    //int ss=stoperica%10;
    stoperica++;

    QString* lbl=new QString(QString::number(m/10)+QString::number(m%10)+":"+QString::number(s/10)+QString::number(s%10)+"."+QString::number(ds)+"0");
    ui->stopericalb->setText(*lbl);

    fpga->CustomHexSet(5, m/10);
    fpga->CustomHexSet(4, m%10);
    fpga->CustomHexSet(3, s/10);
    fpga->CustomHexSet(2, s%10);
    fpga->CustomHexSet(1, ds);
    fpga->CustomHexSet(0, 0);
    
}

void MainWindow::on_startbt_clicked()
{
    stoperica=0;
    timer_100ms = new QTimer(this);
    QObject::connect(timer_100ms, SIGNAL(timeout()), this, SLOT(UpdateTime2()));
    timer_100ms->start(100);
}

void MainWindow::on_stopbt_clicked()
{
    timer_100ms->stop();
}
