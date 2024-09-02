#pragma execution_character_set("utf-8")

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

#define HASH_TABLE_SIZE  10

enum Conflict_Method{OPEN_ADDR = 1, LINK_ADDR};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void setMethod();

    void on_pBtnSearch_clicked();

    void on_pBtnDelete_clicked();

    void on_pBtnInsert_clicked();

    void on_pBtnClear_clicked();

    void on_pBtnSetting_clicked();

    void on_pBtnApply_clicked();

    void on_pBtnImportTxt_clicked();

private:
    Ui::MainWindow *ui;
    //QVector<Elemtype> elem;
    int conflictMethod;

    int tableSize;
    int mod;



};

#endif // MAINWINDOW_H
