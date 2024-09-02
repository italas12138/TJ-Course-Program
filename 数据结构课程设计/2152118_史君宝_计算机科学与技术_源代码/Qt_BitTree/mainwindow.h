#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QFileDevice>
#include <QTreeWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QRegExp>


#include "BitTree.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    BitTreeNode *head = new BitTreeNode();

    void paintEvent(QPaintEvent *)override;

    void cal_size();

private:
    Ui::MainWindow *ui;

    int Tree_num = 0;
    int Tree_Depth = 0;


    double size = 0;


private slots:

    void on_pushButtonSearch_clicked();

    void on_pushButtonInsert_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonFilein_clicked();


    void dataInsert(QString key);



};
#endif // MAINWINDOW_H
