/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBoxData;
    QTableWidget *tableWidgetData;
    QGroupBox *groupBox_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonInsert;
    QPushButton *pushButtonDelete;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonClear;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelRoot;
    QLabel *labelNodenum;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonFilein;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEditRoot;
    QLineEdit *lineEditNodenum;
    QGroupBox *groupBox_tree;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBoxData = new QGroupBox(centralwidget);
        groupBoxData->setObjectName(QString::fromUtf8("groupBoxData"));
        groupBoxData->setGeometry(QRect(970, 360, 291, 381));
        tableWidgetData = new QTableWidget(groupBoxData);
        tableWidgetData->setObjectName(QString::fromUtf8("tableWidgetData"));
        tableWidgetData->setGeometry(QRect(0, 20, 281, 341));
        tableWidgetData->setRowCount(0);
        tableWidgetData->setColumnCount(0);
        groupBox_1 = new QGroupBox(centralwidget);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setGeometry(QRect(960, 0, 311, 161));
        verticalLayoutWidget = new QWidget(groupBox_1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 121, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonInsert = new QPushButton(verticalLayoutWidget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));

        verticalLayout->addWidget(pushButtonInsert);

        pushButtonDelete = new QPushButton(verticalLayoutWidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        verticalLayout->addWidget(pushButtonDelete);

        verticalLayoutWidget_2 = new QWidget(groupBox_1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(170, 30, 121, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonSearch = new QPushButton(verticalLayoutWidget_2);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));

        verticalLayout_2->addWidget(pushButtonSearch);

        pushButtonClear = new QPushButton(verticalLayoutWidget_2);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        verticalLayout_2->addWidget(pushButtonClear);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(960, 160, 311, 181));
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 101, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelRoot = new QLabel(verticalLayoutWidget_3);
        labelRoot->setObjectName(QString::fromUtf8("labelRoot"));

        verticalLayout_3->addWidget(labelRoot);

        labelNodenum = new QLabel(verticalLayoutWidget_3);
        labelNodenum->setObjectName(QString::fromUtf8("labelNodenum"));

        verticalLayout_3->addWidget(labelNodenum);

        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 120, 151, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonFilein = new QPushButton(horizontalLayoutWidget);
        pushButtonFilein->setObjectName(QString::fromUtf8("pushButtonFilein"));

        horizontalLayout->addWidget(pushButtonFilein);

        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(130, 20, 161, 91));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEditRoot = new QLineEdit(verticalLayoutWidget_4);
        lineEditRoot->setObjectName(QString::fromUtf8("lineEditRoot"));

        verticalLayout_4->addWidget(lineEditRoot);

        lineEditNodenum = new QLineEdit(verticalLayoutWidget_4);
        lineEditNodenum->setObjectName(QString::fromUtf8("lineEditNodenum"));

        verticalLayout_4->addWidget(lineEditNodenum);

        groupBox_tree = new QGroupBox(centralwidget);
        groupBox_tree->setObjectName(QString::fromUtf8("groupBox_tree"));
        groupBox_tree->setGeometry(QRect(0, 0, 950, 800));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxData->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        groupBox_1->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        labelRoot->setText(QCoreApplication::translate("MainWindow", "     \346\240\221\346\240\271\345\200\274", nullptr));
        labelNodenum->setText(QCoreApplication::translate("MainWindow", "     \347\273\223\347\202\271\346\225\260", nullptr));
        pushButtonFilein->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\257\274\345\205\245", nullptr));
        groupBox_tree->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
