#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QToolBar>

#include <QToolButton>
#include <QPushButton>

#include <QIcon>
#include <QLabel>

#include <QMessageBox>
#include <QFontComboBox>
#include <QComboBox>

#include <QDockWidget>
#include <QTextEdit>
#include <QPlainTextEdit>

#include <QDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTextCursor>
#include <QClipboard>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextCharFormat>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化文件为未保存状态

    Unsaved = true;
    curFile = tr("未命名.txt");

    setWindowTitle(curFile);
    this->setWindowIcon(QIcon(":/new/icon/title.png"));

    tcf = new QTextCharFormat;

    Creat_Menu();
    Creat_Tool();

    connectImpl();

    //点击查找后显示的窗口
    FindDia = new QDialog(this);
    FindDia->setWindowTitle(tr("查找"));
    FindContent = new QLineEdit(FindDia);
    QPushButton *nextbutton= new QPushButton(tr("查找下一个"), FindDia);
    //垂直布局
    QVBoxLayout *layout= new QVBoxLayout(FindDia);
    layout->addWidget(FindContent);
    layout->addWidget(nextbutton);

    //将“查找下一个”按钮与自定义Find_Text槽函数连接
    connect(nextbutton, &QPushButton::clicked, this, &MainWindow::Find_Text);
}


void MainWindow::Creat_Menu()
{
    //获取菜单栏
    QMenuBar *menuBar = this->menuBar();

    //定义文件菜单和编辑菜单
    QMenu* FileMenu = menuBar->addMenu("文件");
    QMenu* UseMenu = menuBar->addMenu("功能");
    QMenu* SetMenu = menuBar->addMenu("设置");

    //向文件菜单中添加行为
    NewFile = FileMenu->addAction(QIcon(":/new/icon/newfile.png"),"新建");
    OpenFile = FileMenu->addAction(QIcon(":/new/icon/openfile.png"),"打开");
    SaveFile = FileMenu->addAction(QIcon(":/new/icon/savefile.png"),"保存");
    SaveOtherFile = FileMenu->addAction(QIcon(":/new/icon/saveas.png"),"另存为");


    //向功能菜单中添加行为
    CopyText = UseMenu->addAction(QIcon(":/new/icon/copy.png"),"复制");
    PasteText = UseMenu->addAction(QIcon(":/new/icon/paste.png"),"粘贴");
    CutText = UseMenu->addAction(QIcon(":/new/icon/cut.png"),"剪切");
    UseMenu->addSeparator();
    FindText = UseMenu->addAction(QIcon(":/new/icon/find.png"),"查找");
    UseMenu->addSeparator();
    CountCharacters = UseMenu->addAction("统计文字");
    CountNumber = UseMenu->addAction("统计数字");
    CountSpace = UseMenu->addAction("统计空格");
    CountChars = UseMenu->addAction("统计字符串");
    UseMenu->addSeparator();
    DeleteChars = UseMenu->addAction("删除字符串");


    //向设置菜单中添加行为
    FontSet = SetMenu->addAction(QIcon(":/new/icon/fontSet.png"),"字体设置");

    return;
}


void MainWindow::Creat_Tool()
{
    //添加工具栏
    QToolBar* toolBar = this->addToolBar("tool");

    //工具栏添加新建、打开、保存、另存为
    toolBar->addAction(NewFile);
    toolBar->addSeparator();
    toolBar->addAction(OpenFile);
    toolBar->addSeparator();
    toolBar->addAction(SaveFile);
    toolBar->addSeparator();
    toolBar->addAction(SaveOtherFile);
    toolBar->addSeparator();

    //工具栏添加复制、剪切、粘贴、查找、字体设置
    toolBar->addAction(CopyText);
    toolBar->addSeparator();
    toolBar->addAction(PasteText);
    toolBar->addSeparator();
    toolBar->addAction(CutText);
    toolBar->addSeparator();
    toolBar->addAction(FindText);
    toolBar->addSeparator();


    //设置“字体”标签
    fontTypeLabel = new QLabel("字体：");
    toolBar->addWidget(fontTypeLabel);
    //添加字体框
    fontTypeCmb = new QFontComboBox;
    toolBar->addWidget(fontTypeCmb);

    toolBar->addSeparator();

    //设置“字号”标签
    fontSizeLabel = new QLabel("字号：");
    toolBar->addWidget(fontSizeLabel);
    //添加字号框
    fontSizeCmb = new QComboBox;
    toolBar->addWidget(fontSizeCmb);
    //字号框中添加字号选项

    for(int i=1;i<=72;i++){
        fontSizeCmb->addItem(QString::number(i));
    }
    toolBar->addSeparator();


    textEdit = new QTextEdit;
    this->setCentralWidget(textEdit);

}


