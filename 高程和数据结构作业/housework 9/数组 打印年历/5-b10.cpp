/* 2152118 史君宝 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)         //利用蔡勒公式求出每个月的第一天是周几
{
	int w = 0, c;
	if (m == 1 || m == 2)
	{
		m = 12 + m;
		--y;
	}
	c = y / 100;
	y = y % 100;
	w = y + int(y / 4) + int(c / 4) - 2 * c + int(13 * (m + 1) / 5) + d - 1;
	if (w >= 0)
		w %= 7;
	else
	{
		while (w < 0)
			w += 7;
		w %= 7;
	}
	return w;
}

int main()
{
	system("mode con cols=120 lines=45");

	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };       //月份天数表
	int year;                                                     
	bool run = 0;            //判断是否是闰年

	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;

	//判断是否是闰年
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
	
	if(run==1)                    //闰年二月份加1
		++month[1];

	cout << year << "年的日历:" << endl;
	cout << endl;

	int a, b, c, aday, bday, cday;

	for (int i = 0; i < 4; ++i)               //将一年分为4部分，每次打印同行的三个月
	{
		//打印表头 月份
		cout << setw(13) << i * 3 + 1 << "月" << setw(30) << i * 3 + 2 << "月"    
			<< setw(30) << i * 3 + 3 << "月" << endl;

		//打印星期表头
		for (int w = 0; w < 3; ++w)
			cout << "Sun Mon Tue Wed Thu Fri Sat     ";
		cout << endl;

		//利用蔡勒公式求每月第一天星期几
		if(i * 3 + 1<3)
			a= zeller(year-1, i * 3 + 13, 1);
		else
			a = zeller(year, i * 3 + 1, 1);
		if (i * 3 + 2 < 3)
			b = zeller(year - 1, i * 3 + 14, 1);
		else
			b = zeller(year, i * 3 + 2, 1);
		c = zeller(year, i * 3 + 3, 1);

		//打印开始开始的第一个是第几天。把它赋值给天数计数器。
		//比如如果1号是周三，那么开始打印的天数计数器是-2号（为了打印方便）
		aday = 1 - a;
		bday = 1 - b;
		cday = 1 - c;

		//当你的三个天数计数器均超过当月的天数才停止打印
		while (aday <= month[i * 3] || bday <= month[i * 3 + 1] || cday <= month[i * 3 + 2])
		{
			for (int m = 0; m < 7; ++m)         //打印同排第一个月的七天
			{
				//如果天数计数器指向1号以下，或者多于当月天数，换成打印空格
				if (aday<1 || aday>month[i * 3]) 
				{
					++aday;
					cout << "    ";
				}
				//否则打印当月。
				else
					cout << setw(4) << setiosflags(ios::left) << aday++;
			}
			cout << "    ";

			//打印同排的的第二个月的七天
			for (int m = 0; m < 7; ++m)
			{
				if (bday<1 || bday>month[i * 3 + 1])
				{
					++bday;
					cout << "    ";
				}
				else
					cout << setw(4) << setiosflags(ios::left) << bday++;
			}
			cout << "    ";

			//打印同排的的第三个月的七天
			for (int m = 0; m < 7; ++m)
			{
				if (cday<1 || cday>month[i * 3 + 2])
				{
					++cday;
					cout << "    ";
				}
				else
					cout << setw(4) << setiosflags(ios::left) << cday++;
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}