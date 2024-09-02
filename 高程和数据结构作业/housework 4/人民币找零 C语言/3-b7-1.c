/* 2152118 计科 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double y, m;
	int a, a50 = 0, a20 = 0, a10 = 0, a5 = 0, a1 = 0, b5 = 0, b1 = 0, c5 = 0, c2 = 0, c1 = 0, sum = 0;
	printf("请输入找零值：\n");
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
	printf("共%d张找零，具体如下：\n",sum);
	if (a50 != 0)
		printf("50元 : %d张\n",a50);
	if (a20 != 0)
		printf("20元 : %d张\n",a20);
	if (a10 != 0)
		printf("10元 : %d张\n",a10);
	if (a5 != 0)
		printf("5元  : %d张\n",a5);
	if (a1 != 0)
		printf("1元  : %d张\n",a1);
	if (b5 != 0)
		printf("5角  : %d张\n",b5);
	if (b1 != 0)
		printf("1角  : %d张\n",b1);
	if (c5 != 0)
		printf("5分  : %d张\n",c5);
	if (c2 != 0)
		printf("2分  : %d张\n",c2);
	if (c1 != 0)
		printf("1分  : %d张\n",c1);

	return 0;
}