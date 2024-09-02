#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QString>
#include <QComboBox>
#include <QToolButton>
#include <QFontComboBox>

class QLineEdit;
class QDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //成员变量
    QAction* NewFile;
    QAction* OpenFile;
    QAction* SaveFile;
    QAction* SaveOtherFile;


    QAction* CopyText;    //复制
    QAction* PasteText;   //粘贴
    QAction* CutText;     //剪切


    QAction* FindText;    //查找

    QAction* CountCharacters;
    QAction* CountNumber;
    QAction* CountSpace;
    QAction* CountChars;

    QAction* DeleteChars;

    QAction* FontSet;     //字体设置


    QLabel* fontTypeLabel;
    QFontComboBox* fontTypeCmb;

    QLabel* fontSizeLabel;
    QComboBox* fontSizeCmb;


    QTextEdit* textEdit;
    QTextCharFormat* tcf;

private:

    Ui::MainWindow *ui;

    //是否保存标志位
    bool Unsaved;

    //保存当前文件的路径
    QString curFile;

    //Dialog对话框
    QDialog *FindDia;
    //单行输入框
    QLineEdit *FindContent;


private slots:

    //创建菜单栏
    void Creat_Menu();
    //新文件
    void New_File();

    //判断是否需要保存
    bool maybeSave();

    //自定义槽函数-保存操作
    bool Save_File();

    //自定义槽函数-另存为操作
    bool Save_Other_File();

    //自定义槽函数-保存文件
    bool Save_File(const QString &fileName);

    //自定义槽函数-打开文件
    bool Open_File(const QString &fileName);

    //创建工具栏
    void Creat_Tool();
    //自定义槽函数-改变字体
    void Set_Font(const QFont &font);
    //自定义槽函数-改变字号
    void Set_FontSize(int index);
    //自定义槽函数-字体加粗

    //所有的信号与槽连接函数
    void connectImpl();

    //自定义槽函数-查找
    void Find_Text();

    void Count_characters();

    void Count_number();

    void Count_space();

    void Count_chars();

    void Delete_chars();

};
#endif // MAINWINDOW_H
