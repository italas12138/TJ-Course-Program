#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int m;
char chucun[100000], chazhao, s[100000];
/*
typedef struct Bitnode
{
	int ltag, rtag;
	char data;
	struct Bitnode* leftchild, * rightchild;
}Bitnode, * Bittree;

Bittree pre=NULL;

int initBittree(Bittree& T)
{
	T = (Bitnode*)malloc(sizeof(Bitnode));
	if (!T)
		return -1;
	T->leftchild = T->rightchild = NULL;
	return 0;
}

int CreateBittree(Bittree& T, char chucun [100],int len, int i)
{
	if (i == 0)
	{
		T->ltag = T->rtag = 0;
		T->data = chucun[0];
		++i;
	}
	while (i < len)
	{
		if (chucun[i] != '#')
			if (i >= 1 && chucun[i - 1] == '#')
			{
				if (T->rightchild != NULL)
					return i;
				T->rightchild = (Bitnode*)malloc(sizeof(Bitnode));
				T->rightchild->leftchild = T->rightchild->rightchild = NULL;
				T->rightchild->ltag = T->rightchild->rtag = 0;
				T->rightchild->data = chucun[i];
				i = CreateBittree(T->rightchild, chucun, len,++i);
			}
			else
			{
				T->leftchild = (Bitnode*)malloc(sizeof(Bitnode));
				T->leftchild->leftchild = T->leftchild->rightchild = NULL;
				T->leftchild->ltag = T->leftchild->rtag = 0;
				T->leftchild->data = chucun[i];
				i = CreateBittree(T->leftchild, chucun, len,++i);
			}
		else if (chucun[i] == '#')
			if (chucun[i - 1] != '#')
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
	return len;
}

void InOrderBittree(Bittree T,char s[100])
{
	if (T != NULL)
	{
		InOrderBittree(T->leftchild,s);
		s[m++] = T->data;
		cout << T->data;
		InOrderBittree(T->rightchild,s);
	}
}

void InThreding(Bittree T1)
{
	if (T1!=NULL)
	{
		InThreding(T1->leftchild);
		
		if (T1->leftchild==NULL)
		{
			T1->ltag = 1;
			T1->leftchild = pre;
		}
		if (T1->rightchild==NULL)
			T1->rtag = 1;
		if (pre != NULL && pre->rtag == 1)
			pre->rightchild = T1;
		pre = T1;
		InThreding(T1->rightchild);
		
	}
}

void inorder(Bittree T1,char chazhao)
{
	Bittree p = T1;
	while (p->ltag == 0&&p->leftchild!=NULL)
		p = p->leftchild;
	if (p->data == chazhao)
	{
		if (p->rightchild != NULL)
			cout << "succ is " << p->rightchild->data << p->rightchild->rtag << endl;
		else
			cout << "succ is NULL" << endl;
		if (p->leftchild!=NULL)
			cout << "prev is " << p->leftchild->data << p->leftchild->ltag << endl;
		else
			cout << "prev is NULL" << endl;
	}
	while (p->rightchild)
	{
		if (p->rtag == 0)
		{
			p = p->rightchild;
			while (p->ltag == 0)
				p = p->leftchild;
		}
		else
			p = p->rightchild;
		if (p->data == chazhao)
		{
			if (p->rightchild != NULL)
				cout << "succ is " << p->rightchild->data << p->rightchild->rtag << endl;
			else
				cout << "succ is NULL" << endl;
			if (p->leftchild != NULL)
				cout << "prev is " << p->leftchild->data << p->leftchild->ltag << endl;
			else
				cout << "prev is NULL" << endl;
		}
	}
}
*/

int main()
{
	/* Bittree T1;
	initBittree(T1);*/
	
	//cin >> chucun;
	//int chulen,i;
	//chulen = strlen(chucun);

	string s;
	cin >> s;
	cout << s.size() << endl;
	
	/*
	CreateBittree(T1, chucun,chulen,0);
	cin >> chazhao;
	InOrderBittree(T1,s);
	s[m] = '\0';
	cout << endl;
	for (i = 0; i < strlen(s); ++i)
		if (s[i] == chazhao)
			break;
	if (i == strlen(s))
	{
		cout << "Not found" << endl;
		return 0;
	}
	InThreding(T1);
	inorder(T1,chazhao);
	return 0;
	*/
	//cout << chulen << endl;
	return 0;
}