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

/* ��ֵ�Զ��� */
typedef struct {
	char key;	//��ʾ�������������
	int value;	//��ʾ����ֵ����ʽֵ
}Key_Value;

/* ���������� */
typedef struct Node {
	Key_Value elem;					//��ֵ��
	int height, no;					//�ڵ��������ڵ�ĸ߶ȣ�����ȫ�������ṹ�е����
	struct Node* rchild, * lchild;	//���Һ���
}Node, * BiTree;

/* ջ�Ķ��� */
typedef BiTree Elem;
typedef struct {
	Elem* buttom, * top;
	int capacity;
} Stack;

/* ���ж��壬��������Ӧ��ͬ���ͣ�ʹ��ģ�� */
template<class Elem_Type>
class Queue {
public:
	Elem_Type* head, * back, * front;
	int capacity;
};

/* ջ�Ĳ�����ʵ�� */
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

/* ���еĲ�����ʵ�� */
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

/* �������Ĳ�����ʵ�� */
Status initBiTree(BiTree& T)
{
	T = NULL;
	return OK;
}

/***************************************************************
��  �ܣ����ٶ�����
��  ����BiTree& T �����������ڵ�
����ֵ��Status ��״̬��OK��ERROR
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
��  �ܣ�������
��  ����int var1 ������1
		char opt �������
		int var2 ������2
����ֵ��int ��������
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
��  �ܣ�����һ����ջ��ջ����
��  ����Stack& Operator ��������ջ
		Stack& Operand ��������ջ
����ֵ��void
****************************************************************/
void calculate(Stack& Operator, Stack& Operand)
{
	BiTree top, lchild, rchild;
	popStack(Operator, top);
	popStack(Operand, rchild);
	popStack(Operand, lchild);

	top->lchild = lchild;		//ȷ�����ӹ�ϵ
	top->rchild = rchild;		//ȷ�����ӹ�ϵ
	top->elem.value = calculator(lchild->elem.value, top->elem.key, rchild->elem.value);	//������ʽ���
	pushStack(Operand, top);	//�����������ջ
}

/***************************************************************
��  �ܣ����ʽ����
��  ����Stack& Operator ��������ջ
		Stack& Operand ��������ջ
		BiTree nd �������������ڵ�(�ڲ��洢�����)
		const char* prior_opt �����ȼ��������½ڵ�����������������
����ֵ��void
****************************************************************/
void analyseExp(Stack& Operator, Stack& Operand, BiTree nd, const char* prior_opt)
{
	BiTree top = NULL;
	while (!StackEmpty(Operator)) {
		StackTop(Operator, top);
		if (strchr(prior_opt, top->elem.key))	//ջ����������ȼ�������nd�����������ջ��Ԫ�س�ջ���м���
			calculate(Operator, Operand);
		else									//ջ��Ԫ�����ȼ�����*��/��ֱ����ջ
			break;
	}//end of while
	pushStack(Operator, nd);
}

