/* 2152118 �ƿ� ʷ���� */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double m;
	int a;
	cout << "������[1-100��)֮�������" << endl;
	cin >> m;
	a = m / 1e9;
	m -= a * 1e9;
	cout << "ʮ��λ : " << a << endl;
	a = m / 1e8;
	m -= a * 1e8;
	cout << "��λ   : " << a << endl;
	a = m / 1e7;
	m -= a * 1e7;
	cout << "ǧ��λ : " << a << endl;
	a = m / 1e6;
	m -= a * 1e6;
	cout << "����λ : " << a << endl;
	a = m / 1e5;
	m -= a * 1e5;
	cout << "ʮ��λ : " << a << endl;
	a = m / 1e4;
	m -= a * 1e4;
	cout << "��λ   : " << a << endl;
	a = m / 1e3;
	m -= a * 1e3;
	cout << "ǧλ   : " << a << endl;
	a = m / 1e2;
	m -= a * 1e2;
	cout << "��λ   : " << a << endl;
	a = m / 10;
	m -= a * 10;
	cout << "ʮλ   : " << a << endl;
	a = int(m);
	cout << "Բ     : " << a << endl;
	m -= a;
	a =int(m / 0.1+0.05);
	cout << "��     : " << a << endl;
	m -= a * 0.1;
	cout << "��     : " << int(m/0.01+0.005) << endl;
	return 0;

}