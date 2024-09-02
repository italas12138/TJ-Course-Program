#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TreeNodeButton.h"

#include <queue>

#include <cmath>

#include "BitTree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,800);

    setWindowTitle("程序页面");

    ui->tableWidgetData->setColumnCount(1);
    ui->tableWidgetData->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
    ui->tableWidgetData->setRowCount(0);


    ui->lineEditRoot->setValidator(new QIntValidator(1,999,this));
    ui->lineEditNodenum->setValidator(new QIntValidator(1,999,this));

    ui->lineEditRoot->clear();
    ui->lineEditNodenum->clear();
    ui->lineEditRoot->setEnabled(false);
    ui->lineEditNodenum->setEnabled(false);

    ui->pushButtonInsert->setEnabled(true);
    ui->pushButtonSearch->setEnabled(false);
    ui->pushButtonDelete->setEnabled(false);
    ui->pushButtonClear->setEnabled(false);

    ui->pushButtonFilein->setEnabled(true);

    ui->lineEditRoot->setText("null");
    ui->lineEditNodenum->setText("0");

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonInsert_clicked()
{
    qDebug() << "pushButtonInsert";

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("插入");
    dia.setLabelText("请输入树的结点值：");

    dia.setInputMode(QInputDialog::TextInput);

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    qDebug() << dia.textValue();
    QString key = dia.textValue().trimmed();
    if(key == ""){
        QMessageBox msgBox(QMessageBox::Warning, "错误提示", "未输入数据", nullptr, this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Insert failed";
        }
        return;
    }

    int node_value = key.toInt();

    BitTreeNode *curNode = new BitTreeNode();
    BitTreeNode *parentNode = new BitTreeNode();

    bool isFailed = 0;

    if(!head->LeftChild){
        BitTreeNode *root = new BitTreeNode();
        root->NodeValue = node_value;
        root->ParentNode = head;
        head->LeftChild = root;
        head->LTag = 1;

        curNode = root;

        ui->pushButtonSearch->setEnabled(true);
        ui->pushButtonDelete->setEnabled(true);
        ui->pushButtonClear->setEnabled(true);

        ui->pushButtonFilein->setEnabled(true);

        ui->lineEditRoot->setText(QString::number(head->LeftChild->NodeValue));
        ui->lineEditNodenum->setText(QString::number(this->Tree_num+1));

    }
    else{
        curNode = head->LeftChild;
        while(curNode){
            if(node_value == curNode->NodeValue){
                isFailed = 1;
                break;
            }
            else if(node_value < curNode->NodeValue){
                if(curNode->LTag){
                    parentNode = curNode;
                    curNode = curNode->LeftChild;
                }
                else{
                    BitTreeNode *newNode = new BitTreeNode();
                    curNode -> LeftChild = newNode;
                    newNode -> ParentNode = curNode;
                    curNode -> LTag = 1;
                    newNode -> NodeValue = node_value;
                    break;
                }
            }
            else if(node_value > curNode->NodeValue){
                if(curNode->RTag){
                    parentNode = curNode;
                    curNode = curNode->RightChild;
                }
                else{
                    BitTreeNode *newNode = new BitTreeNode();
                    curNode -> RightChild = newNode;
                    newNode -> ParentNode = curNode;
                    curNode -> RTag = 1;
                    newNode -> NodeValue = node_value;
                    break;
                }
            }
        }
    }


    if(!isFailed){

        ui->tableWidgetData->setRowCount(this->Tree_num+1);

        ui->tableWidgetData->setItem(Tree_num, 0,new QTableWidgetItem(key));

        ++this->Tree_num;

        QMessageBox msgBox(QMessageBox::Information, "信息提示", "插入成功", nullptr, this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Insert success";
        }

        while(curNode!=head){
            int one = 1;
            int two = 1;


            if(curNode->LTag){
                one = curNode->LeftChild->Depth+1;
            }
            if(curNode->RTag){
                two = curNode->RightChild->Depth+1;
            }
            if(one>two){
                curNode->Depth = one;
            }
            else{
                curNode->Depth = two;
            }
            curNode = curNode->ParentNode;
        }

    }

    // 满了 无法再加
    if(isFailed){
        // 错误提示
        QMessageBox msgBox(QMessageBox::Warning, "错误提示", "该结点已存在", nullptr, this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Insert failed";
        }
        return;
    }

    ui->lineEditRoot->setText(QString::number(head->LeftChild->NodeValue));
    ui->lineEditNodenum->setText(QString::number(this->Tree_num));

    cal_size();

    return;
}