bool MainWindow::maybeSave(){
    //如果文档被更改了
    if(textEdit->document()->isModified()){
        //自定义一个警告对话框
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr(" 尚未保存，是否保存？"));
        QPushButton *yesBtn = box.addButton(tr("是(&Y)"),QMessageBox::YesRole);
        box.addButton(tr("否(&N)"),QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
            return Save_File();

        else if(box.clickedButton()==cancelBtn)
            return false;
    }
    //如果文档没被修改，则返回true
    return true;
}


//槽函数实现-新建文件
void MainWindow::New_File()
{
  if(maybeSave()){
      Unsaved = true;
      curFile = tr("未命名.txt");
      setWindowTitle(curFile);
      textEdit->clear();
  }
}


bool MainWindow::Save_File()
{
    if(Unsaved){
        return Save_Other_File();
    }else {
        return Save_File(curFile);
    }
}


bool MainWindow::Save_Other_File()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(fileName.isEmpty())
        return false;
    return Save_File(fileName);
}


bool MainWindow::Save_File(const QString &fileName)
{
    QFile aFile(fileName);
    if(aFile.open(QIODevice::ReadWrite)){
           QTextStream fin(&aFile);
           fin<<textEdit->toPlainText();
     }
    else{
           qDebug()<<"save file failed!";
           return false;
    }
    Unsaved = false;
    //获得文件的标准路径
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}


//槽函数实现-打开文件
bool MainWindow::Open_File(const QString &FileName)
{
    QFile aFile(FileName);
    if(aFile.open(QIODevice::ReadWrite)){
           QTextStream fout(&aFile);
           textEdit->setText(fout.readAll());
     }
    else{
           qDebug()<<"open file failed!";
           return false;
    }
    curFile = QFileInfo(aFile).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}


//槽函数实现-显示查找到的文本
void MainWindow::Find_Text()
{
    //获得对话框的内容
    QString findcontent = FindContent->text();
    //查找下一个
    if(textEdit->find(findcontent,QTextDocument::FindBackward|QTextDocument::FindCaseSensitively))
    {
        //找到后高亮显示
        QPalette palette = textEdit->palette();
        palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        textEdit->setPalette(palette);
    }
    else {
        QMessageBox::warning(this,tr("错误"),tr("没有找到内容"),QMessageBox::Ok);
    }
}


//槽函数实现-字体改变
void MainWindow::Set_Font(const QFont &font)
{
   QTextCursor cursor = textEdit->textCursor();

   // 获取当前选中文字的字体和字号
   QTextCharFormat currentFormat = cursor.charFormat();
   QFont currentFont = currentFormat.font();
   qreal currentFontSize = currentFont.pointSizeF();

   // 设置新的字体
   QFont newFont = font;
   newFont.setPointSizeF(currentFontSize);
   tcf->setFont(newFont);
   textEdit->mergeCurrentCharFormat(*tcf);
}


