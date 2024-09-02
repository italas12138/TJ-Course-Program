#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int max_num = 26;

#define OK		1
#define ERROR	0

typedef int Status;

/* 键值对定义 */
typedef struct {
	char key;	//表示变量名或运算符
	int value;	//表示变量值或表达式值
}Key_Value;

/* 二叉树定义 */
typedef struct Node {
	Key_Value elem;					//键值对
	int height, no;					//节点相对最深节点的高度，在完全二叉树结构中的序号
	struct Node* rchild, * lchild;	//左右孩子
}Node, * BiTree;

/* 栈的定义 */
typedef BiTree Elem;
typedef struct {
	Elem* buttom, * top;
	int capacity;
} Stack;

/* 队列定义，由于需适应不同类型，使用模板 */
template<class Elem_Type>
class Queue {
public:
	Elem_Type* head, * back, * front;
	int capacity;
};

/* 栈的操作集实现 */
Status initStack(Stack& s)
{
	s.buttom = s.top = NULL;
	s.capacity = 0;
	return OK;
}

Status createStack(Stack& s, int capacity)
{
	if (capacity <= 0 || (s.buttom = (Elem*)malloc(capacity * sizeof(Elem))) == NULL)
		return ERROR;

	s.top = s.buttom;
	s.capacity = capacity;
	return OK;
}

Status destroyStack(Stack& s)
{
	if (s.buttom) {
		free(s.buttom);
		s.buttom = s.top = NULL;
		s.capacity = 0;
	}
	return OK;
}

Status pushStack(Stack& s, Elem elem)
{
	if (s.top - s.buttom >= s.capacity)
		return ERROR;
	*(s.top++) = elem;
	return OK;
}

Status popStack(Stack& s, Elem& elem)
{
	if (s.top <= s.buttom)
		return ERROR;
	elem = *(--s.top);
	return OK;
}

Status StackTop(Stack& s, Elem& elem)
{
	if (s.top <= s.buttom)
		return ERROR;
	elem = *(s.top - 1);
	return OK;
}

bool StackEmpty(Stack& s)
{
	return s.top == s.buttom;
}

int StackSize(Stack& s)
{
	return s.top - s.buttom;
}

Status printStack(Stack& s)
{
	for (Elem* p = s.buttom; p != s.top; p++) {
		cout << "(" << (*p)->elem.key << " : " << (*p)->elem.value << ") ";
	}
	cout << endl;
	return OK;
}

/* 队列的操作集实现 */
template<class Elem_Type>
Status initQueue(Queue<Elem_Type>& q)
{
	q.head = q.front = q.back = NULL;
	q.capacity = 0;
	return OK;
}

template<class Elem_Type>
Status createQueue(Queue<Elem_Type>& q, int capacity)
{
	if (capacity <= 0 || (q.head = (Elem_Type*)malloc(capacity * sizeof(Elem_Type))) == NULL)
		return ERROR;

	q.front = q.back = q.head;
	q.capacity = capacity;
	return OK;
}

template<class Elem_Type>
Status destroyQueue(Queue<Elem_Type>& q)
{
	if (q.head) {
		free(q.head);
		q.head = q.front = q.back = NULL;
		q.capacity = 0;
	}
	return OK;
}

template<class Elem_Type>
Status pushQueue(Queue<Elem_Type>& q, Elem_Type elem)
{
	if (q.front - q.head >= q.capacity)
		return ERROR;
	*(q.front++) = elem;
	return OK;
}

template<class Elem_Type>
Status popQueue(Queue<Elem_Type>& q, Elem_Type& elem)
{
	if (q.back >= q.front)
		return ERROR;
	elem = *(q.back++);
	return OK;
}

template<class Elem_Type>
Status QueueFront(Queue<Elem_Type>& q, Elem_Type& elem)
{
	if (q.back >= q.front)
		return ERROR;
	elem = *(q.front - 1);
	return OK;
}

template<class Elem_Type>
Status QueueBack(Queue<Elem_Type>& q, Elem_Type& elem)
{
	if (q.back >= q.front)
		return ERROR;
	elem = *q.back;
	return OK;
}

template<class Elem_Type>
bool QueueEmpty(Queue<Elem_Type>& q)
{
	return q.back == q.front;
}

template<class Elem_Type>
int QueueSize(Queue<Elem_Type>& q)
{
	return q.front - q.back;
}

/* 二叉树的操作集实现 */
Status initBiTree(BiTree& T)
{
	T = NULL;
	return OK;
}

