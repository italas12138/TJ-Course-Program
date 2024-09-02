/* 2152118 史君宝 计科 */

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

void choice(int choose_num)
{
	switch (choose_num)
	{
		case 0:
			return;
			break;
		case 1:
			choice_one();
			break;
		case 2:
			choice_two();
			break;
		case 3:
			choice_three();
			break;
		case 4:
			choice_four();
			break;
		case 5:
			choice_five();
			break;
		case 6:
			choice_six();
			break;
		case 7:
			choice_seven();
			break;
	}
}

void menu()
{
	char ch=' ';

	cout << "--------------------------------------------" << endl;
	cout << "1.内部数组，随机生成初始5个球 " << endl;
	cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "3.内部数组，完整版" << endl;
	cout << "4.画出n*n的框架（无分隔线），随机显示5个球" << endl;
	cout << "5.画出n*n的框架（有分隔线），随机显示5个球" << endl;
	cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "7.cmd图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << " --------------------------------------------" << endl;

	cout << "[请选择:] ";

	while (!((ch =_getch())<= '7' && ch >= '0'));

	cout << ch;


	choice(ch-'0');

	return;
}


int main()
{
	menu();
	return 0;
}