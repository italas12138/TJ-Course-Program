/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <cmath>
using namespace std;

void convert(int n)
{
	
		
	if (n < 0&& n != -2147483648)
	{
		n = abs(n);
		cout << "-" << " ";
	}
	char shuchu;
	if (!n )
		return;
	convert(n / 10);
	if (n != -2147483648)
		shuchu = 48 + n % 10;
	else
		shuchu = 48 - n % 10;
	cout << shuchu << " ";
	return;
}

int main()
{
	int n;
	cout << "������һ������" << endl;
	cin >> n;

	convert(n);
	cout << endl;

	return 0;
}