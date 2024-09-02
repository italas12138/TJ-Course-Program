#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList()<<QStringLiteral("id")<<QStringLiteral("data"));


    // 事实证明是可以的，将信号在顶层MainWindow中连接
    addChildNodeAction = new QAction("&添加子节点", this);
    deleteNodeAction = new QAction("&删除节点", this);
    connect(addChildNodeAction,SIGNAL(triggered()),this,SLOT(addChildNode()));
    connect(deleteNodeAction,SIGNAL(triggered()),this,SLOT(deleteNode()));
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(on_treeWidget_customContextMenuRequested(QPoint)));

    // 在listWidget中同步删除
    //connect(addChildNodeAction,SIGNAL(triggered()),ui->listWidget,SLOT(addNode())); // 对于列表来说没有addChildNode()
//    connect(deleteNodeAction,SIGNAL(triggered()),ui->listWidget,SLOT(deleteNode()));


    ui->tableWidget->setColumnCount(3); // 要写在setHorizontalHeaderLabels前面，否则行都会变成数字1 | 2 | 3
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("id")
                                               <<QStringLiteral("data")<<QStringLiteral("pid"));
    ui->tableWidget->setRowCount(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// 导入文件生成
void MainWindow::on_actionImportTxt_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "打开一个txt文件";
    QString filter = "(*.txt)";
    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if (aFileName.isEmpty())
        return;

    QFile  aFile(aFileName);
    if (!aFile.exists()) //文件不存在
        return;
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    //QByteArray line = aFile.readLine();
    //QString str(line);



/*
    //ui->textEdit->setPlainText(aFile.readAll());
    QByteArray line = aFile.readLine();
    QString str(line);

    str = str.trimmed();
    qDebug() << str;
    int n = str.toInt(); //个数
    Node *p = this->L;

    int i;
    qDebug() << "?" ;

    for (i = 0; i < n; i++) {
        qDebug() << "?";
        p->next = new Node();

        qDebug() << "?";
        p = p->next;
        line = aFile.readLine();
        QString str1(line);

        str1.trimmed();
        qDebug() << "?";
        p->id = str1.section(' ',0,0).toInt();
        p->pid = str1.section(' ',1,1).toInt();
        qDebug() << "?";
        qDebug() << p->id << ":" << p->pid;
    }
    p->next = NULL;
*/

    QByteArray line = aFile.readLine();
    QString str(line);
    int flag_root = 0;
    int rowCnt = 0;

    while (!aFile.atEnd()){
        QByteArray line = aFile.readLine();
        QString str(line);
        str = str.trimmed();

        QStringList sections = str.split(" ");
        // 找有没有id重复
        if(ui->treeWidget->findItems(sections[0], Qt::MatchRecursive,0).size()!=0){
            //错误提示
            QMessageBox msgBox(QMessageBox::Warning,"错误提示","id出现重复，请确认源文件！",0,this);
            msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
            //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
                if (msgBox.exec() == QMessageBox::AcceptRole){
                    qDebug() <<"init failed";

                    ui->treeWidget->clear();
                    ui->tableWidget->clear();
                    ui->tableWidget->setRowCount(0);//否则之后再导入数据会有问题

                    return;
                }
        }

        // 要求第一个必须是根节点，还没想好怎么处理第一个不是根节点的情况
        if(flag_root == 0){
            rowCnt = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCnt);
            ui->tableWidget->setItem(rowCnt,0,new QTableWidgetItem(sections[0]));
            ui->tableWidget->setItem(rowCnt,1,new QTableWidgetItem(sections[1]));
            ui->tableWidget->setItem(rowCnt,2,new QTableWidgetItem(sections[2]));
            //rowCnt++;

            //ui->tableWidget->addItem(new QTableWidgetItem(str));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,QStringList()<< sections[0]<<sections[1]);
            ui->treeWidget->insertTopLevelItem(0, root);
            flag_root = 1;
        }
        else {
            //ui->listWidget->addItem(new QListWidgetItem(str));
            // 找父节点
            rowCnt = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCnt);
            ui->tableWidget->setItem(rowCnt,0,new QTableWidgetItem(sections[0]));
            ui->tableWidget->setItem(rowCnt,1,new QTableWidgetItem(sections[1]));
            ui->tableWidget->setItem(rowCnt,2,new QTableWidgetItem(sections[2]));
            //rowCnt++;

            QList<QTreeWidgetItem *> QList = ui->treeWidget->findItems(sections[2], Qt::MatchRecursive, 0);
            if(QList.length() == 1){ // 有且唯一只有一个
                new QTreeWidgetItem(QList[0],QStringList()<< sections[0]<<sections[1]);
            }
            else{
                qDebug() << "Err";
            }
        }
        qDebug() << str;
    }

    aFile.close();
    ui->treeWidget->expandAll();
    //openTextByIODevice(aFileName);
}


