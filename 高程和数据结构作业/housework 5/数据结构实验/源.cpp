#define stackinitsize 100000
#define stackaddsize 10000

#include <iostream>
using namespace std;
/*
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

int push(stack& s, int c)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (int*)realloc(s.base, (stackinitsize + stackaddsize) * sizeof(int));
		if (!s.base)
			return -1;
		s.top = s.base + s.stacksize;
		s.stacksize += stackaddsize;
	}
	*s.top++ = c;
	return 0;
}

int pop(stack& s)
{
	if (s.top == s.base)
		return -1;
	--s.top;
	return 0;
}

int clearstack(stack& s)
{
	s.top = s.base;
	return 0;
}
*/
int main()
{
	int s[10000];
	char c;
	int i = 0,j=0;
	int n = 0, num = 0, position = 0, p = 0, p1 = 0;
	c = getchar();
	while (c != '\n')
	{
		switch (c)
		{
			case ')':
				++position;
				if (j>0)
					--j;
				else
				{
					for (int i = 0; s[i] != 0; ++i)
						s[i] = 0;
					j=0;
					n = position - p1 - 1;
					p1 = position;
					if (num < n)
					{
						num = n;
						p = position - n - 1;
					}
				}
				break;
			case '(':
				++position;
				++j;
				s[j-1] = position;
		}
		c = getchar();
	}
	if (j==0&& p1 != position)
	{
		n = position - p1;
		if (num < n)
		{
			num = n;
			p = position - n;
		}
	}
	if (j>0)
	{
		n = s[0] - p1 - 1;
		if (num < n)
		{
			num = n;
			p = s[0] - n - 1;
		}
		for (int i = 1; i < j; ++i)
		{
			n = s[i] - s[i-1] - 1;
			if (num < n)
			{
				num = n;
				p = s[i] - n - 1;
			}
		}
		n = position - s[j];
		if (num < n)
		{
			num = n;
			p = position - n;
		}
	}
	for (int i = 0; i < j; ++i)
		cout <<s[i] << " ";
	cout << endl;

	cout << num << " " << p << endl;
	return 0;
}