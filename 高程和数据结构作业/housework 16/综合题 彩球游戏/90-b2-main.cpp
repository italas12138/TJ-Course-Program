/* 2152118 ʷ���� �ƿ� */

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
	cout << "1.�ڲ����飬������ɳ�ʼ5���� " << endl;
	cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "6.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
	cout << "7.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << " --------------------------------------------" << endl;

	cout << "[��ѡ��:] ";

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