bool MainWindow::addChildNode()
{
    qDebug() << "addChildNode";

    QInputDialog dia(this);
    dia.setFixedHeight(107);
    dia.setFixedWidth(800);
    dia.setWindowTitle("请输入节点信息");
    dia.setLabelText("id和data用空格分割，例如：9 def");
    dia.setInputMode(QInputDialog::TextInput);//可选参数：DoubleInput  TextInput




    if(dia.exec() == QInputDialog::Accepted){
       qDebug() << dia.textValue();
       QStringList sections = dia.textValue().trimmed().split(" ");
       if(sections.size()!=2){
           QMessageBox msgBox(QMessageBox::Warning,"错误提示","输入数据有误！",0,this);

           msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
           if (msgBox.exec() == QMessageBox::AcceptRole){
               qDebug() <<"addNode failed";
               return false;
           }
       }

       // 找有没有id重复
       if(ui->treeWidget->findItems(sections[0], Qt::MatchRecursive,0).size()!=0){
           //错误提示
           QMessageBox msgBox(QMessageBox::Warning,"错误提示","id出现重复，请确认id！",0,this);

           msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
           //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
               if (msgBox.exec() == QMessageBox::AcceptRole){
                   qDebug() <<"addNode failed";
                   return false;
               }
       }

       new QTreeWidgetItem(curItem,QStringList()<<sections[0]<<sections[1]);

       int rowCnt = ui->tableWidget->rowCount();
       qDebug() << "个数是" << rowCnt;
        ui->tableWidget->insertRow(rowCnt);
       ui->tableWidget->setItem(rowCnt,0,new QTableWidgetItem(sections[0]));
       ui->tableWidget->setItem(rowCnt,1,new QTableWidgetItem(sections[1]));
       ui->tableWidget->setItem(rowCnt,2,new QTableWidgetItem(curItem->text(0)));
       return true;
    }
    else {
        return false;
    }
}

bool MainWindow::deleteNode()
{
    /*
    qDebug() << "reNameNode" << endl;

    QInputDialog dia(this);
    dia.setWindowTitle("请输入想更改的data");
    dia.setLabelText("请输入想更改的data:");
    dia.setInputMode(QInputDialog::TextInput);//可选参数：DoubleInput  TextInput

    if(dia.exec() == QInputDialog::Accepted) {
       qDebug() << dia.textValue();
       curItem->setText(0,dia.textValue());
    }
    return true;*/

    qDebug() << "deleteNode";

   QTreeWidgetItem* parent = curItem->parent();
   if(parent == nullptr){

        qDebug() << "rootNode";
       ui->tableWidget->clear();
       ui->tableWidget->setRowCount(0);
       //得到索引
       /*
       int index = 0;
       int count =  ui->treeWidget->topLevelItemCount();
       for(int i = 0;i<count;i++){
           QTreeWidgetItem* temp =  ui->treeWidget->topLevelItem(i);
           if(curItem->data(0,Qt::UserRole).toString() == temp->data(0,Qt::UserRole).toString()){
               index = i;
           }
       }
       ui->treeWidget->takeTopLevelItem(index);
          */
       ui->treeWidget->clear();
   }
   else{
      /*
       //int rowCnt = ui->tableWidget->rowCount();
       QString index = curItem->text(0);

       int i = 0;
       while(i < ui->tableWidget->rowCount()){
           if(ui->tableWidget->item(i,0)->text() == index){ //获取pid
                ui->tableWidget->removeRow(i);
                continue;
           }

           if(ui->tableWidget->item(i,2)->text() == index){ //获取pid
                ui->tableWidget->removeRow(i);
           }
           else{
               i++;
           }
       }
*/
       //parent->children
       QStack <QTreeWidgetItem *> childStack;
        int childNum;

        childStack.push(curItem);
       //childNum = curItem->childCount();
       //for (int j = 0;j < childNum;j++) {
       //    childStack.push(curItem->child(j));
       //}

       QTreeWidgetItem * id;
       QString index;
       int iTableWidget;

       // 获取所有将要删除的table控件的id
       while(false == childStack.isEmpty()){
           id = childStack.pop();
            index = id->text(0);
           //在tableWidget对应删除
           int i = 0;
           while(i < ui->tableWidget->rowCount()){
               if(ui->tableWidget->item(i,0)->text() == index){
                    ui->tableWidget->removeRow(i);
               }
               else{
                   i++;
               }
           }

           //tableChildToBeDeleted.push_back(id->text(0));

           childNum = id->childCount();
           for (int j = 0;j < childNum;j++) {
               childStack.push(id->child(j));
           }

           iTableWidget = 0;
       }
        //QList<QTreeWidgetItem *> childList = parent->children;
       //QList<QString>::Iterator iter;
       //for(iter=tableChildToBeDeleted.begin();iter!=tableChildToBeDeleted.end();++iter){

       //}
       //for (ItitableChildToBeDeleted) {

       //}

       parent->removeChild(curItem);

       // list的都要删掉
   }
   return true;
   //删除数据库一行
   //curTtem->data
}

// 右键弹出菜单
void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    curItem = ui->treeWidget->itemAt(pos);  //获取当前被点击的节点

    //在空白位置点击，弹出菜单：添加根节点，删除所有模板。
    if(curItem == nullptr){
        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
        //popMenu->addAction(addRootNodeAction);
        //popMenu->addAction(deleteAllNodesAction);
        popMenu->exec(QCursor::pos());
    }
    else{
        QVariant var = curItem->data(0,Qt::UserRole);
        qDebug() << var.toString() << endl;
        qDebug() << "category";
        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
        popMenu->addAction(addChildNodeAction);
        popMenu->addAction(deleteNodeAction);
        popMenu->exec(QCursor::pos());
    }
}

