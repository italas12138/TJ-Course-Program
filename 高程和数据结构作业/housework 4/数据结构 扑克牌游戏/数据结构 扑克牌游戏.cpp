#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,num=0,a[14]={0};
	cin >> n;
	char hua[100][10],hao[100][10];
	char do1[10] = "",do2[10]="",do3[10]="",fuzhu[10]="",zifu[14]="A234567891JQK";
	for (int i = 0; i < n; ++i)
	{
		cin >> do1;
		if (do1[0] == 'A')
		{
			cin >> do2;
			cin >> do3;
			strcpy(hua[num], do2);
			strcpy(hao[num], do3);
			++num;
		}
		if (do1[0] == 'E')
		{
			cin >> do2;
			for (int j = 0; j < num; ++j)         /*寻找相同花色*/
				if (!strcmp(hua[j], do2))
				{
					for (int x = 0; x < 14; ++x)
						if (zifu[x] == hao[j][0])
							++a[x];
					for (int v = j; v < num-1; ++v)    /*找到后将这个花色的牌消掉*/
					{
						strcpy(hua[v], hua[v + 1]);
						strcpy(hao[v], hao[v + 1]);
					}
					--num;
					--j;
				}
			for(int y=13;y>=0;--y)
				for(;a[y]>0;--a[y])
				{
					for (int z = num-1; z >= 0; --z)
					{
						strcpy(hua[z + 1], hua[z]);
						strcpy(hao[z + 1], hao[z]);
					}
					++num;
					strcpy(hua[0], do2);
					hao[0][0] = zifu[y];
					if (y == 9)
					{
						hao[0][1] = '0';
						hao[0][2] = '\0';
					}
					else
						hao[0][1] = '\0';
				}
		}
		if (do1[0] == 'R') 
			for (int k = 0; k < num / 2; ++k)
			{
				strcpy(fuzhu, hua[k]);
				strcpy(hua[k], hua[num - 1 - k]);
				strcpy(hua[num - 1 - k], fuzhu);
				strcpy(fuzhu, hao[k]);
				strcpy(hao[k], hao[num - 1 - k]);
				strcpy(hao[num - 1 - k], fuzhu);
			}
		if (do1[0] == 'P')
			if (num == 0)
			{
				cout << "NULL" << endl;
				continue;
			}
			else
			{
				cout << hua[0] << " " << hao[0] << endl;
				for (int t = 0; t < num - 1; ++t)
				{
					strcpy(hua[t], hua[t + 1]);
					strcpy(hao[t], hao[t + 1]);
				}
				strcpy(hua[num - 1], fuzhu);
				strcpy(hao[num - 1], fuzhu);
				--num;
			}
	}
	if (num == 0)
		cout << "NULL" << endl;
	else
		for (int r = 0; r < num; ++r)
			cout << hua[r] << " " << hao[r] << endl;
	return 0;
}