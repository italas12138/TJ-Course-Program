/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str[33],*p;

	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;

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