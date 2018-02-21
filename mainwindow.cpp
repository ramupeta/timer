#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QTimer>
#include<QDebug>
#include<QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    adf = new QTimer (this);
    suf = new QTimer(this);
    sta=new QTimer(this);
    curti=new QTimer(this);
    t=new QTime(0,0);
    connect(adf,SIGNAL(timeout()),this,SLOT(addhere()));
    connect(suf,SIGNAL(timeout()),this,SLOT(subhere()));
    connect(sta,SIGNAL(timeout()),this,SLOT(countdownstart()));
    connect(curti,SIGNAL(timeout()),this,SLOT(currenttime()));


    ui->setupUi(this);
    curti->start();
    QFile fuv("/home/rahul/timeexample/uv_details.csv");
    if(fuv.open(QIODevice::ReadOnly))
    {
        QTextStream fp(&fuv);
        while(!fp.atEnd())
        {
            QString fg;
            fg=fp.readLine();
            QStringList w=fg.split(";");
           QString jkl=w[1];
            remai_uv=jkl.toDouble();
            jkl=w[3];
            total_uv=jkl.toDouble();
            qDebug()<<"w[1]:"<<w[1]<<"  w[2]"<<w[3];
        }

        qDebug()<<"remain:"<<remai_uv<<" total:"<<total_uv;
    }fuv.close();
        t->setHMS(0,sece,minu);
        QString ttl=t->toString();
        ui->lcdNumber->display(ttl);
//        QSize pb;
//        pb=ui->pushButton->sizeHint();
//        qDebug()<<""
        //int yui=998.16;

        ui->progressBar->setValue(0);
        ui->remaining_life->display(remai_uv);
        ui->totaluv->display(total_uv);
}
void MainWindow::currenttime()
{
    QTime ct=QTime::currentTime();
    QString cut=ct.toString();
    ui->time->setText(cut);

}
void MainWindow::addhere()
{
    sece++;
    if(sece==60)
    {
        sece=60;
    }
    t->setHMS(0,sece,minu);
    QString qs=t->toString();
    //ui->label->setText(qs);

    ui->lcdNumber->display(qs);
}


void MainWindow::subhere()
{
    sece--;
    if(sece==-1)
    {
        sece=0;
    }
    t->setHMS(0,sece,minu);
    QString gfg=t->toString();
    ui->lcdNumber->display(gfg);

}
void MainWindow::countdownstart()
{

   int min=t->minute();
   int sec=t->second();

    remai_uv=remai_uv*60;
   while(k!=0)
   {
       lkj=(min*60)+2;
       dislc=100/lkj;
       sam=dislc;


   k--;
   }
   bny++;
   dislc=dislc+(sam);
   qDebug()<<"progressbar val:"<<dislc<<"  x"<<bny;
   ui->progressBar->setValue(dislc);
   remai_uv--;
   qDebug()<<"remain:"<<remai_uv;
   qDebug()<<"  minute:"<<min<<"  second:"<<sec;
    if(min==0&&sec==0)
    {
        sta->stop();
        minu=0;
        sece=0;
        numbr=0;k=0;
        remai_uv/=60;

        ui->remaining_life->display(remai_uv);
        ui->totaluv->display(total_uv);
        ui->progressBar->setValue(100);
           QFile  fw("/home/rahul/timeexample/uv_details.csv");
           if(fw.open(QIODevice::WriteOnly))
           {
               QTextStream fsw(&fw);

                 fsw<<"remaining_life"<<";"<<remai_uv<<";"<<"total_life"<<";"<<total_uv;

           }fw.close();

        return;

    }

    t->setHMS(0,t->addMSecs(-1).minute(),t->addSecs(-1).second());

    qDebug()<<"numbr:"<<numbr;
    QString rgr=t->toString();
    ui->lcdNumber->display(rgr);
    remai_uv/=60;
    ui->remaining_life->display(remai_uv);
    ui->totaluv->display(total_uv);
    //ui->progressBar->setValue(mk);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //minu=t->addMSecs(+1).minute();
    minu++;
    if(minu==60)
    {
        minu=0;
        sece++;
    }

    t->setHMS(0,sece,minu);

    QString fg=t->toString();
    ui->lcdNumber->display(fg);

}

void MainWindow::on_pushButton_2_clicked()
{
    minu--;
    if(minu==-1)
    {
        minu=59;
        sece--;
    }
    if(sece==-1)
    {
        sece=0;
        minu=0;
    }
    qDebug()<<"minu:"<<minu<<"  sece:"<<sece;

    t->setHMS(0,sece,minu);
    QString gf=t->toString();
    ui->lcdNumber->display(gf);


}

void MainWindow::on_pushButton_pressed()
{
    adf->start(2000);
}

void MainWindow::on_pushButton_released()
{
    adf->stop();
}

void MainWindow::on_pushButton_2_pressed()
{
    suf->start(2000);
}

void MainWindow::on_pushButton_2_released()
{
    suf->stop();
}

void MainWindow::on_start_clicked()
{
    sta->start(1000);
}

void MainWindow::on_reset_clicked()
{
    minu=0;sece=0;
    t->setHMS(0,0,0);
    QString dth=t->toString();
    ui->lcdNumber->display(dth);
}
