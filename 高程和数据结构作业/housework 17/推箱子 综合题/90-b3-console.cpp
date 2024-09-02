/*2152118 史君宝 计科*/

#include <iostream>
#include <fstream>
#include <conio.h>

#include "90-b3.h"
#include "cmd_console_tools.h"

using namespace std;

//打印墙外——9
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

//打印墙——W
void print_W()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(4, 0);
	cout << "╔═╗";

	cct_gotoxy(x, y + 1);
	cout << "║XX║";

	cct_gotoxy(x, y + 2);
	cout << "╚═╝";

	cct_setcolor(0, 7);

	return;
}

//打印可移动位置——0
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

//打印箱子的起始位置——B
void print_B()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(2, 14);
	cout << "╔═╗";

	cct_gotoxy(x, y + 1);
	cout << "║★║";

	cct_gotoxy(x, y + 2);
	cout << "╚═╝";

	cct_setcolor(0, 7);

	return;
}

//打印箱子的最终位置——F
void print_F()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(3, 10);
	cout << "╔═╗";

	cct_gotoxy(x, y + 1);
	cout << "║●║";

	cct_gotoxy(x, y + 2);
	cout << "╚═╝";

	cct_setcolor(0, 7);

	return;
}

//打印初始启动位置——S
void print_S()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(1, 14);
	cout << "╔═╗";

	cct_gotoxy(x, y + 1);
	cout << "║♀║";

	cct_gotoxy(x, y + 2);
	cout << "╚═╝";

	cct_setcolor(0, 7);

	return;
}

//打印箱子的初始/最终位置重叠——R
void print_R()
{
	int x, y;
	cct_getxy(x, y);

	cct_setcolor(6, 12);
	cout << "╔═╗";

	cct_gotoxy(x, y + 1);
	cout << "║★║";

	cct_gotoxy(x, y + 2);
	cout << "╚═╝";

	cct_setcolor(0, 7);

	return;
}
