/* 2152118 计科 史君宝 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double m;
	int a;
	cout << "请输入[1-100亿)之间的数字" << endl;
	cin >> m;
	a = m / 1e9;
	m -= a * 1e9;
	cout << "十亿位 : " << a << endl;
	a = m / 1e8;
	m -= a * 1e8;
	cout << "亿位   : " << a << endl;
	a = m / 1e7;
	m -= a * 1e7;
	cout << "千万位 : " << a << endl;
	a = m / 1e6;
	m -= a * 1e6;
	cout << "百万位 : " << a << endl;
	a = m / 1e5;
	m -= a * 1e5;
	cout << "十万位 : " << a << endl;
	a = m / 1e4;
	m -= a * 1e4;
	cout << "万位   : " << a << endl;
	a = m / 1e3;
	m -= a * 1e3;
	cout << "千位   : " << a << endl;
	a = m / 1e2;
	m -= a * 1e2;
	cout << "百位   : " << a << endl;
	a = m / 10;
	m -= a * 10;
	cout << "十位   : " << a << endl;
	a = int(m);
	cout << "圆     : " << a << endl;
	m -= a;
	a =int(m / 0.1+0.05);
	cout << "角     : " << a << endl;
	m -= a * 0.1;
	cout << "分     : " << int(m/0.01+0.005) << endl;
	return 0;

}