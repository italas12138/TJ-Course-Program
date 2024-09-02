#include <iostream>
using namespace std;
int main()
{
	int N, A,w=200;
	cin >> N >> A;

	int a[2] = { 0 }, n[3] = { 0 }, s[205] = { 0 }, p[205] = {0}, v[205] = { 0 };
	s[1]=a[1] = A / 10;
	s[0]=a[0] = A % 10;
	if (A == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	if (N == 1)
	{
		cout << A << endl;
		return 0;
	}
	for (int i = 2; i <= N; ++i)
	{
		for (int r = 0; r < 200; ++r)
			v[r]=p[r] = 0;
		p[1] = A / 10;
		p[0] = A % 10;
		for (int j = 1; j < i; ++j)
		{
			for (int x = 0; x < 2; ++x)
			{
				for (int y = 0; y < 200; ++y)
					v[x + y] += a[x] * p[y];
				for (int z = 0; z < 200; ++z)
				{
					v[z + 1] += v[z] / 10;
					v[z] = v[z] % 10;
				}
			}
			for (int u = 0; u <200; ++u)
			{
				p[u] = v[u];
				v[u] = 0;
			}
		}
		n[2] = i / 100;
		n[1] = i / 10 % 10;
		n[0] = i % 10;
		for (int x = 0; x < 3; ++x)
		{
			for (int y = 0; y <200; ++y)
				v[x + y]+= n[x] * p[y];
			for (int z = 0; z <200; ++z)
			{
				v[z + 1] += v[z] / 10;
				v[z] = v[z] % 10;
			}
		}
		for (int k = 0; k < 200; ++k)
			s[k] += v[k];
		for (int t = 0; t <200; ++t)
		{
			s[t + 1] += s[t] / 10;
			s[t] = s[t] % 10;
		}
	}
	for (w =200; w > 0; --w)
		if (s[w - 1] != 0)
			break;
	for (; w > 0; --w)
		cout << s[w - 1];
	cout << endl;
	return 0;
}
