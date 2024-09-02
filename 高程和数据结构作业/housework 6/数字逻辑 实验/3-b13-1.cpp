/* 2152118 史君宝 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int year, month, xingqi, day = 0;
	bool run = 0, guo = 1,xingqiguo=1;
	while (guo)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) :";
		cin >> year >> month;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (!(year >= 2000 && year <= 2030))
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (!(month >= 1 && month <= 12))
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		while (xingqiguo)
		{
			cout << "请输入" << year << "年" << month << "月1日的星期(0 - 6表示星期日 - 星期六) :";
			cin >> xingqi;
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(65535, '\n');
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
			if (!(xingqi >= 0 && xingqi <= 6))
			{
				cout << "输入非法，请重新输入" << endl;
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
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  " << "星期一  " << "星期二  " << "星期三  " << "星期四  "
		<< "星期五  " << "星期六  " << endl;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
		month == 10 || month == 12)
		day = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11 )
		day = 30;
	if (month == 2)
		day = 28 + run;
	int i = 1;
	for (int j = 0; j <=4 * xingqi; ++j)
		cout << "  ";
	cout <<setw(2)<<setiosflags(ios::right) << i << "    ";
	if (xingqi == 6)
		cout << endl;
	for (i = 2; i <= day; ++i)
	{
		cout  <<"  " << setw(2) << setiosflags(ios::right) << i << "    ";
		if ((i + xingqi) % 7 == 0)
			cout << endl;
	}

	return 0;		
}