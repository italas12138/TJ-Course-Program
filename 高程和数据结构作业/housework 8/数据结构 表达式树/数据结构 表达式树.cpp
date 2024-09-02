#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define stackinitsize 1000
#define stackaddsize 100
#define stackinitsize 100
#define stackaddsize 10

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

typedef struct Bitnode
{
	char data;
	struct Bitnode* leftchild, * rightchild;
}Bitnode, * Bittree;


typedef struct
{
	Bittree *top;
	Bittree *base;
	int stacksize;
}stackbittree;

int initstackbittree(stackbittree& s)
{
	s.base = (Bittree*)malloc(stackinitsize * sizeof(Bittree));
	if (!s.base)
		return -1;
	s.top = s.base;
	s.stacksize = stackinitsize;
	return 0;
}

int pushbittree(stackbittree& s, Bittree c)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (Bittree*)malloc((stackinitsize + stackaddsize) * sizeof(Bittree));
		if (!s.base)
			return -1;
		s.top = s.base + s.stacksize;
		s.stacksize += stackaddsize;
	}
	*s.top++ = c;
	return 0;
}

int popbittree(stackbittree& s)
{
	if (s.top == s.base)
		return -1;
	--s.top;
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


int initBittree(Bittree& T)
{
	T = (Bitnode*)malloc(sizeof(Bitnode));
	if (!T)
		return -1;
	T->leftchild = T->rightchild = NULL;
	return 0;
}

char bijiao(stack& caozuo, char c)
{
	switch (c)
	{
		case '+':
			if (*(caozuo.top - 1) == '('||caozuo.top==caozuo.base)
				return '>';
			return '<';
			break;
		case '-':
			if (*(caozuo.top - 1) == '(' || caozuo.top == caozuo.base)
				return '>';
			return '<';
			break;
		case '*':
			if (*(caozuo.top - 1) == '+' || *(caozuo.top - 1) == '-' || *(caozuo.top - 1) == '(' || caozuo.top == caozuo.base)
				return '>';
			return '<';
			break;
		case '/':
			if (*(caozuo.top - 1) == '+' || *(caozuo.top - 1) == '-' || *(caozuo.top - 1) == '(' || caozuo.top == caozuo.base)
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

void jisuan(stack& caozuo, stack& shuzi,stackbittree &tree)
{
	switch (*(caozuo.top - 1))
	{
		case '+':
		case '-':
		case '*':
		case '/':
			if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) == '1')
			{
				Bittree zhong;
				initBittree(zhong);
				zhong->leftchild = *(tree.top - 2);
				zhong->rightchild = *(tree.top - 1);
				zhong->data = *(caozuo.top - 1);
				popbittree(tree);
				popbittree(tree);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
			else if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) != '1')
			{
				Bittree zhong, right;
				initBittree(zhong);
				initBittree(right);
				zhong->leftchild = *(tree.top - 1);
				zhong->rightchild = right;
				right->data = *(shuzi.top - 1);
				zhong->data = *(caozuo.top - 1);
				popbittree(tree);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
			else if (*(shuzi.top - 2) != '1' && *(shuzi.top - 1) == '1')
			{
				Bittree zhong, left;
				initBittree(zhong);
				initBittree(left);
				zhong->rightchild = *(tree.top - 1);
				zhong->leftchild = left;
				left->data = *(shuzi.top - 2);
				zhong->data = *(caozuo.top - 1);
				popbittree(tree);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
			else
			{
				Bittree zhong, left, right;
				initBittree(zhong);
				initBittree(left);
				initBittree(right);
				zhong->rightchild = right;
				zhong->leftchild = left;
				left->data = *(shuzi.top - 2);
				right->data = *(shuzi.top - 1);
				zhong->data = *(caozuo.top - 1);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
	}
}

void CreateBittree(Bittree T1, char chucun[100], stack& caozuo, stack& shuzi,stackbittree& tree)
{
	int i=0;
	while (chucun[i] == '(')
	{
		push(caozuo, chucun[i]);
		++i;
	}
	T1->data = chucun[i];
	push(shuzi, '1');
	pushbittree(tree,T1);
	++i;
	while (i < strlen(chucun))
	{
		
		switch (chucun[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':
				switch (bijiao(caozuo, chucun[i]))
				{
					case '<':
						jisuan(caozuo, shuzi,tree);
						while (bijiao(caozuo, chucun[i]) == '<')
							jisuan(caozuo, shuzi,tree);
						push(caozuo, chucun[i]);
						break;
					case '>':
						push(caozuo, chucun[i]);
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
				break;
			default:
				push(shuzi, chucun[i]);
				break;
		}
		++i;
	}	
	while (caozuo.top != caozuo.base)
	{
		if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) == '1')
		{
			Bittree zhong;
			initBittree(zhong);
			zhong->leftchild = *(tree.top - 2);
			zhong->rightchild = *(tree.top - 1);
			zhong->data = *(caozuo.top - 1);
			popbittree(tree);
			popbittree(tree);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
		else if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) != '1')
		{
			Bittree zhong, right;
			initBittree(zhong);
			initBittree(right);
			zhong->leftchild = *(tree.top - 1);
			zhong->rightchild = right;
			right->data = *(shuzi.top - 1);
			zhong->data = *(caozuo.top - 1);
			popbittree(tree);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
		else if (*(shuzi.top - 2) != '1' && *(shuzi.top - 1) == '1')
		{
			Bittree zhong, left;
			initBittree(zhong);
			initBittree(left);
			zhong->rightchild = *(tree.top - 1);
			zhong->leftchild = left;
			left->data = *(shuzi.top - 2);
			zhong->data = *(caozuo.top - 1);
			popbittree(tree);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
		else
		{
			Bittree zhong, left, right;
			initBittree(zhong);
			initBittree(left);
			initBittree(right);
			zhong->rightchild = right;
			zhong->leftchild = left;
			left->data = *(shuzi.top - 2);
			right->data = *(shuzi.top - 1);
			zhong->data = *(caozuo.top - 1);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
	}
	return;
}

void InOrderBittree(Bittree T)
{
	if (T != NULL)
	{
		InOrderBittree(T->leftchild);
		cout << T->data;
		InOrderBittree(T->rightchild);
	}
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

void dayinBittree(Bittree T, int depth, squeue dayin)
{
	int i = depth,sum=1;
	while (i > 0)
	{
		sum *= 2;
		--i;
	}
	while (depth > 0)
	{
		int i;
		enqueue(dayin,T,100);
		i = dayin.rear;
		cout << setw(sum);
		cout<< T->data << endl;

		cout << setw(sum-1);
		if (T->leftchild == NULL)
			cout << " ";
		else
			cout <<"/";
		cout << " ";
		if (T->rightchild == NULL)
			cout << " ";
		else
			cout << "\\";
		cout <<endl;
		if (T->leftchild == NULL)
			cout << " ";
		else
			cout << T->leftchild->data;
		cout << setw(sum - 1);
		if (T->rightchild == NULL)
			cout << " " << endl;
		else
			cout << T->leftchild->data << endl;
	}
}

typedef struct
{
	Bittree* base;
	int front;
	int rear;
}squeue;

int initsqueue(squeue& s, int n)
{
	s.base = (Bittree*)malloc((n + 1) * sizeof(Bittree));
	if (!s.base)
		return -1;
	s.front = s.rear = 0;
	return 0;
}

int enqueue(squeue& s, Bittree T1, int n)
{
	if ((s.rear + 1) % (n + 1) == s.front)
		return -1;
	s.base[s.rear] = T1;
	s.rear = (s.rear + 1) % (n + 1);
	return 0;
}

int dequeue(squeue& s, int n)
{
	if (s.front == s.rear)
		return -1;
	s.front = (s.front + 1) % (n + 1);
	return 0;
}

char bijiao1(stack caozuo1, char c)
{
		switch (c)
		{
			case '+':
				if (*(caozuo1.top - 1) == '(' || caozuo1.top == caozuo1.base)
					return '>';
				return '<';
				break;
			case '-':
				if (*(caozuo1.top - 1) == '(' || caozuo1.top == caozuo1.base)
					return '>';
				return '<';
				break;
			case '*':
				if (*(caozuo1.top - 1) == '+' || *(caozuo1.top - 1) == '-' || *(caozuo1.top - 1) == '(' || caozuo1.top == caozuo1.base)
					return '>';
				return '<';
				break;
			case '/':
				if (*(caozuo1.top1 - 1) == '+' || *(caozuo1.top - 1) == '-' || *(caozuo1.top - 1) == '(' || caozuo1.top == caozuo1.base)
					return '>';
				return '<';
				break;
			case '(':
				return '>';
				break;
			case ')':
				if (*(caozuo1.top - 1) == '(')
					return '=';
				return '<';
				break;
		}

}

void jisuan(stack& caozuo, stack& shuzi, stackbittree& tree)
{
	switch (*(caozuo.top - 1))
	{
		case '+':
		case '-':
		case '*':
		case '/':
			if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) == '1')
			{
				Bittree zhong;
				initBittree(zhong);
				zhong->leftchild = *(tree.top - 2);
				zhong->rightchild = *(tree.top - 1);
				zhong->data = *(caozuo.top - 1);
				popbittree(tree);
				popbittree(tree);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
			else if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) != '1')
			{
				Bittree zhong, right;
				initBittree(zhong);
				initBittree(right);
				zhong->leftchild = *(tree.top - 1);
				zhong->rightchild = right;
				right->data = *(shuzi.top - 1);
				zhong->data = *(caozuo.top - 1);
				popbittree(tree);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
			else if (*(shuzi.top - 2) != '1' && *(shuzi.top - 1) == '1')
			{
				Bittree zhong, left;
				initBittree(zhong);
				initBittree(left);
				zhong->rightchild = *(tree.top - 1);
				zhong->leftchild = left;
				left->data = *(shuzi.top - 2);
				zhong->data = *(caozuo.top - 1);
				popbittree(tree);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
			else
			{
				Bittree zhong, left, right;
				initBittree(zhong);
				initBittree(left);
				initBittree(right);
				zhong->rightchild = right;
				zhong->leftchild = left;
				left->data = *(shuzi.top - 2);
				right->data = *(shuzi.top - 1);
				zhong->data = *(caozuo.top - 1);
				pushbittree(tree, zhong);
				pop(shuzi);
				pop(shuzi);
				pop(caozuo);
				push(shuzi, '1');
			}
	}
}

int jieguo(char chucun[100], char duibibiao[20], int duibi[20])
{
	stack caozuo1;
	stack shuzi1;
	int i = 0;
	while (chucun[i] == '(')
	{
		push(caozuo1, chucun[i]);
		++i;
	}
	++i;
	while (i < strlen(chucun))
	{

		switch (chucun[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':
				switch (bijiao(caozuo1, chucun[i]))
				{
					case '<':
						jisuan(caozuo1, shuzi1);
						while (bijiao(caozuo1, chucun[i]) == '<')
							jisuan(caozuo, shuzi, tree);
						push(caozuo, chucun[i]);
						break;
					case '>':
						push(caozuo, chucun[i]);
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
				break;
			default:
				push(shuzi, chucun[i]);
				break;
		}
		++i;
	}
	while (caozuo.top != caozuo.base)
	{
		if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) == '1')
		{
			Bittree zhong;
			initBittree(zhong);
			zhong->leftchild = *(tree.top - 2);
			zhong->rightchild = *(tree.top - 1);
			zhong->data = *(caozuo.top - 1);
			popbittree(tree);
			popbittree(tree);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
		else if (*(shuzi.top - 2) == '1' && *(shuzi.top - 1) != '1')
		{
			Bittree zhong, right;
			initBittree(zhong);
			initBittree(right);
			zhong->leftchild = *(tree.top - 1);
			zhong->rightchild = right;
			right->data = *(shuzi.top - 1);
			zhong->data = *(caozuo.top - 1);
			popbittree(tree);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
		else if (*(shuzi.top - 2) != '1' && *(shuzi.top - 1) == '1')
		{
			Bittree zhong, left;
			initBittree(zhong);
			initBittree(left);
			zhong->rightchild = *(tree.top - 1);
			zhong->leftchild = left;
			left->data = *(shuzi.top - 2);
			zhong->data = *(caozuo.top - 1);
			popbittree(tree);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
		else
		{
			Bittree zhong, left, right;
			initBittree(zhong);
			initBittree(left);
			initBittree(right);
			zhong->rightchild = right;
			zhong->leftchild = left;
			left->data = *(shuzi.top - 2);
			right->data = *(shuzi.top - 1);
			zhong->data = *(caozuo.top - 1);
			pushbittree(tree, zhong);
			pop(shuzi);
			pop(shuzi);
			pop(caozuo);
			push(shuzi, '1');
		}
	}
	return;
}



int main()
{
	char duibibiao[20];
	int duibi[20],geshu,jie;
	squeue dayin;
	initsqueue(dayin,100);
	int depth=0;
	stack shuzi,caozuo;
	stackbittree tree;
	Bittree T1;
	initstack(caozuo);
	initstack(shuzi);
	initstackbittree(tree);
	initBittree(T1);
	char chucun[100];
	cin >> chucun;
	cin >> geshu;
	for (int i = 0; i < geshu; ++i)
	{
		cin >> duibibiao[i];
		cin >> duibi[i];
	}
	jie=jieguo(chucun, duibibiao, duibi);
	CreateBittree(T1,chucun,caozuo,shuzi,tree);
	InOrderBittree(*(tree.top - 1));
	depth = Depth(*(tree.top - 1));
	dayinBittree(*(tree.top - 1),depth,dayin);

	cout << endl;
	return 0;
}




