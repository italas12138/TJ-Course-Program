#include <iostream>
#include <iomanip>
using namespace std;

#define MAXQZIZE 1500
#define maxsize 2000

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

//�߽��Ĵ洢
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
	int info;
}ArcNode;

//ͷ���Ĵ洢
typedef struct VNode
{
	int data;
	ArcNode* firstarc;
}VNode, Adjlist[maxsize];

//�ڽӱ�Ĵ洢
typedef struct
{
	Adjlist vertices;
	int vexnum, arcnum;
}ALGraph;

int LocateVex(ALGraph G, int m)
{
	for (int i=0; i < G.vexnum; ++i)
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
		G.vertices[i].data = i+1;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; ++k)
	{
		cin >> v1 >> v2;
		int i, j;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		ArcNode* p1,*p2, * q;

		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = j+1;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;

		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = i + 1;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return;
}

void BFS(ALGraph G, int v, int visted[])
{
	ArcNode* p;
	SqQueue Q1,Q2;
	InitQueue(Q1);
	InitQueue(Q2);

	//��һ�������Ϊ���ʹ�
	visted[v] = 1;   

	//��һ����������
	Q1.base[Q1.rear] = v+1;
	Q1.rear = (Q1.rear + 1) % MAXQZIZE;

	for (int i = 0; i < 3; ++i)
	{
		//�����в�Ϊ��
		while (Q1.front != Q1.rear)
		{
			//����һ����������ָ�������
			v = Q1.base[Q1.front];
			Q1.front = (Q1.front + 1) % MAXQZIZE;

			//�ý������Ľ��������
			p = G.vertices[v-1].firstarc;
			while (p)
			{
				if (!visted[p->adjvex-1])
				{
					visted[p->adjvex-1] = 1;
					Q2.base[Q2.rear] = p->adjvex;       //������±�
					Q2.rear = (Q2.rear + 1) % MAXQZIZE;
				}
				p = p->nextarc;
			}
		}

		while (Q2.front != Q2.rear)
		{
			//����һ����������ָ�������
			v = Q2.base[Q2.front];
			Q2.front = (Q2.front + 1) % MAXQZIZE;

			//�ý�������һ���߽��������
			p = G.vertices[v-1].firstarc;
			while (p)
			{
				if (!visted[p->adjvex-1])
				{
					visted[p->adjvex-1] = 1;
					Q1.base[Q1.rear] = p->adjvex;       //������±�
					Q1.rear = (Q1.rear + 1) % MAXQZIZE;
				}
				p = p->nextarc;
			}
		}
	}
}

int main()
{
	ALGraph G;
	CreateALGraph(G);
	int visted[maxsize];
	for (int i = 0; i < G.vexnum; ++i)
	{
		for (int i = 0; i < G.vexnum; ++i)
			visted[i] = 0;
		BFS(G, i, visted);
		int m = 0;
		for (int i = 0; i < G.vexnum; ++i)
			if (visted[i] == 1)
				++m;
		double baifenbi;
		baifenbi = 100*(m * 1.0) / (G.vexnum*1.0);
		cout << i+1 << ": " <<setiosflags(ios::fixed)<< setprecision(2)<<baifenbi << "%" << endl;
	}

	return 0;
}