/*2152118 ʷ���� �ƿ�*/

#include <iostream>
#include <fstream>
#include <conio.h>

#include "90-b3.h"
#include "cmd_console_tools.h"

using namespace std;

//��ӡǽ�⡪��9
void print_nine()
{
	int x, y;
	cct_getxy(x,y);

	for (int i = 0; i < 3; ++i)
	{
		cct_gotoxy(x, y + i);
		cout << "      ";
	}
	
	return;
}

//��ӡǽ����W
void print_W()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(4, 0);
	cout << "�X�T�[";

	cct_gotoxy(x, y + 1);
	cout << "�UXX�U";

	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";

	cct_setcolor(0, 7);

	return;
}

//��ӡ���ƶ�λ�á���0
void print_zero()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(7,0);

	for (int i = 0; i < 3; ++i)
	{
		cct_gotoxy(x, y + i);
		cout << "      ";
	}

	cct_setcolor(0, 7);

	return;
}

//��ӡ���ӵ���ʼλ�á���B
void print_B()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(2, 14);
	cout << "�X�T�[";

	cct_gotoxy(x, y + 1);
	cout << "�U��U";

	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";

	cct_setcolor(0, 7);

	return;
}

//��ӡ���ӵ�����λ�á���F
void print_F()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(3, 10);
	cout << "�X�T�[";

	cct_gotoxy(x, y + 1);
	cout << "�U��U";

	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";

	cct_setcolor(0, 7);

	return;
}

//��ӡ��ʼ����λ�á���S
void print_S()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(1, 14);
	cout << "�X�T�[";

	cct_gotoxy(x, y + 1);
	cout << "�U��U";

	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";

	cct_setcolor(0, 7);

	return;
}

//��ӡ���ӵĳ�ʼ/����λ���ص�����R
void print_R()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(6, 12);
	cout << "�X�T�[";

	cct_gotoxy(x, y + 1);
	cout << "�U��U";

	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";

	cct_setcolor(0, 7);

	return;
}
