#include <iostream>
using namespace std;
int main()
{
	for (int i = 0; i < 100000; ++i)
	{
		int a;
		a = rand() % 2;
		cout << a;
	}
}