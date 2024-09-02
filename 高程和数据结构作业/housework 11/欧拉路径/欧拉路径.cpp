#include <iostream>
using namespace std;

#define maxsize 100   //定义最大值

int map[maxsize][maxsize];   //定义储存边数的二维数组
int visted[maxsize][maxsize];   //定义标签的二维数组

void DFS(int u,int map[][maxsize],int visted[][maxsize],int cixu[],int N,int M,int number)
{
	for (int i = 1; i <= N; ++i)     //在该点向其他顶点遍历
	{
		if (i != u && map[u][i] == 1&&visted[u][i]==0)  //如果与其他顶点有边且没被遍历，就开始搜索
		{
			++number;           //number 记录遍历的边数
			cixu[number] = i;   //将满足条件的放入次序数组
			if (number == M)      //如果边都访问过了，输出序列
			{
				for (int i = 0; i <= M; ++i)
					cout << cixu[i];
				cout << endl;
			}
			visted[u][i] = visted[i][u] = 1;        //将该点标记为遍历过，以便向下搜索
			DFS(i, map, visted, cixu, N, M, number);
			visted[u][i] = visted[i][u] = 0;        //开始访问下一个顶点，将之前的操作重置
			cixu[number] = 0;
			--number;
		}
	}
}

int main()
{
	int N, M;    //N 是顶点数, M 是边数
	cin >> N >> M;  //输入顶点和边数

	int u1, u2;       //定义边的两边的点
	for (int i = 1; i <= M; ++i)
	{
		cin >> u1 >> u2;     //输入边的两边的点
		map[u1][u2] = map[u2][u1] = 1;  //将储存边的二维数组初始化
	}

	int cixu[maxsize]={0};    //定义次序数组，帮助最后的输出
	cixu[0] = 1;              //次序数组的第一个元素置为1（起始点）

	DFS(1,map, visted, cixu,N,M,0);     //深度优先搜索

}