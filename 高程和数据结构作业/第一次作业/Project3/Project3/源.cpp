/* 2152118 �ƿ� ʷ���� */

#include <iostream>
using namespace std;

int main()
{
	int m, a, b;
	cout << "������һ��[1..30000]�������" << endl;
	cin >> m;
	a = m / 10000;
	b = m % 10000;
	cout << "��λ : " << a << endl;
	a = b / 1000;
	b = b % 1000;
	cout << "ǧλ : " << a << endl;
	a = b / 100;
	b = b % 100;
	cout << "��λ : " << a << endl;
	a = b / 10;
	b = b % 10;
	cout << "ʮλ : " << a << endl;
	cout << "��λ : " << b << endl;

	return 0;
}