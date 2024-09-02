#include <iostream>
#include <string.h>
using namespace std;

char chucun[2000000];
int t1[10000], t2[10000];

typedef struct CSNode
{
	char data;
	struct CSNode* firstchild, * nextsibling,*parent;
}CSNode,*CStree;

int initCStree(CStree &T1)
{
	T1 = (CSNode*)malloc(sizeof(CSNode));
	if (!T1)
		return -1;
	T1->parent = NULL;
	T1->data = '0';
	T1->firstchild = T1->nextsibling =  NULL;
	return 0;
}

int Depth2(CStree T1)
{
	int depl, depr;
	if (T1)
	{
		depl = Depth2(T1->firstchild);
		depr = Depth2(T1->nextsibling);
		if (depl >= depr)
			return depl + 1;
		else
			return depr + 1;
	}
	return 0;
}

void createCStree(char chucun[2000000], CStree T1)
{
	int i=0;
	while (i<strlen(chucun))
	{
		if (chucun[i] == 'd')
		{
			++i;
			if (T1->firstchild == NULL)
			{
				T1->firstchild = (CSNode*)malloc(sizeof(CSNode));
				T1->firstchild->data = 'd';
				T1->firstchild->parent = T1;
				T1->firstchild->firstchild = T1->firstchild->nextsibling = NULL;
				T1 = T1->firstchild;
			}
			else
			{
				if (T1->firstchild->nextsibling == NULL)
				{
					T1->firstchild->nextsibling = (CSNode*)malloc(sizeof(CSNode));
					T1->firstchild->nextsibling->data = 'd';
					T1->firstchild->nextsibling->parent = T1;
					T1->firstchild->nextsibling->firstchild = T1->firstchild->nextsibling->nextsibling = NULL;
					T1 = T1->firstchild->nextsibling;
				}
				else
				{
					T1 = T1->firstchild;
					while (T1->nextsibling != NULL)
					{
						T1 = T1->nextsibling;
					}
					T1->nextsibling = (CSNode*)malloc(sizeof(CSNode));
					T1->nextsibling->data = 'd';
					T1->nextsibling->parent = T1->parent;
					T1->nextsibling->firstchild = T1->nextsibling->nextsibling = NULL;
					T1 = T1->nextsibling;
				}
			}
		}
		else if (chucun[i] == 'u')
		{
			++i;
			T1 = T1->parent;
		}
	}
}

int Depth1(char chucun[2000000])
{
	int i=0,n=0,max=0;
	while (i < strlen(chucun))
	{
		if (chucun[i] == 'd')
			++n;
		else if (chucun[i] == 'u')
			--n;
		++i;
		if (n > max)
			max = n;
	}
	return max;
}

int Depth3(char chucun[2000000])
{

	int i = 0, n = 0;
	while (i < strlen(chucun))
	{
		if (i == 0)
		{
			if (chucun[i] == 'd')
				++n;
		}
		else if (i == 1)
		{
			if (chucun[i] == 'd')
				++n;
		}
		else
		{
			if (chucun[i] == 'd' && chucun[i - 1] == 'd')
				++n;
			else if (chucun[i] == 'd' && chucun[i - 2] == 'd')
				++n;
		}
		++i;
	}
	return n;
}

int main()
{
	int cishu = 0,j=0;
	
	while (1)
	{
		CStree T1;
		initCStree(T1);
		cin >> chucun;
		++cishu;
		if (chucun[0] == '#')
			break;
		createCStree(chucun,T1);
		t1[j] = Depth1(chucun);
		t2[j] = Depth2(T1); 
		++j;
	}
	cout << endl;
	for (int m = 0; m < j; ++m)
	{
		cout << "Tree " << m+1 << ": " << t1[m] << " => " << t2[m]-1<< endl;
		cout << endl;
	}
	return 0;
}
