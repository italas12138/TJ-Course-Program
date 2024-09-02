#include <iostream>

using namespace std;

int s[1000][1000];
bool vis[1000][1000];
bool flag = 0;

void chazhao(int s[][1000], int m, int n, int i, int j)
{
	if (i<0 || i>m - 1 || j<0 || j>n - 1)
		return;

	if (!(i - 1 < 0 || i - 1 > m - 1 || j<0 || j>n - 1) && vis[i - 1][j] == 0) {
		vis[i - 1][j] = 1;
		if (s[i - 1][j] == 1) {
			if (i - 1 > 0 && i - 1 < m - 1 && j > 0 && j < n - 1)
				flag = 1;
			chazhao(s, m, n, i - 1, j);
		}
	}
	if (!(i + 1 < 0 || i + 1 > m - 1 || j<0 || j>n - 1) && vis[i + 1][j] == 0) {
		vis[i + 1][j] = 1;
		if (s[i + 1][j] == 1) {
			if (i + 1 > 0 && i + 1 < m - 1 && j > 0 && j < n - 1)
				flag = 1;
			chazhao(s, m, n, i + 1, j);
		}
	}
	if (!(i < 0 || i  > m - 1 || j - 1 < 0 || j - 1 > n - 1) && vis[i][j - 1] == 0) {
		vis[i][j - 1] = 1;
		if (s[i][j - 1] == 1) {
			if (i > 0 && i < m - 1 && j - 1 > 0 && j - 1 < n - 1)
				flag = 1;
			chazhao(s, m, n, i, j - 1);
		}
	}
	if (!(i < 0 || i > m - 1 || j + 1 < 0 || j + 1 > n - 1) && vis[i][j + 1] == 0) {
		vis[i][j + 1] = 1;
		if (s[i][j + 1] == 1) {
			if (i > 0 && i < m - 1 && j + 1 > 0 && j + 1 < n - 1)
				flag = 1;
			chazhao(s, m, n, i, j + 1);
		}
	}
}

int main()
{
	int m, n, c;
	cin >> m >> n;
	int geshu = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> c;
			s[i][j] = c;
		}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			flag = 0;
			if (s[i][j] == 1&&vis[i][j]==0) {
				if (i > 0 && i < m - 1 && j > 0 && j < n - 1)
					flag = 1;
				vis[i][j] = 1;
				chazhao(s, m, n, i, j);
				if (flag)
					++geshu;
			}
			else
				vis[i][j] = 1;
		}
	cout << geshu << endl;
	return 0;
}