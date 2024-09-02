#ifndef BITTREE_H
#define BITTREE_H

#include <QChar>
#include <QString>


struct BitTreeNode {
    int NodeValue;                                      //结点值
    BitTreeNode* LeftChild, * RightChild, *ParentNode;    //左右子树结点
    bool LTag, RTag;                                      //左右子树标志
    int Depth;
    double x_addr, y_addr;                                   //结点坐标

    //默认的构造函数
    BitTreeNode() {
        ParentNode = nullptr;
        LeftChild = nullptr;
        RightChild = nullptr;

        Depth = 1;

        LTag = 0;
        RTag = 0;

        x_addr = 0;
        y_addr = 0;
    }

    //构造新的结点
    BitTreeNode(int NodeValue, BitTreeNode *ParentNode) {
        this->NodeValue = NodeValue;
        this->ParentNode = ParentNode;

        LeftChild = nullptr;
        RightChild = nullptr;

        Depth = 1;

        LTag = 0;
        RTag = 0;

        x_addr = 0;
        y_addr = 0;
    }

    void set_addr(double x_addr, double y_addr) {
        this->x_addr = x_addr;
        this->y_addr = y_addr;
    }
};

#endif // BITTREE_H
