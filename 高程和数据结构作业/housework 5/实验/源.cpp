#define stackinitsize 100
#define stackaddsize 10

#include <iostream>
using namespace std;

typedef struct
{
	int *top;
	int *base;
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
		s.base = (int*)malloc((stackinitsize + stackaddsize) * sizeof(int));
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

int main()
{
	stack s;
	initstack(s);
	char c;
	int i = 0;
	int n = 0, num = 0, position = -1, p = -1,p1=-1;
	c = getchar();
	if (c == '"')
	{
		c = getchar();
		while (c != '"')
		{
			switch (c)
			{
				case ')':
					++position;
					if (s.base!=s.top)
						pop(s);
					else
					{
						clearstack(s);
						n = position - p1-1;
						p1 = position;
						if (num < n)
						{
							num = n;
							p = position - n;
						}
					}
					break;
				case '(':
					++position;
					push(s, position);
			}
			c = getchar();
		}
		if (s.base == s.top&&p1!=position)
		{
			n = position - p1;
			if (num < n)
			{
				num = n;
				p = position - n+1;
			}
		}
		if (s.base != s.top)
		{
			for (int i = 1; (s.base + i) < s.top; ++i)
			{
				n = *(s.base + i) - *(s.base)-1;
				if (num < n)
				{
					num = n;
					p = *(s.base + i) - n;
				}
			}
			n = position - *(s.top - 1);
			if (num < n)
			{
				num = n;
				p = position - n+1;
			}
			n = *s.base - p1-1;
			if (num < n)
			{
				num = n;
				p = *s.base - n;
			}
		}
	}
	cout << num << " " << p << endl;
	return 0;
}