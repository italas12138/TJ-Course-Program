#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

#include <iostream>
using namespace std;

struct SqList {
	int* elem;
	int length;
	int Listsize;
};


int CreateList(SqList& l,int n) {
	l.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!l.elem)
		return 0;
	l.length = n;
	l.Listsize = LIST_INIT_SIZE;
	for (int i = 0; i < n; ++i)
		cin >> l.elem[i];
	return 1;
}

int locateElem(SqList& l,int b) {
	for (int i = 0; i < l.length; ++i)
		if (l.elem[i] == b)
			return i + 1;
}

void listdelete(SqList& l, int b) {
	for (int i = b; i < l.length; ++i)
		l.elem[i - 1] = l.elem[i];
	--l.length;
}

void ListInsert(SqList& l, int i, int a) {
	int j;
	++l.length;
	for (j = l.length - 1; j >=i; --j)
		l.elem[j] = l.elem[j - 1];
	l.elem[j-1] = a;
}

int main()
{
	struct SqList l;
	l.elem = NULL;
	l.length = 0;
	l.Listsize = 0;
	int n,a,b;
	cout << "ÊäÈëÕûÊýn" << endl;
	cin >> n;
	CreateList(l,n);
	for (int i = 0; i < l.length; ++i) {
		a = l.elem[i];
		for (int j = i; j < l.length; ++j) {
			b = locateElem(l, a);
			listdelete(l, b);
		}
		ListInsert(l, i, a);
	}
	for (int i = 0; i < l.length; ++i)
		cout << l.elem[i] << " ";
	cout << endl;
	return 0;
}