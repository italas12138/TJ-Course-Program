/* 2152118 ʷ���� �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void convert(int n)
{
	int fuhao = 1;
	char shuchu;
	if (n < 0)
	{
		fuhao = 0;
		n = fabs(n);
	}
	if (!n)
		return;
	if (n < 0)
	{
		fuhao = 1;
		shuchu = 48 - n % 10;
	}
	else
		shuchu = 48 + n % 10;
	printf("%c ", shuchu);
	convert(n / 10);
	if (fuhao == 0)
		printf("- ");
	return;
}

int main()
{
	int n;
	printf("������һ������\n");
	scanf("%d", &n);

	convert(n);
	printf("\n");

	return 0;
}