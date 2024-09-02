/* 2152118 史君宝 计科 */

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

#define max_num 9

//获得数组形式下的，移动前位置函数   eg D4 d4 变为ball[3][3]
void init_ball_num(int one, int two, int ball[max_num][max_num], char ball_num[max_num])
{
	int x, y;
	while (1)
	{
		cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
		cct_getxy(x, y);

		cin >> ball_num;
		if (ball_num[0] <= 'z' && ball_num[0] >= 'a')
			ball_num -= 32;
		while (!(ball_num[0] >= 'A' && ball_num[0] <= 'A' + one - 1 && ball_num[1] >= '1' && ball_num[1] <= '0' + two))
		{
			cout << "输入错误，请重新输入." << endl;
			cct_gotoxy(x, y);
			cout << "                                    ";
			cct_gotoxy(x, y);
			cin >> ball_num;
			if (ball_num[0] <= 'z' && ball_num[0] >= 'a')
				ball_num -= 32;
		}
		if (ball[ball_num[0]-'A'][ball_num[1] - '1'] == 0)
			cout << "起始位置为空，请重新输入." << endl;
		else
			break;
	}
	cct_getxy(x, y);
	cout << "                                  ";
	cct_gotoxy(x, y);
	cout << "输入为" << ball_num[0] << "行" << ball_num[1] << "列" << endl;
}

//获得数组形式下的，移动后位置函数   eg D4 d4 变为ball[3][3]
void init_ball_ber(int one, int two, int ball[max_num][max_num], char ball_ber[max_num])
{
	int x, y;
	while (1)
	{
		cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
		cct_getxy(x, y);

		cin >> ball_ber;
		if (ball_ber[0] <= 'z' && ball_ber[0] >= 'a')
			ball_ber -= 32;
		while (!(ball_ber[0] >= 'A' && ball_ber[0] <= 'A' + one - 1 && ball_ber[1] >= '1' && ball_ber[1] <= '0' + two))
		{
			cout << "输入错误，请重新输入." << endl;
			cct_gotoxy(x, y);
			cout << "                                   ";
			cct_gotoxy(x, y);
			cin >> ball_ber;
			if (ball_ber[0] <= 'z' && ball_ber[0] >= 'a')
				ball_ber -= 32;
		}
		if (ball[ball_ber[0] - 'A'][ball_ber[1] - '1'] != 0)
			cout << "目标位置非空，请重新输入." << endl;
		else
			break;
	}
	cct_getxy(x, y);
	cout << "                                      ";
	cct_gotoxy(x, y);
	cout << "输入为" << ball_ber[0] << "行" << ball_ber[1] << "列" << endl;
}

//菜单 选择一函数
void choice_one()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };
	int label[max_num][max_num] = { 0 };

	input_menu(one, two);

	get_int(one, two, ball, 1);

	print_int(one, two, ball, label, 1);

	end();

	cct_cls();
	menu();
	return;
}

//菜单 选择二函数
void choice_two()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };
	char ball_num[max_num];
	char ball_ber[max_num];
	int label[max_num][max_num] = { 0 };
	int back;
	int next[3];

	input_menu(one, two);

	get_int(one, two, ball, 2);

	print_int(one, two, ball, label, 1);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		next[0] = rand() % 7 + 1;
		next[1] = rand() % 7 + 1;
		next[2] = rand() % 7 + 1;
	}
	cout << "\n下3个彩球的颜色分别是：" << next[0] << " " << next[1] << " " << next[2] << endl;

	init_ball_num(one, two, ball, ball_num);
	init_ball_ber(one, two, ball, ball_ber);

	back = DFS(ball_num[0] - 'A', ball_num[1] - '1', label, ball, one, two, ball_num, ball_ber);

	if (!back)
		cout << "无法找到移动路径" << endl;
	else
	{
		cout << "\n查找结果数组：" << endl;

		print_int(one, two, ball, label, 2);

		cout << "\n移动路径(不同色标识)：" << endl;


		print_int(one, two, ball, label, 3);
	}

	end();

	cct_cls();
	menu();
	return;
}

//菜单 选择三函数
void choice_three()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };
	int a, b;
	int next[3];
	int score_num = 0, score_get = 0;
	int n = 5, size = 1;

	input_menu(one, two);

	get_int(one, two, ball, 1);

	print_int(one, two, ball, ball, 1);

	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		next[0] = rand() % 7 + 1;
		next[1] = rand() % 7 + 1;
		next[2] = rand() % 7 + 1;
	}
	while (n < one * two)
	{
		char ball_num[max_num];
		char ball_ber[max_num];
		int label[max_num][max_num] = { 0 };
		int back;
		if (!size)
		{

			srand((unsigned)time(NULL));
			for (int i = 0; i < 3; ++i)
				next[i] = rand() % 7 + 1;
				
		}
		cout << "\n下3个彩球的颜色分别是：" << next[0] << " " << next[1] << " " << next[2] << endl;

		init_ball_num(one, two, ball, ball_num);
		init_ball_ber(one, two, ball, ball_ber);

		back = DFS(ball_num[0] - 'A', ball_num[1] - '1', label, ball, one, two, ball_num, ball_ber);

		if (!back)
		{
			cout << "无法找到移动路径" << endl;

			cout << "\n当前数组：" << endl;

			print_int(one, two, ball, label, 1);
			size = 1;
		}
		else
		{
			ball[ball_ber[0] - 'A'][ball_ber[1] - '1'] = ball[ball_num[0] - 'A'][ball_num[1] - '1'];
			ball[ball_num[0] - 'A'][ball_num[1] - '1'] = 0;
			size = score(ball_ber[0] - 'A', ball_ber[1] - '1', one, two, ball, score_get, score_num);
			if (size)
				n -= size;
			else
				n += 3;

			srand((unsigned)time(NULL));
			if (n < one * two)
				for (int i = 0; i < 3; ++i)
				{
					a = rand() % one;
					b = rand() % two;

					if (ball[a][b])
						--i;
					else
						ball[a][b] = next[i];
				}
			else
			{
				for (int i = 0; i < 3 - (n - one * two); ++i)
				{
					a = rand() % one;
					b = rand() % two;

					if (ball[a][b])
						--i;
					else
						ball[a][b] = next[i];
				}
				break;
			}

			cout << "\n移动后的数组(不同色标识)：" << endl;

			print_int(one, two, ball, label, 1);

			cout << "本次得分：" << score_get << " 总得分：" << score_num << endl;

			cout << "\n当前数组：" << endl;
			print_int(one, two, ball, label, 1);
		}
	}
	cout << "无空位可移动，游戏结束!" << endl;

	end();

	cct_cls();
	menu();
	return;
}



