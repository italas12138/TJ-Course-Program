/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	int w = 0,c;
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

int main()
{
	int year, month, day,yuetian,xingqi;
	bool guo = 1,run=0;
	while (guo)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		if (year < 1900 || year>2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (month < 1 || month>12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
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
		if(day<1||day>yuetian)
		{
			cout << "�ղ���ȷ������������" << endl;
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
		cout << "������" << endl;
	if (xingqi == 1)
		cout << "����һ" << endl;
	if (xingqi == 2)
		cout << "���ڶ�" << endl;
	if (xingqi == 3)
		cout << "������" << endl;
	if (xingqi == 4)
		cout << "������" << endl;
	if (xingqi == 5)
		cout << "������" << endl;
	if (xingqi == 6)
		cout << "������" << endl;

	return 0;
}