/* 2152118 史君宝 计科 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

#define max_num 9

//输入菜单，完成每个子程序，行列的输入
void input_menu(int& one, int& two)
{
	cct_cls();
	cout << "请输入行数(7-9)：" << endl;
	cin >> one;
	while (!(one >= 7 && one <= 9))
	{
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> one;
	}
	cout << "请输入列数(7-9)：" << endl;
	cin >> two;
	while (!(two >= 7 && two <= 9))
	{
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> two;
	}
	cout << endl;

}

//为彩球的二维数组ball[][]，赋初值，根据level,确定是5个还是60%。
void get_int(int one, int two, int ball[max_num][max_num], int level)
{
	srand((unsigned)time(NULL));
	int a, b, c;
	if (level == 1)
	{
		for (int i = 0; i < 5; ++i)
		{
			a = rand() % one;
			b = rand() % two;
			c = rand() % 7 + 1;

			if (ball[a][b])
				--i;
			else
				ball[a][b] = c;
		}
	}
	else if (level == 2)
	{
		for (int i = 0; i <= 0.6 * one * two; ++i)
		{
			a = rand() % one;
			b = rand() % two;
			c = rand() % 7 + 1;

			if (ball[a][b])
				--i;
			else
				ball[a][b] = c;
		}
	}
}

//打印彩球的二维数组形式
void print_int(int one, int two, int ball[max_num][max_num], 
	int label[max_num][max_num], int level)
{
	cout << "  |";
	for (int i = 1; i <= two; ++i)
		cout << "  " << i;
	cout << endl << "--+-";
	for (int i = 1; i <= two; ++i)
		cout << "---";
	cout << endl;

	if (level == 1)
	{
		for (int i = 0; i < one; ++i)
		{
			cout << char(i + 'A') << " |";
			for (int j = 0; j < two; ++j)
			{
				cout << "  ";
				if (ball[i][j])
				{
					cct_setcolor(14, ball[i][j]);
					cout << ball[i][j];
					cct_setcolor(0, 7);
				}
				else
					cout << ball[i][j];
			}
			cout << endl;
		}
	}
	if (level == 2)
	{
		for (int i = 0; i < one; ++i)
		{
			cout << char(i + 'A') << " |";
			for (int j = 0; j < two; ++j)
			{
				cout << "  ";
				if (label[i][j] == -1)
					cout << "*";
				else
					cout << "0";
			}
			cout << endl;
		}
	}
	if (level == 3)
	{
		for (int i = 0; i < one; ++i)
		{
			cout << char(i + 'A') << " |";
			for (int j = 0; j < two; ++j)
			{
				cout << "  ";
				if (label[i][j] == -1)
				{
					cct_setcolor(14, ball[i][j]);
					cout << ball[i][j];
					cct_setcolor(0, 7);
				}
				else
					cout << ball[i][j];
			}
			cout << endl;
		}
	}


}

//结束函数，输入end，回到主菜单。
void end()
{
	int x, y;
	cout << "本小题结束，请输入End继续...";
	cct_getxy(x, y);
	char end[max_num];
	cin >> end;
	while (!((end[0] == 'e' || end[0] == 'E') && (end[1] == 'n' || end[1] == 'N') && (end[2] == 'd' || end[2] == 'D')))
	{
		cout << "输入错误，请重新输入" << endl;
		cct_gotoxy(x, y);
		cout << "                 ";
		cct_gotoxy(x, y);
		cin >> end;
	}
}

//深度优先搜索函数，找到移动路径
//x,y为搜索的位置，标签数组label,彩球数组ball,one和two是行列信息，ball_num和ball_ber储存移动前后位置
int DFS(int x, int y, int label[max_num][max_num], int ball[max_num][max_num], 
	int one, int two, char ball_num[], char ball_ber[])
{
	int i, j, a;
	for (int k = 0; k < 4; ++k)
	{
		if (k == 0)
		{
			i = x - 1;
			j = y;
		}
		if (k == 1)
		{
			i = x + 1;
			j = y;
		}
		if (k == 2)
		{
			i = x;
			j = y - 1;
		}
		if (k == 3)
		{
			i = x;
			j = y + 1;
		}
		if (i >= 0 && i <= one - 1 && j >= 0 && j <= two - 1 && label[i][j] == 0 && ball[i][j] == 0)
		{
			label[i][j] = 1;
			if (i == ball_ber[0] - 'A' && j == ball_ber[1] - '1')
			{
				label[x][y] = -1;
				label[i][j] = -1;
				return 1;
			}
			else
				a = DFS(i, j, label, ball, one, two, ball_num, ball_ber);
			if (a)
			{
				label[x][y] = -1;
				return 1;
			}
		}
	}

	return 0;
}

//搜索移动后的彩球上下左右，将能够消掉的球消掉，并返回消掉的彩球数
int score(int x, int y, int one, int two, int ball[max_num][max_num], 
	int& score_get, int& score_num)
{
	int i = 1, j = 1, n = 0;
	while (1)
	{
		if ((x - i >= 0 && x - i <= one - 1) && ball[x - i][y] == ball[x][y])
			++i;
		else
			break;
	}
	while (1)
	{
		if ((x + j >= 0 && x + j <= one - 1) && ball[x + j][y] == ball[x][y])
			++j;
		else
			break;
	}
	if (i + j - 1 >= 5)
	{
		n = i + j - 1;

		for (int k = 1; k < i; ++k)
			ball[x - k][y] = 0;
		for (int k = 1; k < j; ++k)
			ball[x + k][y] = 0;
	}

	i = j = 1;
	while (1)
	{
		if ((y - i >= 0 && y - i <= two - 1) && ball[x][y - i] == ball[x][y])
			++i;
		else
			break;
	}
	while (1)
	{
		if ((y + j >= 0 && y + j <= two - 1) && ball[x][y + j] == ball[x][y])
			++j;
		else
			break;
	}
	if (i + j - 1 >= 5)
	{
		n += i + j - 1;

		for (int k = 1; k < i; ++k)
			ball[x][y - k] = 0;
		for (int k = 1; k < j; ++k)
			ball[x][y + k] = 0;
		ball[x][y] = 0;
	}
	if (n)
	{
		score_get = (n - 1) * (n - 2);
		score_num += score_get;
	}

	return n;
}