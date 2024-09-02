/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidgetOpen;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cbBoxConflictMethod;
    QLineEdit *lEdtMod;
    QLineEdit *lEdtTableSize;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pBtnSetting;
    QPushButton *pBtnApply;
    QPushButton *pBtnImportTxt;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pBtnSearch;
    QPushButton *pBtnInsert;
    QVBoxLayout *verticalLayout;
    QPushButton *pBtnDelete;
    QPushButton *pBtnClear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(804, 428);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidgetOpen = new QTableWidget(groupBox_2);
        tableWidgetOpen->setObjectName(QString::fromUtf8("tableWidgetOpen"));

        gridLayout_2->addWidget(tableWidgetOpen, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cbBoxConflictMethod = new QComboBox(groupBox_3);
        cbBoxConflictMethod->addItem(QString());
        cbBoxConflictMethod->addItem(QString());
        cbBoxConflictMethod->setObjectName(QString::fromUtf8("cbBoxConflictMethod"));

        verticalLayout_2->addWidget(cbBoxConflictMethod);

        lEdtMod = new QLineEdit(groupBox_3);
        lEdtMod->setObjectName(QString::fromUtf8("lEdtMod"));

        verticalLayout_2->addWidget(lEdtMod);

        lEdtTableSize = new QLineEdit(groupBox_3);
        lEdtTableSize->setObjectName(QString::fromUtf8("lEdtTableSize"));

        verticalLayout_2->addWidget(lEdtTableSize);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pBtnSetting = new QPushButton(groupBox_3);
        pBtnSetting->setObjectName(QString::fromUtf8("pBtnSetting"));

        horizontalLayout_2->addWidget(pBtnSetting);

        pBtnApply = new QPushButton(groupBox_3);
        pBtnApply->setObjectName(QString::fromUtf8("pBtnApply"));

        horizontalLayout_2->addWidget(pBtnApply);

        pBtnImportTxt = new QPushButton(groupBox_3);
        pBtnImportTxt->setObjectName(QString::fromUtf8("pBtnImportTxt"));

        horizontalLayout_2->addWidget(pBtnImportTxt);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pBtnSearch = new QPushButton(groupBox);
        pBtnSearch->setObjectName(QString::fromUtf8("pBtnSearch"));

        verticalLayout_4->addWidget(pBtnSearch);

        pBtnInsert = new QPushButton(groupBox);
        pBtnInsert->setObjectName(QString::fromUtf8("pBtnInsert"));

        verticalLayout_4->addWidget(pBtnInsert);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pBtnDelete = new QPushButton(groupBox);
        pBtnDelete->setObjectName(QString::fromUtf8("pBtnDelete"));

        verticalLayout->addWidget(pBtnDelete);

        pBtnClear = new QPushButton(groupBox);
        pBtnClear->setObjectName(QString::fromUtf8("pBtnClear"));

        verticalLayout->addWidget(pBtnClear);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        splitter->addWidget(layoutWidget);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 804, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\223\210\345\270\214\350\241\250", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\206\262\347\252\201\350\247\243\345\206\263\346\226\271\346\263\225:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\231\244\347\225\231\344\275\231\346\225\260\346\263\225\346\250\241\346\225\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\223\210\345\270\214\350\241\250\351\225\277\345\272\246:", nullptr));
        cbBoxConflictMethod->setItemText(0, QCoreApplication::translate("MainWindow", "\345\274\200\346\224\276\345\256\232\345\235\200\346\263\225", nullptr));
        cbBoxConflictMethod->setItemText(1, QCoreApplication::translate("MainWindow", "\351\223\276\345\234\260\345\235\200\346\263\225", nullptr));

        pBtnSetting->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\224\271\350\256\276\347\275\256", nullptr));
        pBtnApply->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        pBtnImportTxt->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\345\257\274\345\205\245", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
        pBtnSearch->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        pBtnInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        pBtnDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pBtnClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