void MainWindow::on_pushButtonSearch_clicked()
{
    qDebug() << "pushByttonSearch";

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("查找");
    dia.setLabelText("请输入树的结点值：");
    dia.setInputMode(QInputDialog::TextInput);


    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    qDebug() << dia.textValue();

    QString key = dia.textValue().trimmed();

    if(key == ""){
        QMessageBox msgBox(QMessageBox::Warning, "错误提示", "未输入数据", nullptr, this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Search failed";
        }
        return;
    }

    int node_value = key.toInt();


    bool isFailed = 1;

    QTableWidgetItem *curItem;

    BitTreeNode *curNode = new BitTreeNode();

    QString str = "";

    if(head->LeftChild){
        curNode = head->LeftChild;
        str += "根节点，";
    }

     while(curNode){
         if(node_value == curNode->NodeValue){
             isFailed = 0;
             break;
         }
         else if(node_value < curNode->NodeValue){
             if(curNode->LTag){
                 curNode = curNode->LeftChild;
                 str += "左，";
             }
             else{
                 isFailed = 1;
                 break;
             }
         }
         else if(node_value > curNode->NodeValue){
             if(curNode->RTag){
                 curNode = curNode->RightChild;
                 str += "右，";
             }
             else{
                 isFailed = 1;
                 break;
             }
         }
     }

     if(!curNode || isFailed){
         QMessageBox msgBox(QMessageBox::Warning, "错误提示", "查找失败", nullptr, this);
         msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

         if(msgBox.exec() == QMessageBox::AcceptRole){
             qDebug() << "Search failed!";
         }
         if(msgBox.exec() == QMessageBox::ResetRole){
             return;
         }
         return;
     }

     QMessageBox msgBox(QMessageBox::Information, "查找提示", "查找成功 "+str, nullptr, this);
     msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

     if(msgBox.exec() == QMessageBox::AcceptRole){
         qDebug() << "Search success!";
     }
     return;
}


