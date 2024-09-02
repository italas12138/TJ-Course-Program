/* 2152118 Ê·¾ý±¦ ¼Æ¿Æ */
#include <iostream>
using namespace std;

int main()
{
	int s[100] = { 0 };
	for (int x = 1; x <= 100; ++x)
		for (int y = 0; y < 100; ++y)
			if ((y + 1) % x == 0)
				++s[y];
	for(int x=0,y=0;x<100;++x)
		if (s[x] % 2 == 1)
		{
			++y;
			if (y == 1)
			{
				cout << x + 1;
				continue;
			}
			cout <<" "<< x + 1;
		}
	cout << endl;

	return 0;
}