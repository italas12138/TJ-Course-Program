/*2152118 ʷ���� �ƿ�*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <io.h>

#include "90-b3.h"
#include "cmd_console_tools.h"

using namespace std;


//����ʽ�Ĳ˵�������0-1����ѡ��
void menu()
{
	cct_cls();
	cout << "---------------------------" << endl;
	cout << "1.��ʾ�ؿ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------" << endl;
	cout << "[��ѡ��0-1]";

	int number = 0;
	char ch = ' ', problem_number[100][5];

	while (!(ch == '0' || ch == '1'))
		ch = _getch();

	if (ch == '1')
	{
		if (!read_file(number, problem_number))
		{
			cct_cls();
			problem_menu(number, problem_number);
			move_menu(number, problem_number);
		}
	}

	return;

}