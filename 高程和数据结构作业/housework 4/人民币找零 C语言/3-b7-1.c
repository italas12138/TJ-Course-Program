/* 2152118 �ƿ� ʷ���� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double y, m;
	int a, a50 = 0, a20 = 0, a10 = 0, a5 = 0, a1 = 0, b5 = 0, b1 = 0, c5 = 0, c2 = 0, c1 = 0, sum = 0;
	printf("����������ֵ��\n");
	scanf("%lf", &y);
	a = (int)y;
	m = y - a;
	if (a - 50 >= 0) 
	{
		a -= 50;
		a50++;
	}
	if (a - 20 >= 0) 
	{
		a -= 20;
		a20++;
	}
	if (a - 20 >= 0) 
	{
		a -= 20;
		a20++;
	}
	if (a - 10 >= 0) 
	{
		a -= 10;
		a10++;
	}
	if (a - 5 >= 0) 
	{
		a -= 5;
		a5++;
	}
	if (a - 1 >= 0) 
	{
		a -= 1;
		a1++;
	}
	if (a - 1 >= 0) 
	{
		a -= 1;
		a1++;
	}
	if (a - 1 >= 0) 
	{
		a -= 1;
		a1++;
	}
	if (a - 1 >= 0) 
	{
		a -= 1;
		a1++;
	}
	if (m - 0.5 >= 0) 
	{
		m -= 0.5;
		b5++;
	}
	if (m - 0.1 >= 0) 
	{
		m -= 0.1;
		b1++;
	}
	if (m - 0.1 >= 0) 
	{
		m -= 0.1;
		b1++;
	}
	if (m - 0.1 >= 0) 
	{
		m -= 0.1;
		b1++;
	}
	if (m - 0.1 >= 0) 
	{
		m -= 0.1;
		b1++;
	}
	if (m - 0.05 >= 0) 
	{
		m -= 0.05;
		c5++;
	}
	if (m - 0.02 >= 0) 
	{
		m -= 0.02;
		c2++;
	}
	if (m - 0.02 >= 0) 
	{
		m -= 0.02;
		c2++;
	}
	if (m - 0.01 >= 0) 
	{
		m -= 0.01;
		c1++;
	}
	sum = a50 + a20 + a10 + a5 + a1 + b5 + b1 + c5 + c2 + c1;
	printf("��%d�����㣬�������£�\n",sum);
	if (a50 != 0)
		printf("50Ԫ : %d��\n",a50);
	if (a20 != 0)
		printf("20Ԫ : %d��\n",a20);
	if (a10 != 0)
		printf("10Ԫ : %d��\n",a10);
	if (a5 != 0)
		printf("5Ԫ  : %d��\n",a5);
	if (a1 != 0)
		printf("1Ԫ  : %d��\n",a1);
	if (b5 != 0)
		printf("5��  : %d��\n",b5);
	if (b1 != 0)
		printf("1��  : %d��\n",b1);
	if (c5 != 0)
		printf("5��  : %d��\n",c5);
	if (c2 != 0)
		printf("2��  : %d��\n",c2);
	if (c1 != 0)
		printf("1��  : %d��\n",c1);

	return 0;
}