void MainWindow::on_pushButtonDelete_clicked()
{
    qDebug() << "pushButtonDelete";

    QInputDialog dia(this);
    dia.setFixedHeight(150);
    dia.setFixedWidth(800);
    dia.setWindowTitle("删除");
    dia.setLabelText("请输入树的结点值：");
    dia.setInputMode(QInputDialog::TextInput);


    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    qDebug() << dia.textValue();

    QString key = dia.textValue().trimmed();

    if(key == ""){
        QMessageBox msgBox(QMessageBox::Warning, "错误提示", "未输入数据", nullptr, this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Delete failed";
        }
        return;
    }

    int node_value = key.toInt();

    bool isFailed = 1;

    BitTreeNode *curNode;

    BitTreeNode *parentNode;

    curNode = head->LeftChild;

    while(curNode){
        if(node_value == curNode->NodeValue){
            isFailed = 0;
            if(!(curNode->LTag||curNode->RTag)){
                parentNode = curNode->ParentNode;
                if(curNode == head->LeftChild || node_value<parentNode->NodeValue){
                    parentNode->LeftChild = nullptr;
                    parentNode->LTag = 0;

                    while(parentNode!=head){
                        int one = 1;
                        int two = 1;
                        if(parentNode -> LTag){
                            one = parentNode->LeftChild->Depth+1;
                        }
                        if(parentNode -> RTag){
                            two = parentNode->RightChild->Depth+1;
                        }
                        if(one>two){
                            parentNode->Depth = one;
                        }
                        else{
                            parentNode->Depth = two;
                        }
                        parentNode = parentNode->ParentNode;
                    }

                }
                else{
                    parentNode->RightChild = nullptr;
                    parentNode->RTag = 0;

                    while(parentNode!=head){

                        int one = 1;
                        int two = 1;
                        if(parentNode -> LTag){
                            one = parentNode->LeftChild->Depth+1;
                        }
                        if(parentNode -> RTag){
                            two = parentNode->RightChild->Depth+1;
                        }
                        if(one>two){
                            parentNode->Depth = one;
                        }
                        else{
                            parentNode->Depth = two;
                        }
                        parentNode = parentNode->ParentNode;
                    }

                }
            }
            else if(curNode->LTag && curNode->RTag){
                BitTreeNode *maxNode = curNode->RightChild;
                while(maxNode->LeftChild){
                    maxNode = maxNode->LeftChild;
                }

                BitTreeNode *iNode = maxNode->ParentNode;



                if(maxNode->NodeValue < iNode->NodeValue){
                    if(maxNode->RTag){

                        iNode->LeftChild = maxNode->RightChild;
                        maxNode->RightChild->ParentNode = iNode;
                    }
                    else{
                        iNode->LeftChild = nullptr;
                        iNode->LTag = 0;
                    }
                }
                else{
                    if(maxNode->RTag){
                        maxNode->ParentNode->RightChild = maxNode->RightChild;
                        maxNode->RightChild->ParentNode = maxNode->ParentNode;
                    }
                    else{
                        maxNode->ParentNode->RightChild = nullptr;
                        maxNode->ParentNode->RTag = 0;
                    }
                }
                curNode->NodeValue = maxNode->NodeValue;

                while(iNode!=head){
                    int one = 1;
                    int two = 1;
                    if(iNode -> LTag){
                        one = iNode->LeftChild->Depth+1;
                    }
                    if(iNode -> RTag){
                        two = iNode->RightChild->Depth+1;
                    }
                    if(one>two){
                        iNode->Depth = one;
                    }
                    else{
                        iNode->Depth = two;
                    }
                    iNode = iNode->ParentNode;
                }
            }

            else if(curNode->LTag){
                BitTreeNode *iNode = curNode->ParentNode;

                if(curNode == head->LeftChild  || curNode->NodeValue < curNode->ParentNode->NodeValue){
                    curNode->ParentNode->LeftChild = curNode->LeftChild;
                    curNode->LeftChild->ParentNode = curNode->ParentNode;
                }
                else{
                    curNode->ParentNode->RightChild = curNode->LeftChild;
                    curNode->LeftChild->ParentNode = curNode->ParentNode;
                }
                while(iNode!=head){
                    int one = 1;
                    int two = 1;
                    if(iNode -> LTag){
                        one = iNode->LeftChild->Depth+1;
                    }
                    if(iNode -> RTag){
                        two = iNode->RightChild->Depth+1;
                    }
                    if(one>two){
                        iNode->Depth = one;
                    }
                    else{
                        iNode->Depth = two;
                    }
                    iNode = iNode->ParentNode;
                }

            }
            else if(curNode->RTag){
                BitTreeNode *iNode = curNode->ParentNode;
                if(curNode == head->LeftChild || curNode->NodeValue < curNode->ParentNode->NodeValue){
                    curNode->ParentNode->LeftChild = curNode->RightChild;
                    curNode->RightChild->ParentNode = curNode->ParentNode;
                }
                else{
                    curNode->ParentNode->RightChild = curNode->RightChild;
                    curNode->RightChild->ParentNode = curNode->ParentNode;
                }
                while(iNode!=head){
                    int one = 1;
                    int two = 1;
                    if(iNode -> LTag){
                        one = iNode->LeftChild->Depth+1;
                    }
                    if(iNode -> RTag){
                        two = iNode->RightChild->Depth+1;
                    }
                    if(one>two){
                        iNode->Depth = one;
                    }
                    else{
                        iNode->Depth = two;
                    }
                    iNode = iNode->ParentNode;
                }
            }

            break;
        }
        else if(node_value < curNode->NodeValue){
            if(curNode->LTag){
                curNode = curNode->LeftChild;
            }
            else{
                break;
            }
        }
        else if(node_value > curNode->NodeValue){
            if(curNode->RTag){
                curNode = curNode->RightChild;
            }
            else{
                break;
            }
        }
    }

    if(!curNode || isFailed){
        QMessageBox msgBox(QMessageBox::Warning, "错误提示", "删除失败", nullptr, this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

        if(msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() << "Delete failed!";
        }
        if(msgBox.exec() == QMessageBox::ResetRole){
            qDebug() << "Delete failed!";
        }
        return;
    }

    QMessageBox msgBox(QMessageBox::Information, "删除提示", "删除成功", nullptr, this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);

    if(msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() << "Delete success!";
    }

    int order = 0;
    QTableWidgetItem *curItem;
    curItem = ui->tableWidgetData->item(order, 0);

    while(order < this->Tree_num) {
        curItem = ui->tableWidgetData->item(order, 0);
        if(curItem && curItem->text()==tr("")){
            break;
        }
        else {
            if(curItem->text() == key){
                --this->Tree_num;
                for(int i = order; i < this->Tree_num; ++i){
                    ui->tableWidgetData->item(i, 0)->setText(ui->tableWidgetData->item(i+1, 0)->text());
                }
                ui->tableWidgetData->item(this->Tree_num, 0)->setText("");
                ui->tableWidgetData->setRowCount(this->Tree_num);
                break;
            }
            else {
                order++;
            }

        }
    }

    if(this->Tree_num == 0){
        ui->pushButtonInsert->setEnabled(true);
        ui->pushButtonSearch->setEnabled(false);
        ui->pushButtonDelete->setEnabled(false);
        ui->pushButtonClear->setEnabled(false);

        ui->pushButtonFilein->setEnabled(true);

        ui->lineEditRoot->setText("null");
        ui->lineEditNodenum->setText("0");
    }
    else{
        ui->lineEditRoot->setText(QString::number(head->LeftChild->NodeValue));
        ui->lineEditNodenum->setText(QString::number(this->Tree_num));
    }
    cal_size();

    return;
}


void MainWindow::on_pushButtonClear_clicked()
{
    if(Tree_num){
        qDebug() << "pushButtonClear";
        QMessageBox msgBox(QMessageBox::Warning, "清除提示", "请确认是否要清除二叉树？", nullptr, this);

        msgBox.addButton(tr("是"), QMessageBox::AcceptRole);

        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"Clear success";
            ui->tableWidgetData->clear();
            head->LeftChild = nullptr;
            this->Tree_num = 0;

            ui->tableWidgetData->setColumnCount(1);
            ui->tableWidgetData->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
            ui->tableWidgetData->setRowCount(0);


            ui->lineEditRoot->clear();
            ui->lineEditNodenum->clear();
            ui->lineEditRoot->setEnabled(true);
            ui->lineEditNodenum->setEnabled(true);

            ui->pushButtonInsert->setEnabled(true);
            ui->pushButtonSearch->setEnabled(false);
            ui->pushButtonDelete->setEnabled(false);
            ui->pushButtonClear->setEnabled(false);

            ui->pushButtonFilein->setEnabled(true);

            ui->lineEditRoot->setText("null");
            ui->lineEditNodenum->setText("0");

            ui->lineEditRoot->setEnabled(false);
            ui->lineEditNodenum->setEnabled(false);
        }
    }

    return;
}


