/* 2152118 史君宝 计科 */
#include <iostream>
#include <conio.h>
using namespace std;

/* --- 如果有需要的宏定义、只读全局变量等，写于此处 --- */
int monthday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

/* --- 如果有其它全局函数需要声明，写于此处 --- */

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */

public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
	//判断是否是闰年
	int run_year();

	//Date 无参数
	Date();

	//Date 三参数
	Date(int x, int y, int z);

	//Date 一参数
	Date(int x);

	void set(int x, int y , int z );

	void get(int& x, int& y, int& z);

	void show();
};

/* --- 给出 Date 类的所有成员函数的体外实现 --- */

int Date::run_year()
{
		if (year % 400 == 0)
			return 1;
		else if (year % 100 == 0)
			return 0;
		else if (year % 4 == 0)
			return 1;
		else
			return 0;
}

Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
	return;
}

//Date 三参数
Date::Date(int x, int y, int z)
{
	int run = 0;
	if (x <= 2099 && x >= 1900)
		year = x;
	else
		year = 2000;
	if (y <= 12 && y >= 1)
		month = y;
	else
		month = 1;
	if (month == 2)
		run = run_year();
	if (z <= (monthday[month - 1] + run) && z >= 1)
		day = z;
	else
		day = 1;
	return;
}

//Date 一参数
Date::Date(int x)
{
	year = 1900;
	month = 1;
	day = 1;

	int run = 0;
	x -= 1;

	while (x > 0)
	{
		run = run_year();

		if (x - 365 - run >= 0)
		{
			x = x - 365 - run;
			++year;
			if (year == 2100)
			{
				year = 2099;
				month = 12;
				day = 31;
				break;
			}
		}
		else
		{
			while (x)
			{
				if (month != 2)
					if (x - monthday[month - 1] >= 0)
					{
						x = x - monthday[month - 1];
						++month;
					}
					else
					{
						day += x;
						x = 0;
					}
				else
				{
					if (x - monthday[month - 1] - run >= 0)
					{
						x = x - monthday[month - 1] - run;
						++month;
					}
					else
					{
						day += x;
						x = 0;
					}
				}

			}
		}
	}

	return;
}

void Date::set(int x = 2000, int y = 1, int z = 1)
{
	int run = 0;
	if (x <= 2099 && x >= 1900)
		year = x;
	else
		year = 2000;
	if (y <= 12 && y >= 1)
		month = y;
	else
		month = 1;
	if (month == 2)
		run = run_year();
	if (z <= (monthday[month - 1] + run) && z >= 1)
		day = z;
	else
		day = 1;
	return;
}

void Date::get(int& x, int& y, int& z)
{
	x = year;
	y = month;
	z = day;
	return;
}

void Date::show()
{
	cout << year << "." << month << "." << day << endl;
	return;
}

/* --- 如果有需要的其它全局函数的实现，可以写于此处 --- */

/* -- 替换标记行 -- 本行不要做任何改动 -- 本行不要删除 -- 在本行的下面不要加入任何自己的语句，作业提交后从本行开始会被替换 -- 替换标记行 -- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动，测试时会替换
***************************************************************************/
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2022, 12, 9);	//2022.12.9

		cout << "无参及三参构造函数测试（完全正确）" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是2000.1.1， 实际为：";
		d1.show();
		cout << "d2应该是2022.12.9，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2022, 6, 32);  //2022.6.1

		cout << "三参构造函数测试（年、月、日非法）" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2022.6.1， 实际为：";
		d4.show();

		/* 多个错，按年月日顺序处理 */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5应该是2000.2.29，实际为：";
		d5.show();
		cout << "d6应该是2000.2.1， 实际为：";
		d6.show();
		cout << "d7应该是2000.1.31，实际为：";
		d7.show();
		cout << "d8应该是2000.1.1， 实际为：";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "三参构造函数测试（闰年）" << endl;
		cout << "========================" << endl;

		cout << "d1应该是2022.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2020.2.29，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		Date d5(30000);      //1982.2.19
		Date d6(44903);      //2022.12.9

		cout << "一参构造函数测试，包括合法及非法值" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();
		cout << "d5应该是1982.2.19， 实际为：";
		d5.show();
		cout << "d6应该是2022.12.9， 实际为：";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		cout << "=================" << endl;

		d1.set(2022, 6, 10);	//2022.6.10
		d2.set(2022, 6);		//2022.6.1
		d3.set(2022);		//2022.1.1

		cout << "d1应该是2022.6.10，实际为：";
		d1.show();
		cout << "d2应该是2022.6.1， 实际为：";
		d2.show();
		cout << "d3应该是2022.1.1， 实际为：";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "测试set，年、月、日非法" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2022, 5, 32);  //2022.5.1
		d4.set(2022, 13, 12); //2022.1.12

		cout << "d1应该是2000.2.29， 实际为：";
		d1.show();
		cout << "d2应该是2019.2.1，  实际为：";
		d2.show();
		cout << "d3应该是2022.5.1，  实际为：";
		d3.show();
		cout << "d4应该是2022.1.12， 实际为：";
		d4.show();

		/* 多个错+带缺省值，按年月日顺序处理 */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5应该是2000.2.29， 实际为：";
		d5.show();
		cout << "d6应该是2000.2.1，  实际为：";
		d6.show();
		cout << "d7应该是2000.2.1，  实际为：";
		d7.show();
		cout << "d8应该是2020.2.1，  实际为：";
		d8.show();
		cout << "d9应该是2020.1.1，  实际为：";
		d9.show();
		cout << "d10应该是2000.1.31，实际为：";
		d10.show();
		cout << "d11应该是2000.1.1， 实际为：";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 12, 9);
		int y, m, d;

		cout << "测试get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "应该y=2022,m=12,d=9，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}
