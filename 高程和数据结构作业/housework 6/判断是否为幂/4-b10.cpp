/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

int is_power(int num, int base)
{
	int sum;
	if (num == base)
		return 1;
	if (num < base)
		return 0;
	sum=is_power(num/base, base);
	return sum;
}

int main()
{
	int num, base;
	bool shifo = 1;
	cout << "请输入整数num及基数base" << endl;
	cin >> num >> base;
	shifo = is_power(num, base);
	if (shifo == 1)
		cout << num << "是" << base << "的幂" << endl;
	if (shifo == 0)
		cout << num << "不是" << base << "的幂" << endl;

	return 0;
}