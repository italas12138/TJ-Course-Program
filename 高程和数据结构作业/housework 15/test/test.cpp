#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a[5]={0};
	for (int i = 0; i < 5; ++i)
		a[i] = i;

	int* p = a;
	for (int i = 0; i < 7; ++i)
		cout << *(p+i) << " ";
	cout << endl;

	return 0;
} 