#include "startwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>

StartWindow::StartWindow()
{
    this->setFixedSize(1280,800);

    this->setWindowTitle("2152118 史君宝");

    QLabel *label1=new QLabel;
    label1->setParent(this);
    QFont font1;
    font1.setFamily("宋体");
    font1.setPointSize(30);
    QString str1=QString("数据结构课设——程序展示");
    label1->setFont(font1);
    label1->setText(str1);

    label1->setGeometry((this->width()-30*str1.size())/3,100,this->width(),50);

    QString str2=QString("2152118 史君宝");
    QLabel *label2=new QLabel;
    label2->setParent(this);
    QFont font2;
    font2.setFamily("宋体");
    font2.setPointSize(26);
    label2->setFont(font2);
    label2->setText(str2);
    label2->setGeometry(800,300,this->width()-800,50);

    QString str3=QString("文本编辑器");
    QLabel *label3=new QLabel;
    label3->setParent(this);
    QFont font3;
    font3.setFamily("宋体");
    font3.setPointSize(26);
    label3->setFont(font3);
    label3->setText(str3);
    label3->setGeometry(800,400,this->width()-800,50);


    QPushButton * startBtn=new QPushButton ("");
    startBtn->setParent(this);
    startBtn->setFixedSize(200,200);

    QString str4=QString("START");
    QFont font4;
    font4.setFamily("宋体");
    font4.setPointSize(30);
    startBtn->move(this->width()*0.5-100,this->height()-200);
    startBtn->setText(str4);
    startBtn->setFont(font4);


    connect(startBtn,&QPushButton::clicked,[=](){
        mainwindow = new MainWindow();
        mainwindow->setGeometry(this->geometry());
        this->hide();
        mainwindow->show();
    });
}

void StartWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/icon/start_background");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
