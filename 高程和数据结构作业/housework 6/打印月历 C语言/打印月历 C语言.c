/* 2152118 ʷ���� �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, xingqi=0, day = 0;
	int run = 0, guo = 1, xingqiguo = 1,yearret,monthret,xingqiret;
	while (guo)
	{
		printf("���������(2000-2030)���·�(1-12) :");
		yearret = scanf("%d", &year);
		monthret = scanf("%d", &month);
		char a;
		if ((yearret && monthret) == 0)
		{
			while ((a = getchar()) != '\n');
			printf("����Ƿ�������������\n");
			continue;
		}
		if (!(year >= 2000 && year <= 2030))
		{
			printf( "����Ƿ�������������\n");
			continue;
		}
		if (!(month >= 1 && month <= 12))
		{
			printf("����Ƿ�������������\n");
			continue;
		}
		while (xingqiguo)
		{
			printf("������%d��%d��1�յ�����(0 - 6��ʾ������ - ������) :",year,month);
			xingqiret = scanf("%d", &xingqi);
			char ch;
			if (xingqiret == 0)
			{
				while ((ch = getchar()) != '\n');
				printf("����Ƿ�������������\n");
				continue;
			}
			if (!(xingqi >= 0 && xingqi <= 6))
			{
				printf("����Ƿ�������������\n");
				continue;
			}
			xingqiguo = 0;
		}
		guo = 0;
	}
	if (year % 4 == 0)
	{
		run = 1;
		if (year % 100 == 0)
		{
			run = 0;
			if (year % 400 == 0)
				run = 1;
		}
	}
	printf("%d��%d�µ�����Ϊ:\n", year, month); 
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������  \n");
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
		month == 10 || month == 12)
		day = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		day = 30;
	if (month == 2)
		day = 28 + run;
	int i = 1;
	for (int j = 0; j <= 4 * xingqi; ++j)
		printf("  ");
	printf("%2d    ", i);
	if (xingqi == 6)
		printf("\n");
	for (i = 2; i <= day; ++i)
	{
		printf("  %2d    ",i);
		if ((i + xingqi) % 7 == 0)
			printf("\n");
	}

	return 0;
}
