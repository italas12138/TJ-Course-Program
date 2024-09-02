
#include <QVector>

#include <QMetaType>

typedef int ElemType;
struct Node{
    int id;			// 该线性表中所有节点的ID唯一
    ElemType data;	// 节点的值，自定义数据类型
    int pid;		// 表示该节点的父节点，值为0表示根，对应线性表中其他节点的id值
    Node *next;		// 指向线性表下一个节点
    QVector <Node *> children; // 指向孩子的指针

    Node(){
        id = -1;
        pid = -1;
        next = nullptr;
    }

    ~Node(){

    }
};


//Q_DECLARE_METATYPE(Node)
// 1. 设计算法根据线性表中pid的指向，将该线性表中存储的节点转换为树形结构
// 2  在树结构中插入一节点，自动将其加入到线性表中
// 3  在树结构中删除一个节点，自动更新线性表的结构

/*
int initLinearList(Node *L)
{
    int n; //个数
    cin >> n;

    Node *p = L;

    int i;
    for (i = 0; i < n; i++) {
        p->next = new Node;
        p = p->next;
        cin >> p->id >> p->pid;
    }
    p->next = NULL;

    //p = L->next;
    //while (p) {
    //	cout << p->id << " " << p->pid << endl;
    //	p = p->next;
    //}

    return 0;
}

int list2tree(Node *L)
{
    Node *p = L->next;
    Node *q;
    int cur_pid;
    Node *pre_root; //把根节点提上来？

    while (p) {
        cur_pid = p->pid;
        if (cur_pid == -1) {
            p = p->next;
            continue;
        }

        q = L->next;
        while (q) {

            // 找到父亲节点
            if (q->id == cur_pid) {
                q->children.push_back(p);
            }
            q = q->next;
        }
        p = p->next;
    }

    return 0;
}

int printTree(Node *p, int level)
{
    if (p->children.size() == 0) {
        return 0;
    }


    //cout << "C++11,第四种遍历方式，auto关键字" << endl;
    for (auto i : p->children){
        for (int j = 0; j < level; j++) {
            cout << "  ";
        }
        cout << i->id << endl;
        printTree(i, level + 1);
    }

    return 0;
}

int deleteNode(Node *L, int id)
{
    Node *q = L;
    Node *p = L->next;
    while (p) {
        if (p->id == id) {
            q->next = p->next;

            for (auto i : p->children) {
                deleteNode(L, i->id);
            }
            delete p;

            p = q->next;

        }
        else {
            q = q->next;
            p = q->next;
        }
    }
    return 0;
}

int addNode(Node *L, Node &e)
{
    Node *p;
    Node *t = new Node;
    memcpy(&(t->data), &(e.data), sizeof(ElemType));
    t->id = e.id;
    t->pid = e.pid;

    // 可能当个数太少的时候会出错
    t->next = L->next->next;
    L->next->next = t;
    p = t->next;

    while (p){
        if (p->id == e.pid) {
            p->children.push_back(t);
            return 0;
        }
        p = p->next;
    }
    return 0;
}

*/



/*
test1
12
0 -1
1 0
2 0
3 0
9 2
7 2
11 3
5 1
4 1
8 3
6 3
10 3



*/