void MainWindow::on_pushButtonFilein_clicked(){
    on_pushButtonClear_clicked();

    QString curPath = QDir::currentPath();
    QString flieTitle = "打开一个txt文件";
    QString filter = "(*.txt)";
    QString aFileName=QFileDialog::getOpenFileName(this, flieTitle, curPath, filter);
    if (aFileName.isEmpty())
        return;

    QFile aFile(aFileName);
    if (!aFile.exists()) //文件不存在
        return;
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    int flag = 0;



    while (!aFile.atEnd()){

        QByteArray line = aFile.readLine();
        QString str = line;
        QString key = str.trimmed();
        if(key != ""){

            flag = 1;

            ui->pushButtonInsert->setEnabled(true);
            ui->pushButtonSearch->setEnabled(true);
            ui->pushButtonDelete->setEnabled(true);
            ui->pushButtonClear->setEnabled(true);

            ui->pushButtonFilein->setEnabled(true);

        }
        if(flag){
            dataInsert(key);

        }
    }
    aFile.close();
}


void MainWindow::dataInsert(QString key)
{
    if(key == ""){
        return;
    }

    int node_value = key.toInt();

    BitTreeNode *curNode = new BitTreeNode();
    BitTreeNode *parentNode = new BitTreeNode();

    bool isFailed = 0;

    if(!head->LeftChild){
        BitTreeNode *root = new BitTreeNode();
        root->NodeValue = node_value;
        root->ParentNode = head;
        head->LeftChild = root;
        head->LTag = 1;

        curNode = root;

        ui->pushButtonSearch->setEnabled(true);
        ui->pushButtonDelete->setEnabled(true);
        ui->pushButtonClear->setEnabled(true);

        ui->pushButtonFilein->setEnabled(true);

    }
    else{
        curNode = head->LeftChild;
        while(curNode){
            if(node_value == curNode->NodeValue){
                isFailed = 1;

                break;
            }
            else if(node_value < curNode->NodeValue){
                if(curNode->LTag){
                    parentNode = curNode;
                    curNode = curNode->LeftChild;
                }
                else{
                    BitTreeNode *newNode = new BitTreeNode();
                    curNode -> LeftChild = newNode;
                    newNode -> ParentNode = curNode;
                    curNode -> LTag = 1;
                    newNode -> NodeValue = node_value;
                    break;
                }
            }
            else if(node_value > curNode->NodeValue){
                if(curNode->RTag){
                    parentNode = curNode;
                    curNode = curNode->RightChild;
                }
                else{
                    BitTreeNode *newNode = new BitTreeNode();
                    curNode -> RightChild = newNode;
                    newNode -> ParentNode = curNode;
                    curNode -> RTag = 1;
                    newNode -> NodeValue = node_value;
                    break;
                }
            }
        }
    }

    if(!isFailed){
        ui->tableWidgetData->setRowCount(this->Tree_num+1);

        ui->tableWidgetData->setItem(Tree_num, 0,new QTableWidgetItem(key));

        ++this->Tree_num;

        ui->lineEditRoot->setText(QString::number(head->LeftChild->NodeValue));
        ui->lineEditNodenum->setText(QString::number(this->Tree_num));

        while(curNode!=head){
            int one = 1;
            int two = 1;
            if(curNode->LTag){
                one = curNode->LeftChild->Depth+1;
            }
            if(curNode->RTag){
                two = curNode->RightChild->Depth+1;
            }
            if(one>two){
                curNode->Depth = one;
            }
            else{
                curNode->Depth = two;
            }
            curNode = curNode->ParentNode;
        }
        cal_size();

        return;
    }
}


