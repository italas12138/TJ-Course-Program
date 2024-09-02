#include "TreeNodeButton.h"
#include "mainwindow.h"
#include <QDebug>


TreeNodeButton::TreeNodeButton(double size, QString imgPath)
{
    QPixmap pix;

    bool flag=pix.load(imgPath);
    if (!flag)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    this->setFixedSize(size, size);
    this->setStyleSheet("QPushButton{border:0px}");

    //设置图标
    this->setIconSize(QSize(size, size));
    this->setIcon(pix);
}



