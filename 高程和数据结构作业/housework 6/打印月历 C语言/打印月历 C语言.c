/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, xingqi=0, day = 0;
	int run = 0, guo = 1, xingqiguo = 1,yearret,monthret,xingqiret;
	while (guo)
	{
		printf("请输入年份(2000-2030)和月份(1-12) :");
		yearret = scanf("%d", &year);
		monthret = scanf("%d", &month);
		char a;
		if ((yearret && monthret) == 0)
		{
			while ((a = getchar()) != '\n');
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (!(year >= 2000 && year <= 2030))
		{
			printf( "输入非法，请重新输入\n");
			continue;
		}
		if (!(month >= 1 && month <= 12))
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		while (xingqiguo)
		{
			printf("请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) :",year,month);
			xingqiret = scanf("%d", &xingqi);
			char ch;
			if (xingqiret == 0)
			{
				while ((ch = getchar()) != '\n');
				printf("输入非法，请重新输入\n");
				continue;
			}
			if (!(xingqi >= 0 && xingqi <= 6))
			{
				printf("输入非法，请重新输入\n");
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
	printf("%d年%d月的月历为:\n", year, month); 
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六  \n");
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
