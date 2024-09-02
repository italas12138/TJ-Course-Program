#include <iostream>
using namespace std;

#define maxsize 100   //�������ֵ

int map[maxsize][maxsize];   //���崢������Ķ�ά����
int visted[maxsize][maxsize];   //�����ǩ�Ķ�ά����

void DFS(int u,int map[][maxsize],int visted[][maxsize],int cixu[],int N,int M,int number)
{
	for (int i = 1; i <= N; ++i)     //�ڸõ��������������
	{
		if (i != u && map[u][i] == 1&&visted[u][i]==0)  //��������������б���û���������Ϳ�ʼ����
		{
			++number;           //number ��¼�����ı���
			cixu[number] = i;   //�����������ķ����������
			if (number == M)      //����߶����ʹ��ˣ��������
			{
				for (int i = 0; i <= M; ++i)
					cout << cixu[i];
				cout << endl;
			}
			visted[u][i] = visted[i][u] = 1;        //���õ���Ϊ���������Ա���������
			DFS(i, map, visted, cixu, N, M, number);
			visted[u][i] = visted[i][u] = 0;        //��ʼ������һ�����㣬��֮ǰ�Ĳ�������
			cixu[number] = 0;
			--number;
		}
	}
}

int main()
{
	int N, M;    //N �Ƕ�����, M �Ǳ���
	cin >> N >> M;  //���붥��ͱ���

	int u1, u2;       //����ߵ����ߵĵ�
	for (int i = 1; i <= M; ++i)
	{
		cin >> u1 >> u2;     //����ߵ����ߵĵ�
		map[u1][u2] = map[u2][u1] = 1;  //������ߵĶ�ά�����ʼ��
	}

	int cixu[maxsize]={0};    //����������飬�����������
	cixu[0] = 1;              //��������ĵ�һ��Ԫ����Ϊ1����ʼ�㣩

	DFS(1,map, visted, cixu,N,M,0);     //�����������

}