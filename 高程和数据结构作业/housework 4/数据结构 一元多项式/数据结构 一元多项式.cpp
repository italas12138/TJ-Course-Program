#include <iostream>
using namespace std;
int main()
{
	int a[2100] = { 0 }, b[2100] = { 0 }, c[2100] = { 0 }, d[2100] = { 0 };
	int s[2100] = { 0 }, e[2100] = { 0 };
	int m,n,p,q,x;
	cin >> m;
	for (int i = 0; i < m; ++i) 
	{
		cin >> p >> q;
		a[q] = p;
		b[q] = q;
	}
	cin >> n;
	for (int i = 0;i < n; ++i)
	{
		cin >> p >> q;
		c[q] = p;
		d[q] = q;
	}
	cin >> x;
	if (x == 0)
		for (int i = 0; i < 2100; ++i)
		{
			s[i] = a[i] + c[i];
			if (s[i] != 0)
				cout << s[i]  << ' ' << i<< ' ';
		}


	else if (x == 1)
	{
		for (int i = 0; i < 2100; ++i)
			for (int j = 0; j < 2100; ++j)
				if ((a[i] && c[j]) != 0)
				{
					e[i + j] = i + j;
					s[i + j] += a[i] * c[j];
				}
		for (int k = 0; k < 2100; ++k)
			if (s[k] != 0)
				cout << s[k] << ' ' << k << ' ';
	}


	else if (x == 2) 
	{
		for (int i = 0; i < 2100; ++i)
		{
			s[i] = a[i] + c[i];
			if (s[i] != 0)
				cout << s[i] << ' ' << i << ' ';
		}
		cout << endl;
		for (int i = 0; i < 2100; ++i)
			s[i] = 0;
		for (int i = 0; i < 2100; ++i)
			for (int j = 0; j < 2100; ++j)
				if ((a[i] && c[j]) != 0)
				{
					e[i + j] = i + j;
					s[i + j] += a[i] * c[j];
				}
		for (int k = 0; k < 2100; ++k)
			if (s[k] != 0)
				cout << s[k] << ' ' << k << ' ';
	}
	cout << endl;
	return 0;
}
