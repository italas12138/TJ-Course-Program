/* ¼Æ¿Æ 2152118 Ê·¾ý±¦ */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << setiosflags(ios::left);
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
			cout << j << "x" << i <<"=" << setw(4) << i * j;
		cout << endl;
	}

	return 0;
}