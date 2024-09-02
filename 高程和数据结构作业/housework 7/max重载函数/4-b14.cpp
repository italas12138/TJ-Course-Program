/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int max(int a, int b,int c)
{
	if (a >= b);
	else
		a = b;
	if (a >= c)
		return a;
	else
		return c;
}

int max(int a, int b, int c,int d)
{
	if (a >= b);
	else
		a = b;
	if (a >= c);
	else
		a = c;
	if (a >= d)
		return a;
	else
		return d;
}

int main()
{
	int x1=1, x2=1, x3=1, x4=1,num,maxer;
	char cuowu=' ';
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(65535, '\n');
			continue;
		}
		if (num == 2)
		{
			cin >> x1 >> x2;
			maxer = max(x1, x2);
		}
		else if (num == 3)
		{
			cin >> x1 >> x2 >> x3;
			maxer = max(x1, x2, x3);
		}
		else if (num == 4)
		{
			cin >> x1 >> x2 >> x3 >> x4;
			maxer = max(x1, x2, x3, x4);
		}
		else
		{
			while ((cuowu = getchar()) != '\n');
			cout << "个数输入错误" << endl;
			return 0;
		}
		if (cin.good() == 0||x1<0||x2<0||x3<0||x4<0)
		{
			cin.clear();
			cin.ignore(65535, '\n');
			continue;
		}
		else
		{
			cout << "max=" << maxer << endl;
			return 0;
		}
	}
}