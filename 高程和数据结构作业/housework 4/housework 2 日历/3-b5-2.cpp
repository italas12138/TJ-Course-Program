/* 2152118 �ƿ� ʷ���� */

#include <iostream>
using namespace std;

int main()
{
	cout << "�������꣬�£���" << endl;
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
		cout << "�������-�·ݲ���ȷ" << endl;
	else
		switch (month) 
		{
		    case 1:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else 
			 		cout << year << "-" << month << "-" << day << "��"
						<< year << "��ĵ�" << day << "��" << endl;
				break;
		    case 3:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else 
					cout << year << "-" << month << "-" << day << "��"
						<< year << "��ĵ�" << day+59+leap << "��" << endl;
				break;
		    case 5:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 120 + leap << "��" << endl;
				break;
		    case 7:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 181 + leap << "��" << endl;
				break;
		    case 8:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 212 + leap << "��" << endl;
				break;
		    case 10:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 273 + leap << "��" << endl;
				break;
		    case 12:
				if (day < 1 || day>31)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 334+ leap << "��" << endl;
				break;
			case 4:
				if (day < 1 || day>30)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 90 + leap << "��" << endl;
				break;
			case 6:
				if (day < 1 || day>30)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 151 + leap << "��" << endl;
				break;
			case 9:
				if (day < 1 || day>30)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 243 + leap << "��" << endl;
				break;
			case 11:
				if (day < 1 || day>30)
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				else
					cout << year << "-" << month << "-" << day << "��"
					<< year << "��ĵ�" << day + 304 + leap << "��" << endl;
				break;
			case 2:
				if (leap) 
				{
					if (day < 1 || day>29)
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					else
						cout << year << "-" << month << "-" << day << "��"
						<< year << "��ĵ�" << day + 31 << "��" << endl;
				}
				else 
				{
					if (day < 1 || day>28)
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					else
						cout << year << "-" << month << "-" << day << "��"
						<< year << "��ĵ�" << day + 31 << "��" << endl;
				}			
				break;
		}

	return 0;
}