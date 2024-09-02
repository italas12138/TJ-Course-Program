/* 2152118 史君宝 计科 */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str[33],*p;

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;

	cin >> str;

	unsigned int result = 0;

	p = str;

	while (*p != '\0')
	{
		result = result * 2 + (*p - '0');
		++p;
	}

	cout << result << endl;

	return 0;
}