/***************************************************************
��  �ܣ�����������
��  ����BiTree& T ��������
		string& exp �����ʽ��
		int* vars ����¼����ֵ�Ĺ�ϣ��
����ֵ��Status ��״̬��OK��ERROR
****************************************************************/
Status createBiTree(BiTree& T, string& exp, int* vars)
{
	Stack Operator, Operand;	//���������ջ�Ͳ�����ջ
	initStack(Operator);
	initStack(Operand);
	if (createStack(Operator, exp.size()) == ERROR)		//����������ջ
		return ERROR;									//����ʧ��
	if (createStack(Operand, exp.size()) == ERROR) {	//����������ջ
		destroyStack(Operator);							//����ʧ��
		return ERROR;
	}
	/* Begin */

	Node* nd = NULL;
	Node lbracket = { '(' }, rbracket = { ')' };		//��������
	for (string::iterator it = exp.begin(); it != exp.end(); it++) {
		if (*it != '(' && *it != ')') {					//������ʱ������ڵ�
			if ((nd = (Node*)calloc(1, sizeof(Node))) == NULL) {	//����ڵ�
				clearStack(Operator, &rbracket, &lbracket);			//���������ջ������
				clearStack(Operand);								//���������ջ������
				destroyStack(Operator);
				destroyStack(Operand);
				return ERROR;
			}
			nd->elem.key = *it;							//��¼�������������
		}

		Node* top = NULL;
		/* ���ʽ���� */
		switch (*it) {
			/* ������ */
			case '(':
				pushStack(Operator, &lbracket);
				break;
				/* �˷����� */
			case '*':
			case '/':
				analyseExp(Operator, Operand, nd, "*/");	//���������
				break;
				/* �ӷ����� */
			case '+':
			case '-':
				analyseExp(Operator, Operand, nd, "*/+-");	//���������
				break;
				/* ������ */
			case ')':
				while (1) {
					StackTop(Operator, top);
					if (top == &lbracket) {//����������ֹͣ
						popStack(Operator, top);
						break;
					}
					calculate(Operator, Operand);			//����һ��
				}//end of while
				break;
				/* ����a-z */
			default: {
				if (nd)		//��if��Ϊ����������ʾ
					nd->elem.value = vars[*it - 'a'];
				pushStack(Operand, nd);
				break;
			}
		}//end of switch

		///* ��ӡջ������ */
		//printStack(Operator);
		//printStack(Operand);
		//cout << endl;
	}//end of for

	while (!StackEmpty(Operator))						//��������ջ��ʣ��Ԫ�س�ջ����
		calculate(Operator, Operand);
	popStack(Operand, T);								//���ղ�����ջʣ��һ��Ԫ�أ���Ϊ���ڵ�

	/* End */
	destroyStack(Operator);	//���ٲ�����ջ
	destroyStack(Operand);	//���ٲ�����ջ
	return OK;
}

/***************************************************************
��  �ܣ��������������
��  ����BiTree& T ��������
����ֵ��Status ��״̬��OK��ERROR
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
��  �ܣ�����������ڵ�ĸ߶Ⱥ�����ȫ�������еı��
��  ����BiTree& T ��������
		int height ���������ڵ�ĸ߶�
		int no ������ȫ�������еı��
����ֵ��Status ��״̬��OK��ERROR
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
��  �ܣ�����������������������
��  ����BiTree& T ��������
����ֵ��Status ��״̬��OK��ERROR
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

	int pos = 1;										//���ƫ����
	int depth = T->height;
	Node* nd = NULL, * old_nd = NULL;
	pushQueue(q, T);
	while (!QueueEmpty(q)) {
		popQueue(q, nd);
		if (nd->lchild)									//���Һ�����ջ
			pushQueue(q, nd->lchild);
		if (nd->rchild)
			pushQueue(q, nd->rchild);

		if (old_nd && old_nd->height != nd->height) {	//��������
			cout << endl;
			pos = 1;									//���ƫ������λ

			/* ��ӡ��֧��/ \ */
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

			pos = 1;									//���ƫ������λ
		}//end of if

		int key_pos = (1 << (nd->height - 1)) + nd->no % (1 << (depth - nd->height)) * (1 << nd->height);
		//			  +---------��ֵ--------+   +---------------����---------------+   +------����-----+
		while (pos++ < key_pos)							//����д��ѭ��������Ҫ��ѭ��������һ��pos++
			cout << " ";
		cout << nd->elem.key;
		if (nd->lchild && nd->rchild)					//��¼�������λ��
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
	string exp;								//���ʽ��
	int varNum = 0;							//��������
	char key = 0;							//������
	int values[max_num] = { 0 };			//����ֵ���Թ�ϣ��ʽ��
	cin >> exp >> varNum;
	for (int i = 0; i < varNum; i++) {
		cin >> key;
		cin >> values[key - 'a'];
	}

	BiTree T;
	/* ��ʼ�������� */
	initBiTree(T);

	/* ���������� */
	createBiTree(T, exp, values);

	///* ��ӡ������ */
	//printBiTree(T);

	/* ������������� */
	postOrderTraverse(T);
	cout << endl;

	/* Ϊ�ڵ��������ֵ */
	calcBiTreeHeightAndNo(T, BiTreeDepth(T), 1);

	///* ��ӡ������ */
	//printBiTree(T);

	/* ������������� */
	levelOrderTraverse(T);

	/* ������ʽ��� */
	cout << T->elem.value << endl;

	/* ���ٶ����� */
	destroyBiTree(T);

	return 0;
}