#define stackinitsize 100
#define stackaddsize 10

#include <iostream>
#include <string>
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

int pop(stack& s)
{
	if (s.top == s.base)
		return -1;
	--s.top;
	return 0;
}

char bijiao(stack &caozuo,char c)
{
	switch (c)
	{
		case '&':
			if (*(caozuo.top - 1) == '|' || *(caozuo.top - 1) == '#' || *(caozuo.top - 1) == '(')
				return '>';
				return '<';
			break;
		case '!':
			return '>';
			break;
		case '|':
			if ( *(caozuo.top - 1) == '#' || *(caozuo.top - 1) == '(')
				return '>';
				return '<';
			break;
		case '(':
			return '>';
			break;
		case ')':
			if (*(caozuo.top - 1) == '(')
				return '=';
			    return '<';
			break;
	}
}

void jisuan(stack& caozuo, stack& shuzi)
{
	switch (*(caozuo.top-1))
	{
		case '!':
			if (*(shuzi.top - 1) == 'V')
			{
				pop(shuzi);
				pop(caozuo);
				push(shuzi, 'F');
			}
			else if (*(shuzi.top - 1) == 'F')
			{
				pop(shuzi);
				pop(caozuo);
				push(shuzi, 'V');
			}
			break;
		case '|':
			if (*(shuzi.top - 1) == 'F' && *(shuzi.top - 2) == 'F')
			{
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, 'F');
			}
			else
			{
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, 'V');
			}
			break;
		case '&':
			if (*(shuzi.top - 1) == 'V' && *(shuzi.top - 2) == 'V')
			{
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, 'V');
			}
			else
			{
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, 'F');
			}
			break;
		
	}
}

int clearstack(stack& s)
{
	s.top = s.base;
	return 0;
}
void jieguo(stack shuzi, stack caozuo)
{
	for (int i = 0; i < caozuo.top - caozuo.base; ++i)
		cout << *(caozuo.base + i) << " ";
	cout << endl;

	for (int i = 0; i < shuzi.top - shuzi.base; ++i)
		cout << *(shuzi.base + i) << " ";
}

int main()
{
	stack caozuo, shuzi;
	initstack(caozuo);
	initstack(shuzi);
	push(caozuo, '#');
	string c;
	int clen=0,i=0;
	
	
	while (getline(cin, c))
	{
		clen = c.length();
		for (int j = 0; j < clen; ++j)
		{
			switch (c[j])
			{
				case 'V':
				case 'F':
					push(shuzi, c[j]);
					break;
				case ' ':
					break;
				default:
					switch (bijiao(caozuo, c[j]))
					{
						case '<':
							jisuan(caozuo, shuzi);
							while (bijiao(caozuo, c[j]) == '<')
								jisuan(caozuo, shuzi);
							push(caozuo, c[j]);
							break;
						case '>':
							push(caozuo, c[j]);
							break;
						case '=':
							pop(caozuo);
							break;
					}
					if (*(caozuo.top - 1) == ')' && *(caozuo.top - 2) == '(')
					{
						pop(caozuo);
						pop(caozuo);
					}
			}
		}
		while (*(caozuo.top - 1) != '#')
		{
			jisuan(caozuo, shuzi);
		}
		++i;
		cout << "Expression " << i << ": " << *(shuzi.top - 1) << endl;
		clearstack(shuzi);
	}
	return 0;
}