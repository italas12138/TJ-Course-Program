/* 2152118 计科 史君宝 */

#include <iostream>
using namespace std;

int main()
{
	cout << "请输入年，月，日" << endl;
	int year, month, day;
	bool leap;
	cin >> year >> month >> day;
	if (year % 4 == 0)
		if (year % 100 == 0)
			if (year % 400 == 0)
				leap = true;
			else
				leap = false;
		else
			leap = true;
	else
		leap = false;
	if (month < 1 || month > 12)
		cout << "输入错误-月份不正确" << endl;
	else
		switch (month) 
		{
		    case 1:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else 
			 		cout << year << "-" << month << "-" << day << "是"
						<< year << "年的第" << day << "天" << endl;
				break;
		    case 3:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else 
					cout << year << "-" << month << "-" << day << "是"
						<< year << "年的第" << day+59+leap << "天" << endl;
				break;
		    case 5:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 120 + leap << "天" << endl;
				break;
		    case 7:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 181 + leap << "天" << endl;
				break;
		    case 8:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 212 + leap << "天" << endl;
				break;
		    case 10:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 273 + leap << "天" << endl;
				break;
		    case 12:
				if (day < 1 || day>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 334+ leap << "天" << endl;
				break;
			case 4:
				if (day < 1 || day>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 90 + leap << "天" << endl;
				break;
			case 6:
				if (day < 1 || day>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 151 + leap << "天" << endl;
				break;
			case 9:
				if (day < 1 || day>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 243 + leap << "天" << endl;
				break;
			case 11:
				if (day < 1 || day>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << year << "-" << month << "-" << day << "是"
					<< year << "年的第" << day + 304 + leap << "天" << endl;
				break;
			case 2:
				if (leap) 
				{
					if (day < 1 || day>29)
						cout << "输入错误-日与月的关系非法" << endl;
					else
						cout << year << "-" << month << "-" << day << "是"
						<< year << "年的第" << day + 31 << "天" << endl;
				}
				else 
				{
					if (day < 1 || day>28)
						cout << "输入错误-日与月的关系非法" << endl;
					else
						cout << year << "-" << month << "-" << day << "是"
						<< year << "年的第" << day + 31 << "天" << endl;
				}			
				break;
		}

	return 0;
}