void MainWindow::cal_size(){
    int sum = 1;

    if(head->LeftChild){
        for(int i=0; i<head->LeftChild->Depth-1; ++i){
            sum*=2;
        }

        size = 800/sum;

        if(size<800/Tree_num && head->LeftChild->Depth>=6)
            size = 800/Tree_num;
    }

    return;
}


void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPen pen(Qt::SolidLine);
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    BitTreeNode *iNode = head;

    int cur = 0;
    int sum = 1;

    if(iNode->LeftChild){

        iNode = iNode->LeftChild;

        iNode->set_addr(400,0);

        painter.drawEllipse(400-size/2, 0, size, size);//圆的半径为25
        painter.drawText(400-8, size/2+5, QString::number(iNode->NodeValue));


        BitTreeNode *bitnodelist[1000];

        bitnodelist[0] = iNode;

        if(iNode->Depth>=4)
        {
            while(cur<sum){
                if(cur!=0){

                    if(bitnodelist[cur] == bitnodelist[cur]->ParentNode->LeftChild){

                        double one;

                        if(bitnodelist[cur]->ParentNode->ParentNode == head)
                        {
                            one = 800;
                        }
                        else{
                            one = bitnodelist[cur]->ParentNode->ParentNode->x_addr;
                        }

                        double two = bitnodelist[cur]->ParentNode->x_addr;

                        QString str1 = QString::number(bitnodelist[cur]->NodeValue);

                        if(one>two){
                            bitnodelist[cur]->set_addr(two-(one-two)/2, bitnodelist[cur]->ParentNode->y_addr+size*2);
                            painter.drawEllipse(two-(one-two)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size*2, size, size);
                            painter.drawText(two-(one-two)/2-8, bitnodelist[cur]->ParentNode->y_addr+size*2+size/2+5, str1);
                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr-size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                        else{
                            bitnodelist[cur]->set_addr(two-(two-one)/2, bitnodelist[cur]->ParentNode->y_addr+size*2);
                            painter.drawEllipse(two-(two-one)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size*2, size, size);
                            painter.drawText(two-(two-one)/2-8, bitnodelist[cur]->ParentNode->y_addr+size*2+size/2+5, str1);
                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr-size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                    }

                    if(bitnodelist[cur] == bitnodelist[cur]->ParentNode->RightChild){

                        double one;

                        if(bitnodelist[cur]->ParentNode->ParentNode == head)
                        {
                            one = 800;
                        }
                        else{
                            one = bitnodelist[cur]->ParentNode->ParentNode->x_addr;
                        }

                        double two = bitnodelist[cur]->ParentNode->x_addr;

                        QString str1 = QString::number(bitnodelist[cur]->NodeValue);

                        if(one>two){
                            bitnodelist[cur]->set_addr(two+(one-two)/2, bitnodelist[cur]->ParentNode->y_addr+size*2);
                            painter.drawEllipse(two+(one-two)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size*2, size, size);
                            painter.drawText(two+(one-two)/2-8, bitnodelist[cur]->ParentNode->y_addr+size*2+size/2+5, str1);

                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr+size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                        else{
                            bitnodelist[cur]->set_addr(two+(two-one)/2, bitnodelist[cur]->ParentNode->y_addr+size*2);
                            painter.drawEllipse(two+(two-one)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size*2, size, size);
                            painter.drawText(two+(two-one)/2-8, bitnodelist[cur]->ParentNode->y_addr+size*2+size/2+5, str1);

                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr+size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                    }
                }

                if(bitnodelist[cur]->LTag){
                    bitnodelist[sum] = bitnodelist[cur]->LeftChild;
                    ++sum;
                }
                if(bitnodelist[cur]->RTag){
                    bitnodelist[sum] = bitnodelist[cur]->RightChild;
                    ++sum;
                }
                ++cur;
            }
        }
        else{
            while(cur<sum){
                if(cur!=0){

                    if(bitnodelist[cur] == bitnodelist[cur]->ParentNode->LeftChild){

                        double one;

                        if(bitnodelist[cur]->ParentNode->ParentNode == head)
                        {
                            one = 800;
                        }
                        else{
                            one = bitnodelist[cur]->ParentNode->ParentNode->x_addr;
                        }

                        double two = bitnodelist[cur]->ParentNode->x_addr;

                        QString str1 = QString::number(bitnodelist[cur]->NodeValue);

                        if(one>two){
                            bitnodelist[cur]->set_addr(two-(one-two)/2, bitnodelist[cur]->ParentNode->y_addr+size);
                            painter.drawEllipse(two-(one-two)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size, size, size);
                            painter.drawText(two-(one-two)/2-8, bitnodelist[cur]->ParentNode->y_addr+size+size/2+5, str1);
                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr-size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                        else{
                            bitnodelist[cur]->set_addr(two-(two-one)/2, bitnodelist[cur]->ParentNode->y_addr+size);
                            painter.drawEllipse(two-(two-one)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size, size, size);
                            painter.drawText(two-(two-one)/2-8, bitnodelist[cur]->ParentNode->y_addr+size+size/2+5, str1);
                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr-size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                    }

                    if(bitnodelist[cur] == bitnodelist[cur]->ParentNode->RightChild){

                        double one;

                        if(bitnodelist[cur]->ParentNode->ParentNode == head)
                        {
                            one = 800;
                        }
                        else{
                            one = bitnodelist[cur]->ParentNode->ParentNode->x_addr;
                        }

                        double two = bitnodelist[cur]->ParentNode->x_addr;

                        QString str1 = QString::number(bitnodelist[cur]->NodeValue);

                        if(one>two){
                            bitnodelist[cur]->set_addr(two+(one-two)/2, bitnodelist[cur]->ParentNode->y_addr+size);
                            painter.drawEllipse(two+(one-two)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size, size, size);
                            painter.drawText(two+(one-two)/2-8, bitnodelist[cur]->ParentNode->y_addr+size+size/2+5, str1);
                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr+size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                        else{
                            bitnodelist[cur]->set_addr(two+(two-one)/2, bitnodelist[cur]->ParentNode->y_addr+size);
                            painter.drawEllipse(two+(two-one)/2-size/2, bitnodelist[cur]->ParentNode->y_addr+size, size, size);
                            painter.drawText(two+(two-one)/2-8, bitnodelist[cur]->ParentNode->y_addr+size+size/2+5, str1);
                            painter.drawLine(bitnodelist[cur]->ParentNode->x_addr+size/2, bitnodelist[cur]->ParentNode->y_addr+size/2,
                                             bitnodelist[cur]->x_addr, bitnodelist[cur]->y_addr);
                        }
                    }
                }

                if(bitnodelist[cur]->LTag){
                    bitnodelist[sum] = bitnodelist[cur]->LeftChild;
                    ++sum;
                }
                if(bitnodelist[cur]->RTag){
                    bitnodelist[sum] = bitnodelist[cur]->RightChild;
                    ++sum;
                }
                ++cur;
            }
        }
    }
}

