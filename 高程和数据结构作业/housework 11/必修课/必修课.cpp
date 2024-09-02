#include <iostream>
using namespace std;

#define maxsize 100

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
    int time;
    int quick_time;
    int end_time;
    int indegree;
    ArcNode* firstarc;
    ArcNode* lastarc;
}VNode, Adjlist[maxsize];

//领接表的存储
typedef struct
{
    Adjlist vertices;
    int vexnum, arcnum;
}ALGraph;

void create(ALGraph& G)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].firstarc = NULL;
        G.vertices[i].lastarc = NULL;
        G.vertices[i].time = 0;
        G.vertices[i].quick_time = 0;
        G.vertices[i].end_time = 1000;
        G.vertices[i].indegree = 0;
    }
    int ti, ci,u;
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> ti >> ci;
        G.vertices[i].time = ti;
        for (int j = 0; j < ci; ++j)
        {
            cin >>u;
            ArcNode* p,*q;
            p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex =i+1;
            p->nextarc = NULL;
            p->nextarc = G.vertices[u -1].firstarc;
            G.vertices[u - 1].firstarc = p;
            

            q = (ArcNode*)malloc(sizeof(ArcNode));
            q->adjvex = u;
            q->nextarc = NULL;
            q->nextarc = G.vertices[i].lastarc;
            G.vertices[i].lastarc = q;
            ++G.vertices[i].indegree;

            ++u;
        }
    }
}

void topsort(ALGraph& G)
{
    int arm = 1;
    int v = 0;
    ArcNode* p;
    int visted[maxsize] = { 0 };
    while (arm)
    {
        for (int i = 0; i < G.vexnum; ++i)
        {
            if (G.vertices[i].indegree == 0 && visted[i] == 0)
            {
                visted[i] = 1;
                p = G.vertices[i].firstarc;
                while (p)
                {
                    --G.vertices[p->adjvex - 1].indegree;
                    if (G.vertices[p->adjvex - 1].quick_time < G.vertices[i].quick_time + G.vertices[i].time)
                        G.vertices[p->adjvex - 1].quick_time = G.vertices[i].quick_time + G.vertices[i].time;
                    p = p->nextarc;
                }
                arm = 1;
                break;
            }
            else
                arm = 0;
        }
    }
}

void count_time(ALGraph& G, int u)
{
    ArcNode* p, * q;
    p = (ArcNode*)malloc(sizeof(ArcNode));
    p = G.vertices[u - 1].lastarc;
    while (p)
    {
        if (G.vertices[p->adjvex - 1].end_time > G.vertices[u - 1].end_time - G.vertices[p->adjvex - 1].time)
            G.vertices[p->adjvex - 1].end_time = G.vertices[u - 1].end_time - G.vertices[p->adjvex - 1].time;
        count_time(G, p->adjvex);
        p = p->nextarc;
    }
    return;
}

void find_path(ALGraph& G)
{
    int visited[maxsize];
    int maxtime=0, max=0;
    for (int i =0; i < G.vexnum; ++i)
        if (G.vertices[i].quick_time > maxtime)
        {
            maxtime = G.vertices[i].quick_time;
            max = i;
        }
    G.vertices[max].end_time = G.vertices[max].quick_time;
    count_time(G, max + 1);

    //改不了
    for (int i = 0; i < G.vexnum; ++i)
    {
        cout << G.vertices[i].quick_time+ G.vertices[i].time << " ";
        if (G.vertices[i].quick_time == G.vertices[i].end_time)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    ALGraph G;
    G.vexnum = n;
    create(G);

    topsort(G);
    find_path(G);

   
    return 0;
}
