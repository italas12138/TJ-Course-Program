/* 2152118 计科 史君宝 */

#include <iostream>
using namespace std;

int main()
{
	int m, a, b;
	cout << "请输入一个[1..30000]间的整数" << endl;
	cin >> m;
	a = m / 10000;
	b = m % 10000;
	cout << "万位 : " << a << endl;
	a = b / 1000;
	b = b % 1000;
	cout << "千位 : " << a << endl;
	a = b / 100;
	b = b % 100;
	cout << "百位 : " << a << endl;
	a = b / 10;
	b = b % 10;
	cout << "十位 : " << a << endl;
	cout << "个位 : " << b << endl;

	return 0;
}