/* 2152118 ʷ���� �ƿ� */
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
	cout << "����������num������base" << endl;
	cin >> num >> base;
	shifo = is_power(num, base);
	if (shifo == 1)
		cout << num << "��" << base << "����" << endl;
	if (shifo == 0)
		cout << num << "����" << base << "����" << endl;

	return 0;
}