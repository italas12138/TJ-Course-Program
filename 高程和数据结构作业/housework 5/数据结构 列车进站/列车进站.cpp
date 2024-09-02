#define stackinitsize 100
#define stackaddsize 10

#include <iostream>
#include <string.h>
using namespace std;

typedef struct
{
	char* top;
	char* base;
	int stacksize;
}stack;

int initstack(stack& s)
{
	s.base = (char*)malloc(stackinitsize * sizeof(char));
	if (!s.base)
		return -1;
	s.top = s.base;
	s.stacksize = stackinitsize;
	return 0;
}

int push(stack& s, char c)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (char*)malloc((stackinitsize + stackaddsize) * sizeof(char));
		if (!s.base)
			return -1;
		s.top = s.base + s.stacksize;
		s.stacksize += stackaddsize;
	}
	*s.top++ = c;
	return 0;
}

int pop(stack& s, char& e)
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
	bool che = 1;
	stack zhantai, rukou;
	initstack(zhantai);
	initstack(rukou);
	char c, e = ' ';
	char ru[100] = {};
	cin >> ru;
	c = getchar();
	int rulen = 0;
	rulen = strlen(ru);
	c = getchar();
	while (c != EOF)
	{
		for (int k = rulen - 1; k >= 0; --k)
		{
			push(rukou, ru[k]);
		}
		while (c != EOF && c != '\n')
		{
			if (rukou.top == rukou.base && (zhantai.top != zhantai.base) && *(zhantai.top - 1) != c)
				che = 0;
			if ((zhantai.top != zhantai.base) && *(zhantai.top - 1) == c)
				pop(zhantai, e);
			else if ((rukou.top != rukou.base) && *(rukou.top - 1) != c)
			{
				while ((rukou.top != rukou.base) && *(rukou.top - 1) != c)
				{
					pop(rukou, e);
					push(zhantai, e);
				}
				if (rukou.top == rukou.base && (zhantai.top != zhantai.base) && *(zhantai.top - 1) != c)
					che = 0;
			}
			if ((rukou.top != rukou.base) && *(rukou.top - 1) == c)
				pop(rukou, e);
			c = getchar();
		}
		if (che == 1)
			cout << "yes" << endl;
		else if (che == 0)
			cout << "no" << endl;
		c = getchar();
		clearstack(zhantai);
		clearstack(rukou);
		che = 1;
	}
	return 0;
}