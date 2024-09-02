/* 2152118 计科 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int  year, month, day;
	int leap;
	printf("请输入年，月，日\n");
	scanf("%d %d %d",&year, &month, &day);
	if (year % 4 == 0)
		if (year % 100 == 0)
			if (year % 400 == 0)
				leap = 1;
			else
				leap = 0;
		else
			leap = 1;
	else
		leap = 0;
	if (month < 1 || month > 12)
		printf("输入错误-月份不正确\n");
	else
		switch (month) 
		{
		case 1:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n",year,month,day,year,day);
			break;
		case 3:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day+59+leap);
			break;
		case 5:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day+120+leap);
			break;
		case 7:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 181 + leap);
			break;
		case 8:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day+212+leap);
			break;
		case 10:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 273 + leap);
			break;
		case 12:
			if (day < 1 || day>31)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 334 + leap);
			break;
		case 4:
			if (day < 1 || day>30)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 90 + leap);
			break;
		case 6:
			if (day < 1 || day>30)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 151+ leap);
			break;
		case 9:
			if (day < 1 || day>30)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day+243+leap);
			break;
		case 11:
			if (day < 1 || day>30)
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day+304+leap);
			break;
		case 2:
			if (leap) 
			{
				if (day < 1 || day>29)
					printf("输入错误-日与月的关系非法\n");
				else
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + leap);
			}
			else 
			{
				if (day < 1 || day>28)
					printf("输入错误-日与月的关系非法\n");
				else
					printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + leap);
			}
			break;
		}

	return 0;
}