/***************************************************************
功  能：销毁二叉树
参  数：BiTree& T ：二叉树根节点
返回值：Status ：状态，OK或ERROR
****************************************************************/
Status destroyBiTree(BiTree& T)
{
	if (T) {
		destroyBiTree(T->lchild);
		destroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return OK;
}

Status clearStack(Stack& s, Node* rbracket = NULL, Node* lbracket = NULL)
{
	Node* nd = NULL;
	while (StackEmpty(s)) {
		popStack(s, nd);
		if (nd == rbracket || nd == lbracket)
			continue;
		free(nd);
	}//end of while
	return OK;
}

/***************************************************************
功  能：计算器
参  数：int var1 ：变量1
		char opt ：运算符
		int var2 ：变量2
返回值：int ：计算结果
****************************************************************/
int calculator(int var1, char opt, int var2)
{
	switch (opt) {
		case '+':
			return var1 + var2;
		case '-':
			return var1 - var2;
		case '*':
			return var1 * var2;
		case '/':
			return var1 / var2;
		default:
			return 0;
	}
}

/***************************************************************
功  能：进行一次入栈出栈计算
参  数：Stack& Operator ：操作符栈
		Stack& Operand ：操作数栈
返回值：void
****************************************************************/
void calculate(Stack& Operator, Stack& Operand)
{
	BiTree top, lchild, rchild;
	popStack(Operator, top);
	popStack(Operand, rchild);
	popStack(Operand, lchild);

	top->lchild = lchild;		//确定父子关系
	top->rchild = rchild;		//确定父子关系
	top->elem.value = calculator(lchild->elem.value, top->elem.key, rchild->elem.value);	//计算表达式结果
	pushStack(Operand, top);	//将结果重新入栈
}

/***************************************************************
功  能：表达式分析
参  数：Stack& Operator ：操作符栈
		Stack& Operand ：操作数栈
		BiTree nd ：新增二叉树节点(内部存储运算符)
		const char* prior_opt ：优先级不低于新节点中运算符的运算符集
返回值：void
****************************************************************/
void analyseExp(Stack& Operator, Stack& Operand, BiTree nd, const char* prior_opt)
{
	BiTree top = NULL;
	while (!StackEmpty(Operator)) {
		StackTop(Operator, top);
		if (strchr(prior_opt, top->elem.key))	//栈顶运算符优先级不低于nd的运算符，将栈顶元素出栈进行计算
			calculate(Operator, Operand);
		else									//栈顶元素优先级低于*和/，直接入栈
			break;
	}//end of while
	pushStack(Operator, nd);
}

/***************************************************************
功  能：构建二叉树
参  数：BiTree& T ：二叉树
		string& exp ：表达式串
		int* vars ：记录变量值的哈希表
返回值：Status ：状态，OK或ERROR
****************************************************************/
Status createBiTree(BiTree& T, string& exp, int* vars)
{
	Stack Operator, Operand;	//定义操作符栈和操作数栈
	initStack(Operator);
	initStack(Operand);
	if (createStack(Operator, exp.size()) == ERROR)		//构建操作符栈
		return ERROR;									//申请失败
	if (createStack(Operand, exp.size()) == ERROR) {	//构建操作数栈
		destroyStack(Operator);							//申请失败
		return ERROR;
	}
	/* Begin */

	Node* nd = NULL;
	Node lbracket = { '(' }, rbracket = { ')' };		//左右括号
	for (string::iterator it = exp.begin(); it != exp.end(); it++) {
		if (*it != '(' && *it != ')') {					//非括号时，申请节点
			if ((nd = (Node*)calloc(1, sizeof(Node))) == NULL) {	//申请节点
				clearStack(Operator, &rbracket, &lbracket);			//清除操作符栈中内容
				clearStack(Operand);								//清除操作数栈中内容
				destroyStack(Operator);
				destroyStack(Operand);
				return ERROR;
			}
			nd->elem.key = *it;							//记录变量名或运算符
		}

		Node* top = NULL;
		/* 表达式分析 */
		switch (*it) {
			/* 右括号 */
			case '(':
				pushStack(Operator, &lbracket);
				break;
				/* 乘法除法 */
			case '*':
			case '/':
				analyseExp(Operator, Operand, nd, "*/");	//运算符分析
				break;
				/* 加法减法 */
			case '+':
			case '-':
				analyseExp(Operator, Operand, nd, "*/+-");	//运算符分析
				break;
				/* 左括号 */
			case ')':
				while (1) {
					StackTop(Operator, top);
					if (top == &lbracket) {//遇到左括号停止
						popStack(Operator, top);
						break;
					}
					calculate(Operator, Operand);			//计算一次
				}//end of while
				break;
				/* 变量a-z */
			default: {
				if (nd)		//本if仅为消除智能提示
					nd->elem.value = vars[*it - 'a'];
				pushStack(Operand, nd);
				break;
			}
		}//end of switch

		///* 打印栈的内容 */
		//printStack(Operator);
		//printStack(Operand);
		//cout << endl;
	}//end of for

	while (!StackEmpty(Operator))						//将操作符栈中剩余元素出栈计算
		calculate(Operator, Operand);
	popStack(Operand, T);								//最终操作数栈剩余一个元素，即为根节点

	/* End */
	destroyStack(Operator);	//销毁操作符栈
	destroyStack(Operand);	//销毁操作数栈
	return OK;
}

/***************************************************************
功  能：后序遍历二叉树
参  数：BiTree& T ：二叉树
返回值：Status ：状态，OK或ERROR
****************************************************************/
Status postOrderTraverse(BiTree& T)
{
	if (T) {
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		cout << T->elem.key;
	}
	return OK;
}

Status printBiTree(BiTree root, int depth = 1)
{
	cout << setfill('|');
	if (root) {
		cout << setw(depth + 1) << "--" << root->elem.key << " : " << root->elem.value
			<< "(height:" << root->height << " no:" << root->no << endl;
		printBiTree(root->lchild, depth + 1);
		printBiTree(root->rchild, depth + 1);
	}
	//else
	//	cout << setw(depth + 1) << "--" << "*" << endl;
	return OK;
}

int BiTreeDepth(BiTree& T)
{
	if (!T)
		return 0;
	else
		return max(BiTreeDepth(T->lchild), BiTreeDepth(T->rchild)) + 1;
}

/***************************************************************
功  能：计算二叉树节点的高度和在完全二叉树中的编号
参  数：BiTree& T ：二叉树
		int height ：相对最深节点的高度
		int no ：在完全二叉树中的编号
返回值：Status ：状态，OK或ERROR
****************************************************************/
Status calcBiTreeHeightAndNo(BiTree& T, int height, int no)
{
	if (T) {
		T->height = height;
		T->no = no;
		calcBiTreeHeightAndNo(T->lchild, height - 1, 2 * no);
		calcBiTreeHeightAndNo(T->rchild, height - 1, 2 * no + 1);
	}
	return OK;
}

/***************************************************************
功  能：层序遍历二叉树输出二叉树
参  数：BiTree& T ：二叉树
返回值：Status ：状态，OK或ERROR
****************************************************************/
Status levelOrderTraverse(BiTree& T)
{
	Queue<BiTree> q;
	initQueue(q);
	createQueue(q, 1 << T->height);
	Queue<int> q_pos;
	initQueue(q_pos);
	createQueue(q_pos, 1 << T->height);
	/* Begin */

	int pos = 1;										//光标偏移量
	int depth = T->height;
	Node* nd = NULL, * old_nd = NULL;
	pushQueue(q, T);
	while (!QueueEmpty(q)) {
		popQueue(q, nd);
		if (nd->lchild)									//左右孩子入栈
			pushQueue(q, nd->lchild);
		if (nd->rchild)
			pushQueue(q, nd->rchild);

		if (old_nd && old_nd->height != nd->height) {	//层数增加
			cout << endl;
			pos = 1;									//光标偏移量复位

			/* 打印分支线/ \ */
			while (!QueueEmpty(q_pos)) {
				int key_pos;
				popQueue(q_pos, key_pos);
				while (pos++ < key_pos - 1)
					cout << " ";
				cout << "/";
				while (pos++ < key_pos + 1)
					cout << " ";
				cout << "\\";
			}//end of while
			cout << endl;

			pos = 1;									//光标偏移量复位
		}//end of if

		int key_pos = (1 << (nd->height - 1)) + nd->no % (1 << (depth - nd->height)) * (1 << nd->height);
		//			  +---------初值--------+   +---------------步数---------------+   +------步长-----+
		while (pos++ < key_pos)							//自增写入循环，不需要在循环外额外加一句pos++
			cout << " ";
		cout << nd->elem.key;
		if (nd->lchild && nd->rchild)					//记录运算符的位置
			pushQueue(q_pos, key_pos);

		old_nd = nd;
	}//end of while
	cout << endl;

	/* End */
	destroyQueue(q);
	destroyQueue(q_pos);
	return OK;
}

int main()
{
	string exp;								//表达式串
	int varNum = 0;							//变量个数
	char key = 0;							//变量名
	int values[max_num] = { 0 };			//变量值，以哈希表方式存
	cin >> exp >> varNum;
	for (int i = 0; i < varNum; i++) {
		cin >> key;
		cin >> values[key - 'a'];
	}

	BiTree T;
	/* 初始化二叉树 */
	initBiTree(T);

	/* 构建二叉树 */
	createBiTree(T, exp, values);

	///* 打印二叉树 */
	//printBiTree(T);

	/* 后序遍历二叉树 */
	postOrderTraverse(T);
	cout << endl;

	/* 为节点添加特殊值 */
	calcBiTreeHeightAndNo(T, BiTreeDepth(T), 1);

	///* 打印二叉树 */
	//printBiTree(T);

	/* 层序遍历二叉树 */
	levelOrderTraverse(T);

	/* 输出表达式结果 */
	cout << T->elem.value << endl;

	/* 销毁二叉树 */
	destroyBiTree(T);

	return 0;
}