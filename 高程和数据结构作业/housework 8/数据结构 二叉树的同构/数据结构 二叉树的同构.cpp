#include <iostream>
using namespace std;

char a[10000];
int b[10000], c[10000];
int w, v, x;
typedef struct Bitnode{
	char data;
	struct Bitnode*leftchild, *rightchild;
}Bitnode,*Bittree;

int initBittree(Bittree& T)
{
	T = (Bitnode*)malloc(sizeof(Bitnode));
	if (!T)
		return -1;
	T->leftchild = T->rightchild = NULL;
	return 0;
}

void Exchange(Bittree& T)
{
	Bittree S;
	if (T)
	{
		S = T->leftchild;
		T->leftchild = T->rightchild;
		T->rightchild = S;
	}
}
void CreateBittree(Bittree& T, char a[],int b[],int c[], int i)
{
	if (b[i] >= 0)
	{
		T->leftchild = (Bitnode*)malloc(sizeof(Bitnode));
		T->leftchild->data =a[b[i]];
		CreateBittree(T->leftchild, a,b,c,b[i]);
	}
	else
		T->leftchild = NULL;
	if (c[i]>=0)
	{
		T->rightchild = (Bitnode*)malloc(sizeof(Bitnode));
		T->rightchild->data = a[c[i]];
		CreateBittree(T->rightchild, a,b,c, c[i]);
	}
	else
		T->rightchild = NULL;
	return;
}

int Depth(Bittree& T)
{
	int depl, depr;
	if (T)
	{
		depl = Depth(T->leftchild);
		depr = Depth(T->rightchild);
		if (depl >= depr)
			return depl + 1;
		else
			return depr + 1;
	}
	return 0;
}

int exchangeBittree(Bittree& T1, Bittree& T2)
{
	if (T1->leftchild != NULL)
	{
		if ((T2->leftchild != NULL && T2->rightchild != NULL))
		{
			if (T1->leftchild->data != T2->leftchild->data)
				Exchange(T2);
		}
		else if (T2->leftchild == NULL)
			Exchange(T2);
	}
	else if (T1->rightchild != NULL)
	{
		if ((T2->leftchild != NULL && T2->rightchild != NULL))
		{
			if (T1->rightchild->data != T2->rightchild->data)
				Exchange(T2);
		}
		else if (T2->rightchild == NULL)
			Exchange(T2);
	}
	if(T1->leftchild != NULL&& T2->leftchild != NULL)
		exchangeBittree(T1->leftchild, T2->leftchild);
	if (T1->rightchild != NULL && T2->rightchild != NULL)
		exchangeBittree(T1->rightchild, T2->rightchild);
	return 0;
}

int bijiaoBittree(Bittree& T1, Bittree& T2)
{
	++w;
	if (T1->leftchild != NULL || T2->leftchild != NULL)
		if (T1->leftchild != NULL && T2->leftchild != NULL)
			if (T1->leftchild->data == T2->leftchild->data)
			{
				int a;
				++v;
				a = bijiaoBittree(T1->leftchild, T2->leftchild);
				if (a < 0)
					return -1;
			}
			else
				return -1;
		else
			return -1;
	else if (T1->rightchild != NULL || T2->rightchild != NULL)
		if (T1->rightchild != NULL && T2->rightchild != NULL)
			if (T1->rightchild->data == T2->rightchild->data)
			{
				int b;
				++x;
				b=bijiaoBittree(T1->rightchild, T2->rightchild);
				if (b < 0)
					return -1;
			}
			else
				return -1;
		else
			return -1;
	else
		return 0;
	return 0;
}

int main()

{
	Bittree T1, T2;
	initBittree(T1);
	initBittree(T2);
	int geshu,bijiaozhi=1, depT1, depT2;
	int sumt1 = 0, sumt2 = 0,t1,t2;
 	cin >> geshu;
	cin.clear();
	cin.ignore();
	for (int i = 0; i < geshu; ++i)
	{
		cin >> a[i];
		cin >> b[i];
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore();
			b[i] = -1;
		}
		if(b[i]>=0)
			sumt1 += b[i];
		cin >> c[i];
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore();
			c[i] = -1;
		}
		if (c[i] >= 0)
			sumt1 += c[i];
	}
	t1 = geshu * (geshu - 1) / 2 - sumt1;
	T1->data = a[t1];
	CreateBittree(T1, a,b,c,t1);
	cin >> geshu;
	cin.clear();
	cin.ignore();
	for (int i = 0; i < geshu; ++i)
	{
		cin >> a[i];
		cin >> b[i];
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore();
			b[i] = -1;
		}
		if (b[i] >= 0)
			sumt2 += b[i];
		cin >> c[i];
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore();
			c[i] = -1;
		}
		if (c[i] >= 0)
			sumt2 += c[i];
	}
	t2 = geshu * (geshu - 1) / 2 - sumt2;
	T2->data = a[t2];
	CreateBittree(T2, a,b,c, t2);
	exchangeBittree(T1, T2);
	bijiaozhi = bijiaoBittree(T1, T2);
	if (bijiaozhi == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	depT1 = Depth(T1);
	depT2 = Depth(T2);
	cout << depT1 << endl;
	cout << depT2 << endl;
	cout << w << " " << v << " " << x;
	return 0;
}