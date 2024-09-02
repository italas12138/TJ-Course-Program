/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int zeller(int y, int m, int d)
{
	int w = 0, c;
	if (m == 1 || m == 2)
	{
		m = 12 + m;
		--y;
	}
	c = y / 100;
	y = y % 100;
	w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
	return w;
}

int main()
{
	int year, month, day, yuetian, xingqi,yearret,monthret,dayret;
	int guo = 1, run = 0;
	while (guo)
	{
		printf("请输入年[1900-2100]、月、日：\n");
		char ch;
		yearret = scanf("%d", &year);
		monthret = scanf("%d", &month);
		dayret = scanf("%d", &day);
		if ((yearret && monthret&&dayret) == 0)
		{
			while ((ch = getchar()) != '\n');
			printf("输入错误，请重新输入\n");
			continue;
		}
		if (year < 1900 || year>2100)
		{
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (month < 1 || month>12)
		{
			printf("月份不正确，请重新输入\n");
			continue;
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
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
			month == 10 || month == 12)
			yuetian = 31;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			yuetian = 30;
		else
			yuetian = 28 + run;
		if (day<1 || day>yuetian)
		{
			printf("日不正确，请重新输入\n");
			continue;
		}
		guo = 0;
	}
	xingqi = zeller(year, month, day);
	if (xingqi >= 0)
		xingqi %= 7;
	else
	{
		while (xingqi < 0)
			xingqi += 7;
		xingqi %= 7;
	}
	if (xingqi == 0)
		printf("星期日\n");
	if (xingqi == 1)
		printf("星期一\n");
	if (xingqi == 2)
		printf("星期二\n");
	if (xingqi == 3)
		printf("星期三\n");
	if (xingqi == 4)
		printf("星期四\n");
	if (xingqi == 5)
		printf("星期五\n");
	if (xingqi == 6)
		printf("星期六\n");

	return 0;
}