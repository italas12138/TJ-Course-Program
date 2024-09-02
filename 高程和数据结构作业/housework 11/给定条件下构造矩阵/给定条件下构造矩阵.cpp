#include <iostream>
using namespace std;

#define MAXQZIZE 1000
#define maxsize 1000

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
    int indegree;
    ArcNode* firstarc;
}VNode, Adjlist[maxsize];

//领接表的存储
typedef struct
{
    Adjlist vertices;
    int vexnum, arcnum;
}ALGraph;

void create(ALGraph &G,int n)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].data = i+1;
        G.vertices[i].indegree = 0;
        G.vertices[i].firstarc = NULL;
    }
    int v1, v2;
    for (int i = 0; i < n; ++i)
    {
        cin >> v1 >> v2;
        ArcNode* p1;
        p1 = (ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex = v2;
        p1->nextarc = NULL;
        p1->nextarc  = G.vertices[v1-1].firstarc;
        G.vertices[v1-1].firstarc = p1;   
        G.vertices[v2-1].indegree++;
    }
    return;
}

int topsort(ALGraph &G,int G1sort[])
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
                G1sort[v++] = G.vertices[i].data;
                visted[i] = 1;
                p = G.vertices[i].firstarc;
                while (p)
                {
                    --G.vertices[p->adjvex - 1].indegree;
                    p = p->nextarc;
                }
                arm = 1;
                break;
            }
            else
                arm = 0;
        }
    }
    for (int i = 0; i < G.vexnum; ++i)
        arm += visted[i]-1;
    if (!arm)
        return 0;
    else
        return 1;
}

int main()
{
    int k, n, m;
    cin >> k >> n >> m;

    ALGraph G1, G2;
    G1.vexnum = k;
    G2.vexnum = k;
    create(G1,n);
    create(G2,m);

    int sort1, sort2,G1sort[maxsize]={0}, G2sort[maxsize]={0};
    sort1 = topsort(G1, G1sort);
    sort2 = topsort(G2, G2sort);

    if (sort1 + sort2)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
                if (G1sort[i] == G2sort[j]&& G1sort[i]!=0)
                    cout << G1sort[i] << " ";
                else
                    cout << "0 ";
            cout << endl;
        }
    }
    return 0;
}
