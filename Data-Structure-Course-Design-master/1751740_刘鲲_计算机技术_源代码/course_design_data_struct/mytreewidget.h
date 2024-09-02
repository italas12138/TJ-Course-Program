#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H
#include <QTreeWidget>
#include <QDebug>
#include <QInputDialog>
#include <QMenu>

class myTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    myTreeWidget(QWidget* parent = nullptr);
signals:


private slots:
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
    bool addChildNode();
    bool deleteNode();

public:  // 否则mainwindows没法调用
    QTreeWidgetItem *curItem;

    //节点上点击
    QAction *addChildNodeAction;
    QAction *deleteNodeAction;


};

#endif // MYTREEWIDGET_H
