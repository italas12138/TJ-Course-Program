/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

void dec_to_base_n(int num, int base)
{
	unsigned int a;
	a = (unsigned int)(num);
	int yushu;
	if(a<base)
		if (a >= 10)
		{
			cout << char(a - 10 + 'A');
			return;
		}
		else
		{
			cout << a;
			return;
		}	
	yushu =a % base;
	a = a / base;
	num = (int)(a);
	dec_to_base_n(num, base);
	if (yushu >= 10)
	{
		cout << char(yushu - 10 + 'A');
		return;
	}
	cout << yushu;
	return;

	
}

int main()
{
	int num, base;

	cout << "请输入十进制整数(int型)及要转换的进制[2..16]" << endl;
	cin >> num >> base;		//不考虑输入错误，num为int型范围任何值均可，base为2~16，不考虑10进制

	if (base == 10) //进制为10直接退出
		return -1;

	/* 完成进制转换并打印 */
	dec_to_base_n(num, base);
	cout << endl;

	return 0;
}