//槽函数实现-字号改变
void MainWindow::Set_FontSize(int index)
{
    tcf->setFontPointSize(double(index));
    textEdit->mergeCurrentCharFormat(*tcf);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectImpl()
{

    //信号与槽-新建文件
    connect(NewFile, &QAction::triggered,this, &MainWindow::New_File);

    //信号与槽-打开文件
    connect(OpenFile,&QAction::triggered,[=]{
        if(maybeSave()){
            QString fileName = QFileDialog::getOpenFileName(this);

            if(!fileName.isEmpty()){
                Open_File(fileName);
            }
        }
    });

    connect(CountCharacters,&QAction::triggered,this,&MainWindow::Count_characters);
    connect(CountNumber,&QAction::triggered,this,&MainWindow::Count_number);
    connect(CountSpace,&QAction::triggered,this,&MainWindow::Count_space);
    connect(CountChars,&QAction::triggered,this,&MainWindow::Count_chars);
    connect(DeleteChars,&QAction::triggered,this,&MainWindow::Delete_chars);

    //信号与槽-文件另存为
    connect(SaveOtherFile,&QAction::triggered,this,&MainWindow::Save_Other_File);

    //信号与槽-复制 QTextEdit自带的copy()槽函数
    connect(CopyText,&QAction::triggered,textEdit,&QTextEdit::copy);

    //信号与槽-剪切 QTextEdit自带的cut()槽函数
    connect(CutText,&QAction::triggered,textEdit,&QTextEdit::cut);

    //信号与槽-粘贴 QTextEdit自带的paste()槽函数
    connect(PasteText,&QAction::triggered,textEdit,&QTextEdit::paste);

    //信号与槽-搜索
    connect(FindText,&QAction::triggered,[=]{
        FindDia->show();
    });

    //信号与槽-字体设置
    connect(FontSet,&QAction::triggered,[=]{
      bool fontSelected;
      QFont font = QFontDialog::getFont(&fontSelected,this);
      if(fontSelected){
          textEdit->setFont(font);
      }
    });


    connect(fontTypeCmb,&QFontComboBox::currentFontChanged,this, &MainWindow::Set_Font);


    void (QComboBox::*p)(int)=&QComboBox::currentIndexChanged;

    connect(fontSizeCmb,p,this,&MainWindow::Set_FontSize);

}


void MainWindow::Count_characters()
{

    textEdit->moveCursor(QTextCursor::End);

    int sum = 0;

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("计数");
    dia.setLabelText("请输入要计数的文字：");
    dia.setInputMode(QInputDialog::TextInput);

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    QString findcontent = dia.textValue().trimmed();


    while(textEdit->find(findcontent,QTextDocument::FindBackward|QTextDocument::FindCaseSensitively)){
        ++sum;
    }

    QString str = QString::number(sum);


    QMessageBox msgBox(QMessageBox::Information, "结果提示", QString("%1" "%2" "%3").arg(findcontent, "的个数为",str), nullptr, this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"Count success";
    }

    return;
}


void MainWindow::Count_number()
{

    textEdit->moveCursor(QTextCursor::End);

    int sum = 0;

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("计数");
    dia.setLabelText("请输入要计数的数字：");
    dia.setInputMode(QInputDialog::TextInput);

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    QString findcontent = dia.textValue().trimmed();


    while(textEdit->find(findcontent,QTextDocument::FindBackward|QTextDocument::FindCaseSensitively)){
        ++sum;
    }

    QString str = QString::number(sum);

    QMessageBox msgBox(QMessageBox::Information, "结果提示", QString("%1" "%2""%3").arg(findcontent, "的个数为", str), nullptr, this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"Count success";
    }

    return;
}


void MainWindow::Count_chars()
{

    textEdit->moveCursor(QTextCursor::End);

    int sum = 0;

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("计数");
    dia.setLabelText("请输入要计数的字符串：");
    dia.setInputMode(QInputDialog::TextInput);

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    QString findcontent = dia.textValue().trimmed();


    while(textEdit->find(findcontent,QTextDocument::FindBackward|QTextDocument::FindCaseSensitively)){
        ++sum;
    }

    QString str = QString::number(sum);

    QMessageBox msgBox(QMessageBox::Information, "结果提示", QString("%1" "%2" "%3").arg(findcontent, "字符串的个数为", str), nullptr, this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"Count success";
    }

    return;
}


void MainWindow::Count_space()
{
    textEdit->moveCursor(QTextCursor::End);

    int sum = 0;

    QString findcontent =" ";


    while(textEdit->find(findcontent,QTextDocument::FindBackward|QTextDocument::FindCaseSensitively)){
        ++sum;
    }

    QString str = QString::number(sum);

    QMessageBox msgBox(QMessageBox::Information, "结果提示", QString("%1" "%2").arg("空格的个数为", str), nullptr, this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"Count success";
    }

    return;
}


void MainWindow::Delete_chars()
{

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("计数");
    dia.setLabelText("请输入要删除的字符串：");
    dia.setInputMode(QInputDialog::TextInput);

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    QString findcontent = dia.textValue().trimmed();

    QString plainText = textEdit->toPlainText();

    int len1 = plainText.size();
    int len2 = findcontent.size();

    int isFailed = 0;
    if(len1<len2)
    {
        QMessageBox msgBox(QMessageBox::Information, "结果提示", "删除失败", nullptr, this);

        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Delete failed";
        }
        return;
    }

    QVector <int> array;
    QString result ="";

    array.push_back(-len2);

    for(int i=0; i<=len1-len2;++i){
        isFailed = 0;
        for(int j=0;j<len2;++j){
            if(plainText[i+j] != findcontent[j]){
                isFailed = 1;
                break;
            }
        }
        if(!isFailed){
            array.push_back(i);
            i+=len2-1;
        }
    }
    array.push_back(len1);


    for(int i=0;i<array.size()-1;++i){
        for(int j=array[i]+len2; j<array[i+1];++j)
            result+=plainText[j];
    }

    textEdit->setText(result);

    QMessageBox msgBox(QMessageBox::Information, "结果提示", "删除成功", nullptr, this);

    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"Delete success";
    }

    return;

}
