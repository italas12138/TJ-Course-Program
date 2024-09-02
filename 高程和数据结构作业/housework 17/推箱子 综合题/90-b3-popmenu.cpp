/*2152118 史君宝 计科*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <io.h>

#include "90-b3.h"
#include "cmd_console_tools.h"

using namespace std;


//弹出式的菜单，输入0-1进行选择
void menu()
{
	cct_cls();
	cout << "---------------------------" << endl;
	cout << "1.显示关卡" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------" << endl;
	cout << "[请选择0-1]";

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