/* 2152118 �ƿ� ʷ���� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int m, a, b;
	printf("������һ��[1..30000]�������\n");
	scanf("%d", &m);
	a = m / 10000;
	b = m % 10000;
	printf("��λ : ""%d\n", a);
	a = b / 1000;
	b = b % 1000;
	printf("ǧλ : ""%d\n", a);
	a = b / 100;
	b = b % 100;
	printf("��λ : ""%d\n", a);
	a = b / 10;
	b = b % 10;
	printf("ʮλ : ""%d\n", a);
	printf("��λ : ""%d\n", b);

	return 0;
}