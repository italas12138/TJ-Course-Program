#include <iostream>
using namespace std;

#define MAXQZIZE 1000
#define maxsize 1000

typedef struct
{
    int* base;
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue& s)
{
    s.base = (int*)malloc((MAXQZIZE + 1) * sizeof(int));
    if (!s.base)
        return -1;
    s.front = s.rear = 0;
    return 0;
}

//边结点的存储
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* nextarc;
    int info;
}ArcNode;

//头结点的存储
typedef struct VNode
{
    int data;
    ArcNode* firstarc;
}VNode, Adjlist[maxsize];

//领接表的存储
typedef struct
{
    Adjlist vertices;
    int vexnum, arcnum;
}ALGraph;

int LocateVex(ALGraph G, int m)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (m == G.vertices[i].data)
            return i;
    }
    return -1;
}

void CreateALGraph(ALGraph& G)
{
    int v1, v2;
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = NULL;
    }
    for (int k = 0; k < G.arcnum; ++k)
    {
        int i, j;
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        ArcNode* p1, * p2, * q;
        p1 = (ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex = j;
        p1->nextarc = NULL;
        q = G.vertices[i].firstarc;
        if (!q)
            G.vertices[i].firstarc = p1;
        else
        {
            while (q->nextarc)
                q = q->nextarc;
            q->nextarc = p1;
        }

        p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = i;
        p2->nextarc = NULL;
        q = G.vertices[j].firstarc;
        if (!q)
            G.vertices[j].firstarc = p2;
        else
        {
            while (q->nextarc)
                q = q->nextarc;
            q->nextarc = p2;
        }
    }
    return;
}

void DFS(ALGraph G, int v, int visted[], bool help)
{
    ArcNode* p;
    if (help)
        cout << " ";
    help = 1;
    cout << G.vertices[v].data;
    visted[v] = 1;
    p = G.vertices[v].firstarc;
    while (p)
    {
        if (!visted[p->adjvex])
            DFS(G, p->adjvex, visted, help);
        p = p->nextarc;
    }
}

void BFS(ALGraph G, int v, int visted[])
{
    ArcNode* p;
    SqQueue Q;
    InitQueue(Q);
    cout << G.vertices[v].data;
    visted[v] = 1;
    Q.base[Q.rear] = v;
    Q.rear = (Q.rear + 1) % MAXQZIZE;
    while (Q.front != Q.rear)
    {
        v = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXQZIZE;
        p = G.vertices[v].firstarc;
        while (p)
        {
            if (!visted[p->adjvex])
            {
                cout << " " << G.vertices[p->adjvex].data;
                visted[p->adjvex] = 1;
                Q.base[Q.rear] = p->adjvex;
                Q.rear = (Q.rear + 1) % MAXQZIZE;
            }
            p = p->nextarc;
        }
    }
}

int main()
{
    ALGraph G;
    CreateALGraph(G);
    bool help = 0;
    int visted[maxsize];
    for (int i = 0; i < G.vexnum; ++i)
        visted[i] = 0;
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (!visted[i])
        {
            cout << "{";
            DFS(G, i, visted, help);
            cout << "}";
        }
    }
    cout << endl;
    for (int i = 0; i < G.vexnum; ++i)
        visted[i] = 0;
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (!visted[i])
        {
            cout << "{";
            BFS(G, i, visted);
            cout << "}";
        }
    }

    return 0;
}