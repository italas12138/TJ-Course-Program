#include "mytreewidget.h"


myTreeWidget::myTreeWidget(QWidget* parent): // 要去掉=0,声明中已经有了
    QTreeWidget(parent)
{


    addChildNodeAction = new QAction("&addChildNode", this);
    deleteNodeAction = new QAction("&deleteNode", this);

    // 把信号的连接放到mainwindow的构造函数中去试试
    //connect(addChildNodeAction,SIGNAL(triggered()),this,SLOT(addChildNode()));
    //connect(deleteNodeAction,SIGNAL(triggered()),this,SLOT(deleteNode()));
    //connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(on_treeWidget_customContextMenuRequested(QPoint)));

    // try 将tree的操作信号和table连在一起
    // connect(deleteNodeAction,SIGNAL(triggered()),this,SLOT(deleteNode()));
    //为什么下面两行代码不起作用
   // setColumnCount(2);
   // setHeaderLabels(QStringList()<<QStringLiteral("id")<<QStringLiteral("data"));
}


bool myTreeWidget::addChildNode()
{
    qDebug() << "addChildNode";

    QInputDialog dia(this);
    dia.setWindowTitle("Input Dialog");
    dia.setLabelText("Please input id:");
    dia.setInputMode(QInputDialog::TextInput);//可选参数：DoubleInput  TextInput



    if(dia.exec() == QInputDialog::Accepted){
       qDebug() << dia.textValue();
       new QTreeWidgetItem(curItem,QStringList()<<dia.textValue()<<"data");

       return true;
    }
    else {
        return false;
    }
}

bool myTreeWidget::deleteNode()
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
       //得到索引
       int index = 0;
       int count = this->topLevelItemCount();
       for(int i = 0;i<count;i++){
           QTreeWidgetItem* temp = this->topLevelItem(i);
           if(curItem->data(0,Qt::UserRole).toString() == temp->data(0,Qt::UserRole).toString()){
               index = i;
           }
       }
       this->takeTopLevelItem(index);
   }
   else
       parent->removeChild(curItem);

   return true;
   //删除数据库一行
   //curTtem->data
}

// 右键弹出菜单
void myTreeWidget::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    curItem= this->itemAt(pos);  //获取当前被点击的节点

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
