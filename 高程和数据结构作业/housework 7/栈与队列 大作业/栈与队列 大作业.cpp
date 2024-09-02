#define stackinitsize 30000
#define stackaddsize 100

#include <iostream>
#include <string.h>
using namespace std;
int s1[120000], s2[120000];

typedef struct
{
	int* top;
	int* base;
	int stacksize;
}stack;

int initstack(stack& s)
{
	s.base = (int*)malloc(stackinitsize * sizeof(int));
	if (!s.base)
		return -1;
	s.top = s.base;
	s.stacksize = stackinitsize;
	return 0;
}

int push(stack& s,int c)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (int*)malloc((stackinitsize + stackaddsize) * sizeof(int));
		if (!s.base)
			return -1;
		s.top = s.base + s.stacksize;
		s.stacksize += stackaddsize;
	}
	*s.top++ = c;
	return 0;
}

int pop(stack& s, int& e)
{
	if (s.top == s.base)
		return -1;
	--s.top;
	e = *s.top;
	return 0;
}


int clearstack(stack& s)
{
	s.top = s.base;
	return 0;
}


int main()
{
	int n,w;
	cin >> n;
	stack Dg;
	initstack(Dg);
	while(n)
	{
		push(Dg, n);
		--n;
	}
	int e, slen1=1, slen2;
	int e1[4];
	s1[0] = 1;
	while (Dg.top != Dg.base)
	{
		pop(Dg, e);
		e1[0] = e % 10;
		e1[1] = e / 10 % 10;
		e1[2] = e / 100 % 10;
		e1[3] = e / 1000;
		if (e > 1000)
			slen2 = slen1 + 4;
		else if (e > 100)
			slen2 = slen1 + 3;
		else if (e > 10)
			slen2 = slen1 + 2;
		else
			slen2 = slen1 + 1;
		for (int x = 0; x < 4; ++x)
		{
			for (int y = 0; y < slen1; ++y)
				s2[x + y] += e1[x] * s1[y];
			for (int z = 0; z < slen2; ++z)
			{
				s2[z + 1] += s2[z] / 10;
				s2[z] = s2[z] % 10;
			}	
		}
		for (int z = 0; z < slen2; ++z)
		{
			s1[z] = s2[z];
			s2[z] = 0;
		}
		slen1 = slen2;
		if (e % 1000 == 0)
			cout << e << endl;
	}
	for(w = slen1; w >= 0; --w)
		if (s1[w] != 0)
			break;
	for(int i=w;i>=0;--i)
		cout << s1[i];
	return 0;
}