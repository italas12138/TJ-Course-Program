#include <iostream>
#include <iomanip>
using namespace std;

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
	w = y + int(y / 4) + int(c / 4) - 2 * c + int(13 * (m + 1) / 5) + d - 1;
	return w;
}

void calendar(int year, int month, int day, int xingqi)
{
	cout << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	int i = 1;
	for (int j = 0; j <= 4 * xingqi; ++j)
		cout << "  ";
	cout << setw(2) << setiosflags(ios::right) << i << "    ";
	if (xingqi == 6)
		cout << endl;
	for (i = 2; i <= day; ++i)
	{
		cout << "  " << setw(2) << setiosflags(ios::right) << i << "    ";
		if ((i + xingqi) % 7 == 0)
			cout << endl;
	}
	cout << endl;
	return;
}

int main()
{
	int year, month, day, yuetian, xingqi,fuzhuday=1;
	bool guo = 1, run = 0;
	while (guo)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year < 1900 || year>2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month>12)
		{
			cout << "月份不正确，请重新输入" << endl;
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
			day = 31;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			day = 30;
		else
			day = 28 + run;
		guo = 0;
	}
	xingqi = zeller(year, month, fuzhuday);
	if (xingqi >= 0)
		xingqi %= 7;
	else
	{
		while (xingqi < 0)
			xingqi += 7;
		xingqi %= 7;
	}
	cout << endl;
	calendar(year, month, day, xingqi);

	return 0;
}
