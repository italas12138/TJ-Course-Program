/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double legendre(double x, int n)
{
	double sum;
	if (n==0)
		return 1;
	if (n==1)
		return x;
	sum = ((2 * n - 1) * x * legendre(x, n - 1) - (n - 1) * legendre(x, n - 2)) / n;
	return sum;
}

int main()
{
	double x;
	int n;
	printf("计算legendre，请输入x和n的值\n");
	scanf("%lf %d", &x, &n);
	printf("legendre[%d](%f)=%f\n", n, x, legendre( x, n));

	return 0;
}

