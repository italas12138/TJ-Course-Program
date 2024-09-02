/* 2152118 计科 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double m;
	int a;
	printf("请输入[1-100亿)之间的数字\n");
	scanf("%lf",&m);
	a = m / 1e9;
	m -= a * 1e9;
	printf("十亿位 : ""%d\n",a);
	a = m / 1e8;
	m -= a * 1e8;
	printf("亿位   : ""%d\n", a);
	a = m / 1e7;
	m -= a * 1e7;
	printf("千万位 : ""%d\n", a);
	a = m / 1e6;
	m -= a * 1e6;
	printf("百万位 : ""%d\n", a);
	a = m / 1e5;
	m -= a * 1e5;
	printf("十万位 : ""%d\n", a);
	a = m / 1e4;
	m -= a * 1e4;
	printf("万位   : ""%d\n", a);
	a = m / 1e3;
	m -= a * 1e3;
	printf("千位   : ""%d\n", a);
	a = m / 1e2;
	m -= a * 1e2;
	printf("百位   : ""%d\n", a);
	a = m / 10;
	m -= a * 10;
	printf("十位   : ""%d\n", a);
	a = (int) m;
	printf("圆     : ""%d\n", a);
	m -= a;
	a = (int) (m / 0.1 + 0.05);
	printf("角     : ""%d\n", a);
	m -= a * 0.1;
	printf("分     : ""%d\n", (int) (m / 0.01 + 0.005));

	return 0;
}