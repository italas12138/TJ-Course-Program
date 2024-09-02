/* 2152118 ʷ���� �ƿ� */

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

#define max_num 9

//���������ʽ�µģ��ƶ�ǰλ�ú���   eg D4 d4 ��Ϊball[3][3]
void init_ball_num(int one, int two, int ball[max_num][max_num], char ball_num[max_num])
{
	int x, y;
	while (1)
	{
		cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
		cct_getxy(x, y);

		cin >> ball_num;
		if (ball_num[0] <= 'z' && ball_num[0] >= 'a')
			ball_num -= 32;
		while (!(ball_num[0] >= 'A' && ball_num[0] <= 'A' + one - 1 && ball_num[1] >= '1' && ball_num[1] <= '0' + two))
		{
			cout << "�����������������." << endl;
			cct_gotoxy(x, y);
			cout << "                                    ";
			cct_gotoxy(x, y);
			cin >> ball_num;
			if (ball_num[0] <= 'z' && ball_num[0] >= 'a')
				ball_num -= 32;
		}
		if (ball[ball_num[0]-'A'][ball_num[1] - '1'] == 0)
			cout << "��ʼλ��Ϊ�գ�����������." << endl;
		else
			break;
	}
	cct_getxy(x, y);
	cout << "                                  ";
	cct_gotoxy(x, y);
	cout << "����Ϊ" << ball_num[0] << "��" << ball_num[1] << "��" << endl;
}

//���������ʽ�µģ��ƶ���λ�ú���   eg D4 d4 ��Ϊball[3][3]
void init_ball_ber(int one, int two, int ball[max_num][max_num], char ball_ber[max_num])
{
	int x, y;
	while (1)
	{
		cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
		cct_getxy(x, y);

		cin >> ball_ber;
		if (ball_ber[0] <= 'z' && ball_ber[0] >= 'a')
			ball_ber -= 32;
		while (!(ball_ber[0] >= 'A' && ball_ber[0] <= 'A' + one - 1 && ball_ber[1] >= '1' && ball_ber[1] <= '0' + two))
		{
			cout << "�����������������." << endl;
			cct_gotoxy(x, y);
			cout << "                                   ";
			cct_gotoxy(x, y);
			cin >> ball_ber;
			if (ball_ber[0] <= 'z' && ball_ber[0] >= 'a')
				ball_ber -= 32;
		}
		if (ball[ball_ber[0] - 'A'][ball_ber[1] - '1'] != 0)
			cout << "Ŀ��λ�÷ǿգ�����������." << endl;
		else
			break;
	}
	cct_getxy(x, y);
	cout << "                                      ";
	cct_gotoxy(x, y);
	cout << "����Ϊ" << ball_ber[0] << "��" << ball_ber[1] << "��" << endl;
}

//�˵� ѡ��һ����
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

//�˵� ѡ�������
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
	cout << "\n��3���������ɫ�ֱ��ǣ�" << next[0] << " " << next[1] << " " << next[2] << endl;

	init_ball_num(one, two, ball, ball_num);
	init_ball_ber(one, two, ball, ball_ber);

	back = DFS(ball_num[0] - 'A', ball_num[1] - '1', label, ball, one, two, ball_num, ball_ber);

	if (!back)
		cout << "�޷��ҵ��ƶ�·��" << endl;
	else
	{
		cout << "\n���ҽ�����飺" << endl;

		print_int(one, two, ball, label, 2);

		cout << "\n�ƶ�·��(��ͬɫ��ʶ)��" << endl;


		print_int(one, two, ball, label, 3);
	}

	end();

	cct_cls();
	menu();
	return;
}

//�˵� ѡ��������
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
		cout << "\n��3���������ɫ�ֱ��ǣ�" << next[0] << " " << next[1] << " " << next[2] << endl;

		init_ball_num(one, two, ball, ball_num);
		init_ball_ber(one, two, ball, ball_ber);

		back = DFS(ball_num[0] - 'A', ball_num[1] - '1', label, ball, one, two, ball_num, ball_ber);

		if (!back)
		{
			cout << "�޷��ҵ��ƶ�·��" << endl;

			cout << "\n��ǰ���飺" << endl;

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

			cout << "\n�ƶ��������(��ͬɫ��ʶ)��" << endl;

			print_int(one, two, ball, label, 1);

			cout << "���ε÷֣�" << score_get << " �ܵ÷֣�" << score_num << endl;

			cout << "\n��ǰ���飺" << endl;
			print_int(one, two, ball, label, 1);
		}
	}
	cout << "�޿�λ���ƶ�����Ϸ����!" << endl;

	end();

	cct_cls();
	menu();
	return;
}



