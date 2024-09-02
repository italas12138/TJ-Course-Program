/* 2152118 ʷ���� �ƿ� */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

#define max_num 9

//����˵������ÿ���ӳ������е�����
void input_menu(int& one, int& two)
{
	cct_cls();
	cout << "����������(7-9)��" << endl;
	cin >> one;
	while (!(one >= 7 && one <= 9))
	{
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> one;
	}
	cout << "����������(7-9)��" << endl;
	cin >> two;
	while (!(two >= 7 && two <= 9))
	{
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> two;
	}
	cout << endl;

}

//Ϊ����Ķ�ά����ball[][]������ֵ������level,ȷ����5������60%��
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

//��ӡ����Ķ�ά������ʽ
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

//��������������end���ص����˵���
void end()
{
	int x, y;
	cout << "��С�������������End����...";
	cct_getxy(x, y);
	char end[max_num];
	cin >> end;
	while (!((end[0] == 'e' || end[0] == 'E') && (end[1] == 'n' || end[1] == 'N') && (end[2] == 'd' || end[2] == 'D')))
	{
		cout << "�����������������" << endl;
		cct_gotoxy(x, y);
		cout << "                 ";
		cct_gotoxy(x, y);
		cin >> end;
	}
}

//������������������ҵ��ƶ�·��
//x,yΪ������λ�ã���ǩ����label,��������ball,one��two��������Ϣ��ball_num��ball_ber�����ƶ�ǰ��λ��
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

//�����ƶ���Ĳ����������ң����ܹ��������������������������Ĳ�����
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