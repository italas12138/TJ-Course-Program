/* 2152118 �ƿ� ʷ���� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double m;
	int a;
	printf("������[1-100��)֮�������\n");
	scanf("%lf",&m);
	a = m / 1e9;
	m -= a * 1e9;
	printf("ʮ��λ : ""%d\n",a);
	a = m / 1e8;
	m -= a * 1e8;
	printf("��λ   : ""%d\n", a);
	a = m / 1e7;
	m -= a * 1e7;
	printf("ǧ��λ : ""%d\n", a);
	a = m / 1e6;
	m -= a * 1e6;
	printf("����λ : ""%d\n", a);
	a = m / 1e5;
	m -= a * 1e5;
	printf("ʮ��λ : ""%d\n", a);
	a = m / 1e4;
	m -= a * 1e4;
	printf("��λ   : ""%d\n", a);
	a = m / 1e3;
	m -= a * 1e3;
	printf("ǧλ   : ""%d\n", a);
	a = m / 1e2;
	m -= a * 1e2;
	printf("��λ   : ""%d\n", a);
	a = m / 10;
	m -= a * 10;
	printf("ʮλ   : ""%d\n", a);
	a = (int) m;
	printf("Բ     : ""%d\n", a);
	m -= a;
	a = (int) (m / 0.1 + 0.05);
	printf("��     : ""%d\n", a);
	m -= a * 0.1;
	printf("��     : ""%d\n", (int) (m / 0.01 + 0.005));

	return 0;
}