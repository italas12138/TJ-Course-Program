#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableWidgetOpen->setColumnCount(1); // 要写在setHorizontalHeaderLabels前面，否则行都会变成数字1 | 2 | 3
    ui->tableWidgetOpen->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
    ui->tableWidgetOpen->setRowCount(0);

    //ui->tableWidgetLink->setColumnCount(1); // 要写在setHorizontalHeaderLabels前面，否则行都会变成数字1 | 2 | 3
    //ui->tableWidgetLink->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
    //ui->tableWidgetLink->setRowCount(0);

    //QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");QRegExpValidator(regxp,this)//正则表达式，第一位数字为a-z的数字，第二位为1-9的数字，后边是0-2位0-9的数字
    ui->lEdtMod->setValidator(new QIntValidator(1,999,this));
    ui->lEdtTableSize->setValidator(new QIntValidator(1,999,this));

    ui->lEdtMod->clear();
    ui->lEdtTableSize->clear();
    ui->lEdtMod->setEnabled(true);
    ui->lEdtTableSize->setEnabled(true);
    ui->cbBoxConflictMethod->setEditable(true);

    ui->pBtnApply->setEnabled(true);
    ui->pBtnImportTxt->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBtnSearch_clicked()
{
    qDebug() << "pBtnSearch";

    QInputDialog dia(this);
    dia.setFixedHeight(107);
    dia.setFixedWidth(800);
    dia.setWindowTitle("搜索");
    dia.setLabelText("请输入关键字：");
    dia.setInputMode(QInputDialog::TextInput);//可选参数：DoubleInput  TextInput


    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    qDebug() << dia.textValue();
    QString key = dia.textValue().trimmed();
    int addr = key.toInt() % this->mod;
    int cnt = 0;
    bool isFailed = 0;

    //QStringList sections = dia.textValue().trimmed().split(" ");
     QTableWidgetItem *curItem;

     switch (conflictMethod) {
     case OPEN_ADDR:
         while(cnt < this->tableSize) {
              curItem = ui->tableWidgetOpen->item(addr,0);
             if(curItem == nullptr ||
                   (curItem && curItem->text()==tr(""))){
                 //ui->tableWidgetOpen->setItem(addr,0,new QTableWidgetItem(key));
                 isFailed = 1;
                 break;
             }
             else {
                 if(curItem->text()==key){
                     qDebug() << "search success";
                     isFailed = 0;
                     break;
                 }
                 else {
                     addr = (addr + 1) % mod;
                     cnt++;
                     qDebug() << "Open addressing";
                 }
             }
         }
         break;
     case LINK_ADDR:
         while(1) {
             curItem = ui->tableWidgetOpen->item(addr,cnt);
             if(curItem == nullptr ||
                   (curItem && curItem->text()==tr(""))){
                 isFailed = 1;
                 break;
             }
             else {
                 if(curItem->text() == key){
                     qDebug() << "search success";
                     isFailed = 0;
                     break;
                 }
                 else {
                     cnt++;
                     qDebug() << "Link addressing";
                 }
             }
         }// end of while

         break;

     }


    // 满了 无法再加
    if(cnt >= this->tableSize || isFailed){
        // 错误提示
        QMessageBox msgBox(QMessageBox::Warning,"错误提示","查找失败",nullptr,this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
        //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
        if (msgBox.exec() == QMessageBox::AcceptRole){
            qDebug() <<"search failed";
        }
        return;
    }

    QMessageBox msgBox(QMessageBox::Information,"查找结果提示","查找成功",nullptr,this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
    //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"search success";
    }
    return;

}

void MainWindow::on_pBtnDelete_clicked()
{
    qDebug() << "pBtnDelete";

    QInputDialog dia(this);
    dia.setFixedHeight(107);
    dia.setFixedWidth(800);
    dia.setWindowTitle("删除");
    dia.setLabelText("请输入关键字：");
    dia.setInputMode(QInputDialog::TextInput);//可选参数：DoubleInput  TextInput

    int cnt = 0;
    bool isFailed = 0;

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    qDebug() << dia.textValue();
    QString key = dia.textValue().trimmed();
    int addr = key.toInt() % this->mod;
     QTableWidgetItem *curItem;

     switch (this->conflictMethod) {
     case OPEN_ADDR:
         while(cnt < this->tableSize) {
              curItem = ui->tableWidgetOpen->item(addr,0);
             if(curItem == nullptr ||
                   (curItem && curItem->text()==tr(""))){
                 //ui->tableWidgetOpen->setItem(addr,0,new QTableWidgetItem(key));
                 isFailed = 1;
                 break;
             }
             else {
                 if(curItem->text()==key){
                     curItem->setText("");
                     //如果之后有
                     qDebug() << "delete success";
                     isFailed = 0;
                     break;
                 }
                 else {
                     addr = (addr + 1) % mod;
                     cnt++;
                     qDebug() << "Open addressing";
                 }

             }
         }
         break; // of case
     case LINK_ADDR:
         while(1) {
              curItem = ui->tableWidgetOpen->item(addr,cnt);
             if(curItem == nullptr ||
                   (curItem && curItem->text()==tr(""))){
                 isFailed = 1;
                 break;
             }
             else {
                 if(curItem->text()==key){
                     curItem->setText("");
                     qDebug() << "delete success";
                     int numColumn = ui->tableWidgetOpen->columnCount();

                     // 链表后面的往前移动
                     int i;
                     for(i = cnt;i < numColumn - 1;i++){
                         if(ui->tableWidgetOpen->item(addr, i+1)){
                             ui->tableWidgetOpen->
                                     setItem(addr, i, ui->tableWidgetOpen->item(addr, i+1)->clone());
                         }
                         else {
                            break;
                         }
                     }
                     ui->tableWidgetOpen->takeItem(addr, i);

                     isFailed = 0;
                     break;
                 }
                 else {
                     cnt++;
                     qDebug() << "Link addressing";
                 }

             }
         }
         break;
     } // end of switch


    // 满了 无法再加
    if(cnt >= this->tableSize || isFailed){
        // 错误提示
        QMessageBox msgBox(QMessageBox::Warning,"错误提示","删除失败",nullptr,this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
        //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
            if (msgBox.exec() == QMessageBox::AcceptRole){
                qDebug() <<"delete failed";
            }
        return;
    }

    QMessageBox msgBox(QMessageBox::Information,"查找结果提示","删除成功",nullptr,this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
    //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"delete success";
    }
    return;
}

void MainWindow::on_pBtnInsert_clicked()
{
    qDebug() << "pBtnSearch";

    QInputDialog dia(this);
    dia.setFixedHeight(107);
    dia.setFixedWidth(800);
    dia.setWindowTitle("插入");
    dia.setLabelText("请输入关键字：");
    dia.setInputMode(QInputDialog::TextInput);//可选参数：DoubleInput  TextInput

    if(dia.exec() != QInputDialog::Accepted){
       return;
    }

    qDebug() << dia.textValue();
    QString key = dia.textValue().trimmed();
    int addr = key.toInt() % this->mod;
    QTableWidgetItem *curItem;
    int cnt = 0;
    bool isFailed = 1;

    switch (this->conflictMethod) {
    case OPEN_ADDR:
        while(cnt < this->tableSize) {
             curItem = ui->tableWidgetOpen->item(addr,0);
            if(curItem == nullptr ||
                  (curItem && curItem->text()==tr(""))){
                ui->tableWidgetOpen->setItem(addr,0,new QTableWidgetItem(key));
                isFailed = 0;
                break;
            }
            else {
                if(curItem->text()==key){
                    qDebug() << "insert failed(exist)";
                    isFailed = 1;
                    break;
                }
                else {
                    addr = (addr + 1) % mod;
                    cnt++;
                    qDebug() << "Open addressing";
                }

            }
        }
        if(cnt >= this->tableSize){
            QMessageBox msgBox(QMessageBox::Warning,"错误提示","哈希表空间不足",nullptr,this);
            msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
            if (msgBox.exec() == QMessageBox::AcceptRole){
                qDebug() <<"insert failed";
            }
            return;
        }
        break;
    case LINK_ADDR:
        while(1) {
             curItem = ui->tableWidgetOpen->item(addr,cnt);
            if(curItem == nullptr ||
                  (curItem && curItem->text()==tr(""))){

                if(cnt+1 > ui->tableWidgetOpen->columnCount())
                    ui->tableWidgetOpen->setColumnCount(cnt+1);
                ui->tableWidgetOpen->setItem(addr,cnt,new QTableWidgetItem(key));
                isFailed = 0;
                break;
            }
            else {
                if(curItem->text()==key){
                    qDebug() << "insert failed(exist)";
                    isFailed = 1;
                    break;
                }
                else {
                    //addr = (addr + 1) % mod;
                    cnt++;
                    qDebug() << "Link addressing";
                }
            }
        }
        break;

    } // end of switch

    // 满了 无法再加
    if(isFailed){
        // 错误提示
        QMessageBox msgBox(QMessageBox::Warning,"错误提示","关键字已存在",nullptr,this);
        msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
        //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
            if (msgBox.exec() == QMessageBox::AcceptRole){
                qDebug() <<"insert failed";
            }
        return;
    }

    QMessageBox msgBox(QMessageBox::Information,"结果提示","插入成功",nullptr,this);
    msgBox.addButton(tr("我知道了"), QMessageBox::AcceptRole);
    //msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"insert success";
    }
    return;
}

void MainWindow::on_pBtnClear_clicked()
{
    qDebug() << "pBtnClear";
    QMessageBox msgBox(QMessageBox::Warning,"提示","请确认是否要清除哈希表？",nullptr,this);
    msgBox.addButton(tr("是"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("否"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole){
        qDebug() <<"clear";
        ui->tableWidgetOpen->clear();
        this->mod = -1;
        this->tableSize = -1;
        ui->tableWidgetOpen->setColumnCount(1); // 要写在setHorizontalHeaderLabels前面，否则行都会变成数字1 | 2 | 3
        ui->tableWidgetOpen->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
        ui->tableWidgetOpen->setRowCount(0);


        ui->lEdtMod->clear();
        ui->lEdtTableSize->clear();
        ui->lEdtMod->setEnabled(true);
        ui->lEdtTableSize->setEnabled(true);
    }


    return;
}

void MainWindow::on_pBtnSetting_clicked()
{
    qDebug() << "setting";
    QMessageBox msgBox(QMessageBox::Warning,"提示","如果更改设置，将清空哈希表！",nullptr,this);
    msgBox.addButton(tr("是，更改设置"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("取消"), QMessageBox::RejectRole);
    if (msgBox.exec() != QMessageBox::AcceptRole){
        return;
    }
    qDebug() <<"clear table";
    ui->tableWidgetOpen->clear();
    this->mod = -1;
    this->tableSize = -1;
    ui->tableWidgetOpen->setColumnCount(1); // 要写在setHorizontalHeaderLabels前面，否则行都会变成数字1 | 2 | 3
    ui->tableWidgetOpen->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
    ui->tableWidgetOpen->setRowCount(0);

    ui->lEdtMod->clear();
    ui->lEdtTableSize->clear();
    ui->lEdtMod->setEnabled(true);
    ui->lEdtTableSize->setEnabled(true);
    ui->cbBoxConflictMethod->setEditable(true);

    ui->pBtnImportTxt->setEnabled(false);
    ui->pBtnApply->setEnabled(true);
    return;
}

void MainWindow::on_pBtnApply_clicked()
{
    qDebug() << "apply setting?";
    QMessageBox msgBox(QMessageBox::Warning,"确认应用设置吗？","若想再次更改，将清空哈希表",nullptr,this);
    msgBox.addButton(tr("是，应用设置"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("取消"), QMessageBox::RejectRole);
    if (msgBox.exec() != QMessageBox::AcceptRole){
        return;
    }
    qDebug() <<"apply setting";


    this->tableSize= ui->lEdtTableSize->text().toInt();
    this->mod = ui->lEdtMod->text().toInt();
    qDebug() << "哈希表大小 " << this->tableSize;
    qDebug() << "除留余数法模数 " << this->mod;
    if(this->tableSize <= 0 || this->mod <= 0){
        QMessageBox msgBox(QMessageBox::Warning,"错误提示","设置值不合法",nullptr,this);
        msgBox.addButton(tr("好，我知道了"), QMessageBox::AcceptRole);
        msgBox.exec();
        ui->lEdtMod->clear();
        ui->lEdtTableSize->clear();

        ui->lEdtMod->setEnabled(true);
        ui->lEdtTableSize->setEnabled(true);
        ui->pBtnImportTxt->setEnabled(false);
        ui->pBtnApply->setEnabled(true);
        return;

    }

    if(this->tableSize < this->mod){
        QMessageBox msgBox(QMessageBox::Warning,"错误提示","哈希表长度必须比模数大！",nullptr,this);
        msgBox.addButton(tr("好，我知道了"), QMessageBox::AcceptRole);
        msgBox.exec();
        ui->lEdtMod->clear();
        ui->lEdtTableSize->clear();

        ui->lEdtMod->setEnabled(true);
        ui->lEdtTableSize->setEnabled(true);
        ui->pBtnImportTxt->setEnabled(false);
        ui->pBtnApply->setEnabled(true);
        return;
    }

    ui->tableWidgetOpen->clear();
    ui->tableWidgetOpen->setColumnCount(1);
    ui->tableWidgetOpen->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("data"));
    ui->tableWidgetOpen->setRowCount(this->tableSize);

    //GetDlgItem(ui->pBtnApply)->EnableWindow(false);
    ui->cbBoxConflictMethod->currentText();
    if(ui->cbBoxConflictMethod->currentText() == "链地址法")
        this->conflictMethod = LINK_ADDR;
    else if (ui->cbBoxConflictMethod->currentText() == "开放定址法") {
        this->conflictMethod = OPEN_ADDR;
    }
    else {
        this->conflictMethod = OPEN_ADDR; //默认
    }

    ui->lEdtMod->setEnabled(false);
    ui->lEdtTableSize->setEnabled(false);
    ui->cbBoxConflictMethod->setEditable(false);

    ui->pBtnImportTxt->setEnabled(true);
    ui->pBtnApply->setEnabled(true);
    return;
}

void MainWindow::on_pBtnImportTxt_clicked()
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

    QByteArray line = aFile.readLine();
    QString str(line);
    QStringList sections = str.trimmed().split(" ");

    //mod = sections[1].toInt();
    int n = sections[0].toInt();
    //this->tableSize = sections[2].toInt();
    //ui->tableWidgetOpen->setRowCount(this->tableSize);

    int key;
    int cnt;
    int addr;
    while (!aFile.atEnd()){
        QByteArray line = aFile.readLine();
        QString str(line);
        str = str.trimmed();
        key = str.toInt();
        addr = key % this->mod;
        cnt = 0;

        switch(this->conflictMethod){
        case OPEN_ADDR:
            if(n > this->tableSize){
                QMessageBox msgBox(QMessageBox::Warning,"错误提示","哈希表空间不够！",nullptr,this);
                msgBox.addButton(tr("好，我知道了"), QMessageBox::AcceptRole);
                msgBox.exec();
                return;
            }
            while(cnt < this->tableSize) {
                if(ui->tableWidgetOpen->item(addr,0) == nullptr ||
                      (ui->tableWidgetOpen->item(addr,0) &&
                       ui->tableWidgetOpen->item(addr,0)->text()==tr(""))){

                    ui->tableWidgetOpen->setItem(addr,0,new QTableWidgetItem(str));
                    qDebug() << "add " << sections[0] << " successfully";
                    break;
                }
                else {
                    addr = (addr + 1) % mod;
                    cnt++;
                    qDebug() << "Open addressing";
                }
            }

            // 满了 无法再加 但是满不满之前已经判断好了
            if(cnt >= this->tableSize){

            }
            break;

        case LINK_ADDR:
            while(1){
                if(ui->tableWidgetOpen->item(addr,cnt) == nullptr ||
                      (ui->tableWidgetOpen->item(addr,cnt) &&
                       ui->tableWidgetOpen->item(addr,cnt)->text()==tr(""))){

                    ui->tableWidgetOpen->setItem(addr,cnt,new QTableWidgetItem(str));
                    qDebug() << "add " << str << " successfully";
                    break;
                }
                else {
                    cnt++;
                    ui->tableWidgetOpen->setColumnCount(cnt + 1);
                    qDebug() << "Linking";
                }
            } // end of while
            break;

        }

        qDebug() << str;
    }

    ui->lEdtMod->setEnabled(false);
    ui->lEdtTableSize->setEnabled(false);
    ui->cbBoxConflictMethod->setEditable(false);

    //ui->pBtnImportTxt->setEnabled(true);
    //ui->pBtnApply->setEnabled(true);

    aFile.close();
}
