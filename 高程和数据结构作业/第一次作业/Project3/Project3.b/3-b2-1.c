/* 2152118 计科 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int m, a, b;
	printf("请输入一个[1..30000]间的整数\n");
	scanf("%d", &m);
	a = m / 10000;
	b = m % 10000;
	printf("万位 : ""%d\n", a);
	a = b / 1000;
	b = b % 1000;
	printf("千位 : ""%d\n", a);
	a = b / 100;
	b = b % 100;
	printf("百位 : ""%d\n", a);
	a = b / 10;
	b = b % 10;
	printf("十位 : ""%d\n", a);
	printf("个位 : ""%d\n", b);

	return 0;
}