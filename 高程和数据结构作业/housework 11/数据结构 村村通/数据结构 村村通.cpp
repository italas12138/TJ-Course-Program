#include <iostream>
using namespace std;

#define maxsize 150

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

//邻接表的存储
typedef struct
{
    Adjlist vertices;
    int vexnum, arcnum;
}ALGraph;

typedef int VRType;
struct close{
    int adjvex;
    int lowcost=1000;
}closedge[maxsize];

void CreateALGraph(ALGraph& G)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].data = i + 1;
        G.vertices[i].firstarc = NULL;
    }
    int v1, v2;
    for (int i = 0; i < G.arcnum; ++i)
    {
        cin >> v1 >> v2;
        ArcNode* p1, * p2;
        p1 = (ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex = v2;
        p1->nextarc = G.vertices[v1-1].firstarc;
        G.vertices[v1-1].firstarc = p1;

        p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = v1;
        p2->nextarc = G.vertices[v2-1].firstarc;
        G.vertices[v2-1].firstarc = p2;
    }
    return;
}

void DFS(ALGraph G, int v, int visted[],struct close closedge[])
{
    ArcNode* p;
    closedge[G.vertices[v - 1].data - 1].lowcost = 0;
    visted[v-1] = 1;
    p = G.vertices[v-1].firstarc;
    while (p)
    {
        if (!visted[p->adjvex-1])
            DFS(G, p->adjvex, visted,closedge);
        p = p->nextarc;
    }
}


int MiniSpantree_PRIM(ALGraph G, int u, int far[][maxsize], int farlong)
{
    //定义标签
    bool arm = 1;

   //struct close closedge[maxsize];
    
    //定义标签数组
    int visted[maxsize] = { 0 };
    visted[u - 1] = 1;

    //计算距离
    farlong = 0;

    int mincost, min;

    while (arm)
    {
        //找到已经连接上的
        DFS(G, u, visted, closedge);

        //更新closedge数组
        for (int i = 0; i < G.vexnum; ++i)
        {
            visted[i] = 0;
            if (closedge[i].lowcost == 0)
            {
                for (int j = 0; j < G.vexnum; ++j)
                {
                    if (closedge[j].lowcost != 0)
                        if (far[i][j] < closedge[j].lowcost)
                        {
                            closedge[j].lowcost = far[i][j];
                            closedge[j].adjvex = i+1;
                        }
                }
            }
        }

        mincost = 1000;
        min = 0;
        for (int i = 0; i < G.vexnum; ++i)
            if (closedge[i].lowcost < mincost && closedge[i].lowcost != 0)
            {
                mincost = closedge[i].lowcost;
                min = i;
            }
        closedge[min].lowcost = 0;
        farlong += far[closedge[min].adjvex-1][min];

        ArcNode* p1, * p2;
        p1 = (ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex = min+1;
        p1->nextarc = G.vertices[closedge[min].adjvex-1].firstarc;
        G.vertices[closedge[min].adjvex-1].firstarc = p1;

        p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = closedge[min].adjvex;
        p2->nextarc = G.vertices[min].firstarc;
        G.vertices[min].firstarc = p2;

        arm = 0;

        for (int i = 0; i < G.vexnum; ++i)
            if (closedge[i].lowcost != 0)
            {
                arm = 1;
                break;
            }
    }
    return farlong;
}

int main()
{
    int n,m;
    cin >> n;
    int far[maxsize][maxsize] = { 0 };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> far[i][j];

    cin >> m;
    ALGraph G;
    G.vexnum = n;
    G.arcnum = m;

    CreateALGraph(G);
    int farlong = 0;
    farlong = MiniSpantree_PRIM(G,1,far, farlong);
    
    cout << farlong << endl;

    return 0;
}