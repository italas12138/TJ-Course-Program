/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int runnian(int year)  /*判断是否是闰年*/
{
	if (year % 400 == 0)      
		return 1;
	if (year % 100 == 0)       
		return 0;
	if (year % 4 == 0)
		return 1;
	return 0;
}

int tianshu(int s[], int month, int day)     /*求天数*/
{
	int sum = 0;
	for (int i = 0; i < month - 1; ++i)
		sum += s[i];
	sum += day;
	return sum;
}
int main()
{
	int year, month, day;
	int yuefen[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	if (!(month >= 1 && month <= 12))
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	if (runnian(year) == 1)
		yuefen[1] = 29;
	if (day > yuefen[month - 1] || day < 1)
	{
		printf("输入错误-日与月的关系非法\n");
			return 0;
	}
	printf("%d-%d-%d是%d年的第%d天\n",year,month,day,year,tianshu(yuefen, month, day));
	return 0;
}