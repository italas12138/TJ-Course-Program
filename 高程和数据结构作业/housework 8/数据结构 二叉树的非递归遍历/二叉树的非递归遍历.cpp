#include <iostream>
using namespace std;

int n;

typedef struct Bitnode 
{
	char data;
	struct Bitnode* leftchild, * rightchild;
}Bitnode, * Bittree;

int initBittree(Bittree& T)
{
	T = (Bitnode*)malloc(sizeof(Bitnode));
	if (!T)
		return -1;
	T->leftchild = T->rightchild = NULL;
	return 0;
}

int CreateBittree(Bittree& T, char chucun[][7], int i)
{
	if (i == 0)
	{
		T->data = chucun[0][5];
		++i;
	}
	while (i < 2 * n)
	{
		if (chucun[i][1] == 'u')
			if(i>=1&&chucun[i-1][1]=='o')
			{
				if (T->rightchild != NULL)
					return i;
				T->rightchild = (Bitnode*)malloc(sizeof(Bitnode));
				T->rightchild->leftchild = T->rightchild->rightchild = NULL;
				T->rightchild->data = chucun[i][5];
				i = CreateBittree(T->rightchild, chucun, ++i);
			}
			else
			{
				T->leftchild = (Bitnode*)malloc(sizeof(Bitnode));
				T->leftchild->leftchild = T->leftchild->rightchild = NULL;
				T->leftchild->data = chucun[i][5];
				i = CreateBittree(T->leftchild, chucun, ++i);
			}
		else if (chucun[i][1] == 'o')
			if (chucun[i - 1][1] == 'u')
			{
				++i;
			}
			else
			{
				if (T->rightchild != NULL)
					return i;
				else
				{
					++i;
					return i;
				}
			}
	}
	return 2*n;
}

void PostOrderBittree(Bittree T)
{
	if (T!=NULL)
	{
		PostOrderBittree(T->leftchild);
		PostOrderBittree(T->rightchild);
		cout << T->data;
	}
}
int main()
{
	Bittree T1;
	initBittree(T1);
	cin >> n;
	cin.clear();
	cin.ignore();
	char chucun[200][7];
	for (int i = 0; i < 2 * n; ++i)
		cin.getline(chucun[i],7);
	CreateBittree(T1,chucun,0);
	PostOrderBittree(T1);
	return 0;
}