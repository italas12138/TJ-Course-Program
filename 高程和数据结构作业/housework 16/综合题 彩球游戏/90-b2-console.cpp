/* 2152118 ʷ���� �ƿ� */

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

#define max_num 9

//�޸�������Կ�����ƶ�����
#define Sleeptime 100

//��ӡ�� ��Ļ��С�����������Ҽ��˳���
void print_size(int level)
{
	cct_gotoxy(0, 0);
	cout << "��Ļ��";
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
	if (level == 1)
		cout << cols << "��" << lines << "��";
	else if (level == 2)
		cout << cols << "��" << lines << "�У��Ҽ��˳���";
}

//��ӡ���ޱ߿�ģ���һ��αͼ�λ��ĺ���
void print_one(int one, int two, int ball[max_num][max_num])
{
	cout << endl;
	cct_setcolor(7, 0);
	cout << "��";
	for (int i = 0; i < two; ++i)
		cout << "��";
	cout << "��" << endl;

	for (int i = 0; i < one; ++i)
	{
		cct_setcolor(7, 0);
		cout << "��";
		for (int j = 0; j < 2 * two; ++j)
			cout << " ";
		cout << "��" << endl;
	}

	cct_setcolor(7, 0);
	cout << "��";
	for (int i = 0; i < two; ++i)
		cout << "��";
	cout << "��" << endl;

	for (int i = 0; i < one; ++i)
	{
		cct_gotoxy(2, i + 2);
		for (int j = 0; j < two; ++j)
		{
			if (ball[i][j])
			{
				cct_setcolor(14, ball[i][j]);
				cout << "��";
				cct_setcolor(7, 0);
			}
			else
			{
				cct_setcolor(7, 0);
				cout << "  ";
			}
		}
	}
	cct_setcolor(0, 7);
}

//��ӡ���б߿�ģ��ڶ���αͼ�λ��ĺ���
void print_two(int one, int two, int ball[max_num][max_num])
{
	cout << endl;
	cct_setcolor(7, 0);
	cout << "��";
	for (int i = 1; i < two; ++i)
		cout << "����";
	cout << "����" << endl;

	for (int i = 1; i < one; ++i)
	{
		cct_setcolor(7, 0);
		for (int j = 0; j < two; ++j)
			cout << "��" << "  ";
		cout << "��" << endl;

		cout << "��";
		for (int j = 1; j < two; ++j)
			cout << "����";
		cout << "����" << endl;
	}
	for (int j = 0; j < two; ++j)
		cout << "��" << "  ";
	cout << "��" << endl;

	cct_setcolor(7, 0);
	cout << "��";
	for (int i = 1; i < two; ++i)
		cout << "����";
	cout << "����" << endl;


	for (int i = 0; i < one; ++i)
	{
		for (int j = 0; j < two; ++j)
		{
			if (ball[i][j])
			{
				cct_setcolor(14, ball[i][j]);
				cct_gotoxy(4 * j + 2, 2 * i + 2);
				cout << "��";
				cct_setcolor(7, 0);
			}
		}
	}
	cct_setcolor(0, 7);
}

//��ӡ��ʼ�ĵ÷ֿ�
void print_score()
{
	cct_gotoxy(40, 1);
	cct_setcolor(7, 0);
	cout << "��";
	for (int i = 0; i < 5; ++i)
		cout << "��";
	cout << "��";
	cct_gotoxy(40, 2);
	cout << "��";
	cout << "�÷֣�0   ";
	cout << "��";
	cct_gotoxy(40, 3);
	cout << "��";
	for (int i = 0; i < 5; ++i)
		cout << "��";
	cout << "��";
}

//��ӡ��ʼ��Ԥ����������Ŀ�
void print_ball()
{
	cct_setcolor(7, 0);
	cct_gotoxy(40, 5);
	cout << "�����ש��ש���";
	cct_gotoxy(40, 6);
	cout << "��";

	for (int i = 0; i < 3; ++i)
		cout << "��" << "��";
	cct_gotoxy(40, 7);
	cout << "�����ߩ��ߩ���";
}

//��ӡ����ʼ�ļ���������Ŀ�
void print_count(int one, int two, int ballnum[8])
{
	cct_setcolor(7, 0);
	cct_gotoxy(40, 9);
	cout << "������������������������������";
	cct_gotoxy(40, 10);
	cout << "��" << "  :" << setw(2) << one * two - 5 << "/(" 
		<< setw(5) << setiosflags(ios::right) << setiosflags(ios::fixed) 
		<< setprecision(2) << 100.0 * (one * two - 5) / (one * two) << "%) ����-0     ��";

	for (int i = 1; i <= 7; ++i)
	{
		cct_gotoxy(40, 10 + i);
		cout << "��";
		cct_setcolor(14, i);
		cout << "��";
		cct_setcolor(7, 0);
		cout << ":" << setw(2) << setiosflags(ios::right) << ballnum[i] 
			<< "/(" << setiosflags(ios::right) << setw(5) << setiosflags(ios::fixed) 
			<< setprecision(2) << 100.0 * ballnum[i] / (one * two) << "%) ����-0     ��";
	}
	cct_gotoxy(40, 18);
	cout << "������������������������������";
}

//����������������ı�ǩ���飬����ƶ����̣��ƶ�һ�λ� Sleep(Sleeptime)
int move(int ball[max_num][max_num], int label[max_num][max_num], 
	int chucun[max_num][max_num], int x, int y, int i, int j, int one, int two)
{
	int a = 0;
	chucun[x][y] = 1;
	if (x >= 1 && label[x - 1][y] == -1 && chucun[x - 1][y] == 0)
	{
		cct_gotoxy(4 * y + 2, 2 * x + 2);
		cct_setcolor(7, 0);
		cout << "  ";
		cct_gotoxy(4 * y + 2, 2 * x + 1);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);
		cct_gotoxy(4 * y + 2, 2 * x + 1);
		cct_setcolor(7, 0);
		cout << "��";
		cct_gotoxy(4 * y + 2, 2 * x);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);

		if (x - 1 == i && y == j)
			return 1;
		else
			a = move(ball, label, chucun, x - 1, y, i, j, one, two);
		if (a)
			return 1;
	}
	else if (x < one - 1 && label[x + 1][y] == -1 && chucun[x + 1][y] == 0)
	{
		cct_gotoxy(4 * y + 2, 2 * x + 2);
		cct_setcolor(7, 0);
		cout << "  ";
		cct_gotoxy(4 * y + 2, 2 * x + 3);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);
		cct_gotoxy(4 * y + 2, 2 * x + 3);
		cct_setcolor(7, 0);
		cout << "��";
		cct_gotoxy(4 * y + 2, 2 * x + 4);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);

		if (x + 1 == i && y == j)
			return 1;
		else
			move(ball, label, chucun, x + 1, y, i, j, one, two);
		if (a)
			return 1;
	}
	else if (y >= 1 && label[x][y - 1] == -1 && chucun[x][y - 1] == 0)
	{
		cct_gotoxy(4 * y + 2, 2 * x + 2);
		cct_setcolor(7, 0);
		cout << "  ";
		cct_gotoxy(4 * y, 2 * x + 2);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);
		cct_gotoxy(4 * y, 2 * x + 2);
		cct_setcolor(7, 0);
		cout << "��";
		cct_gotoxy(4 * y - 2, 2 * x + 2);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);

		if (x == i && y - 1 == j)
			return 1;
		else
			move(ball, label, chucun, x, y - 1, i, j, one, two);
		if (a)
			return 1;
	}
	else if (y < two - 1 && label[x][y + 1] == -1 && chucun[x][y + 1] == 0)
	{
		cct_gotoxy(4 * y + 2, 2 * x + 2);
		cct_setcolor(7, 0);
		cout << "  ";
		cct_gotoxy(4 * y + 4, 2 * x + 2);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);
		cct_gotoxy(4 * y + 4, 2 * x + 2);
		cct_setcolor(7, 0);
		cout << "��";
		cct_gotoxy(4 * y + 6, 2 * x + 2);
		cct_setcolor(14, ball[i][j]);
		cout << "��";
		Sleep(Sleeptime);

		if (x == i && y + 1 == j)
			return 1;
		else
			move(ball, label, chucun, x, y + 1, i, j, one, two);
		if (a)
			return 1;
	}
	return 0;
}

//�˵� ѡ����
void choice_four()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };

	input_menu(one, two);

	get_int(one, two, ball, 1);

	print_int(one, two, ball, ball, 1);

	cout << "���س�����ʾͼ��...";

	char ch;
	while (!((ch = _getch()) == '\r'));

	cct_cls();

	print_one(one, two, ball);

	print_size(1);

	cct_gotoxy(0, one + 3);
	end();

	cct_cls();
	menu();
	return;
}

//�˵� ѡ����
void choice_five()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };

	input_menu(one, two);

	get_int(one, two, ball, 1);

	print_int(one, two, ball, ball, 1);

	cout << "���س�����ʾͼ��...";

	char ch;
	while (!((ch = _getch()) == '\r'));

	cct_cls();

	print_two(one, two, ball);

	print_size(1);

	cct_gotoxy(0, 2 * one + 2);
	end();

	cct_cls();
	menu();
	return;
}

//�˵� ѡ����
void choice_six()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };

	input_menu(one, two);

	get_int(one, two, ball, 2);

	cct_cls();
	print_two(one, two, ball);

	print_size(2);

	cct_enable_mouse();

	int MX, MY, MAction, keycode1, keycode2;

	while (1)
	{
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (MAction == MOUSE_ONLY_MOVED)
		{
			int i = 0, j = 0, lab = 0, el = 0;
			for (i = 0; i < one; ++i)
				if (MY == 2 * i + 2)
				{
					lab = 1;
					break;
				}

			for (j = 0; j < two; ++j)
				if ((MX == 4 * j + 2) || (MX == 4 * j + 3))
				{
					el = 1;
					break;
				}
			if (lab && el)
			{
				cct_gotoxy(0, 2 * one + 2);
				cout << "                                      ";

				cct_gotoxy(0, 2 * one + 2);
				cout << "[��ǰ���]" << char(i + 'A') << "��" << j + 1 << "��";
			}
		}
		else if (MAction == MOUSE_LEFT_BUTTON_CLICK)
		{
			static int x = 0, y = 0, labelone = 0;
			int i = 0, j = 0, lab = 0, el = 0;

			for (i = 0; i < one; ++i)
				if (MY == 2 * i + 2)
				{
					lab = 1;
					break;
				}

			for (j = 0; j < two; ++j)
				if ((MX == 4 * j + 2) || (MX == 4 * j + 3))
				{
					el = 1;
					break;
				}

			if (labelone)
			{
				if (ball[i][j] == 0)
				{

					int label[max_num][max_num] = { 0 };
					int chucun[max_num][max_num] = { 0 };
					int back;
					char ball_num[5], ball_ber[5];

					ball_num[0] = x + 'A';
					ball_num[1] = y + '1';
					ball_ber[0] = i + 'A';
					ball_ber[1] = j + '1';
					back = DFS(x, y, label, ball, one, two, ball_num, ball_ber);

					if (!back)
					{
						cct_gotoxy(0, 2 * one + 2);
						cout << "[����] �޷���[" << char(x + 'A') << y + 1 
							<< "]�ƶ���[" << char(i + 'A') << j + 1 << "]" << endl;
					}
					else
					{
						ball[ball_ber[0] - 'A'][ball_ber[1] - '1'] = 
							ball[ball_num[0] - 'A'][ball_num[1] - '1'];
						ball[ball_num[0] - 'A'][ball_num[1] - '1'] = 0;

						move(ball, label, chucun, x, y, i, j, one, two);
						cct_setcolor(0, 7);
						labelone = x = y = 0;
						break;

					}
				}
				else
				{
					cct_gotoxy(4 * y + 2, 2 * x + 2);
					cct_setcolor(14, ball[i][j]);
					cout << "��";
					cct_setcolor(0, 7);
				}
			}

			if (lab && el && ball[i][j] != 0)
			{
				cct_gotoxy(4 * j + 2, 2 * i + 2);
				cct_setcolor(14, ball[i][j]);
				cout << "��";
				cct_setcolor(0, 7);
				labelone = 1;
				x = i;
				y = j;
			}
		}
		else if (MAction == MOUSE_RIGHT_BUTTON_CLICK)
			break;
	}

	cct_gotoxy(0, 2 * one + 2);
	end();

	cct_cls();
	menu();
	return;
}

//�˵� ѡ����
void choice_seven()
{
	int one, two;
	int ball[max_num][max_num] = { 0 };
	int next[3];

	input_menu(one, two);

	get_int(one, two, ball, 1);

	cct_cls();
	print_two(one, two, ball);

	print_score();
	print_ball();

	int ballnum[8] = { 0 };
	int out[8] = { 0 };
	for (int i = 0; i < one; ++i)
	{
		for (int j = 0; j < two; ++j)
		{
			if (ball[i][j])
				++ballnum[ball[i][j]];
		}
	}

	print_count(one, two, ballnum);

	cct_setcolor(0, 7);
	print_size(2);

	cct_enable_mouse();

	int MX, MY, MAction, keycode1, keycode2;

	int score_num = 0, score_get = 0;
	int n = 5, size = 1;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		next[i] = rand() % 7 + 1;
		cct_gotoxy(42 + 4 * i, 6);
		cct_setcolor(14, next[i]);
		cout << "��";
	}
	cct_setcolor(0, 7);

	//���û�п�λ�˳�ѭ��
	while (n < one * two)
	{
		//���û��������ͬʱ�������һ���ƶ��͸���������
		while (1)
		{
			if (!size)
			{
				srand((unsigned)time(NULL));
				for (int i = 0; i < 3; ++i)
				{
					next[i] = rand() % 7 + 1;
					cct_gotoxy(42 + 4 * i, 6);
					cct_setcolor(14, next[i]);
					cout << "��";
				}
				cct_setcolor(0, 7);
				size = 1;
			}
			cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
			if (MAction == MOUSE_ONLY_MOVED)
			{
				int i = 0, j = 0, lab = 0, el = 0;
				for (i = 0; i < one; ++i)
					if (MY == 2 * i + 2)
					{
						lab = 1;
						break;
					}

				for (j = 0; j < two; ++j)
					if ((MX == 4 * j + 2) || (MX == 4 * j + 3))
					{
						el = 1;
						break;
					}
				if (lab && el)
				{
					cct_gotoxy(0, 2 * one + 2);
					cout << "                                      ";
					cct_gotoxy(0, 2 * one + 2);
					cout << "[��ǰ���]" << char(i + 'A') << "��" << j + 1 << "��";
				}
			}

			else if (MAction == MOUSE_LEFT_BUTTON_CLICK)
			{
				//x��y�����ϴ���������λ�ã�labelone�����Ƿ��Ѿ�ѡ��һ������
				static int x = 0, y = 0, labelone = 0;
				int i = 0, j = 0, lab = 0, el = 0;

				//�ҵ����λ�ã�������ڱ߿��ϣ���lab��el��Ϊ1
				for (i = 0; i < one; ++i)
					if (MY == 2 * i + 2)
					{
						lab = 1;
						break;
					}

				for (j = 0; j < two; ++j)
					if ((MX == 4 * j + 2) || (MX == 4 * j + 3))
					{
						el = 1;
						break;
					}

				//����ϴ�ѡ������
				if (labelone)
				{
					//����ٴ�ѡ�е�λ�����򣬳����ƶ�
					if (ball[i][j] == 0)
					{
						int label[max_num][max_num] = { 0 };
						int chucun[max_num][max_num] = { 0 };
						int back;
						char ball_num[5], ball_ber[5];

						ball_num[0] = x + 'A';
						ball_num[1] = y + '1';
						ball_ber[0] = i + 'A';
						ball_ber[1] = j + '1';
						back = DFS(x, y, label, ball, one, two, ball_num, ball_ber);

						//������������������Ƿ���·��
						if (!back)
						{
							cct_gotoxy(0, 2 * one + 2);
							cout << "[����] �޷���[" << char(x + 'A') << y + 1 
								 << "]�ƶ���[" << char(i + 'A') << j + 1 << "]" << endl;
						}
						//�ҵ���·��
						else
						{
							int color = ball[ball_num[0] - 'A'][ball_num[1] - '1'];
							ball[ball_ber[0] - 'A'][ball_ber[1] - '1'] = 
								ball[ball_num[0] - 'A'][ball_num[1] - '1'];
							ball[ball_num[0] - 'A'][ball_num[1] - '1'] = 0;

							//ʵ���ƶ�
							move(ball, label, chucun, x, y, i, j, one, two);
							cct_setcolor(0, 7);
							//������Щ������Ϊ0��
							labelone = x = y = 0;

							//�ƶ����Ƿ�����������ĵط�
							size = score(i, j, one, two, ball, score_get, score_num);
							//��������
							if (size)
							{
								n -= size;
								cct_gotoxy(48, 2);
								cct_setcolor(7, 0);
								cout << score_num;
								cct_gotoxy(0, 0);
								print_two(one, two, ball);
								out[color] += size;
								ballnum[color] -= size;
							}
							else
								n += 3;
							//����Ԥ�����
							if (!size)
							{
								int a, b;
								a = b = 0;
								srand((unsigned)time(NULL));
								if (n < one * two)
									for (int k = 0; k < 3; ++k)
									{
										a = rand() % one;
										b = rand() % two;

										if (ball[a][b])
											--k;
										else
										{
											ball[a][b] = next[k];
											++ballnum[next[k]];
											cct_gotoxy(4 * b + 2, 2 * a + 2);
											cct_setcolor(14, ball[a][b]);
											cout << "��";
											cct_setcolor(0, 7);
										}
									}

								else
								{
									for (int k = 0; k < 3+one*two-n; ++k)
									{
										a = rand() % one + 0;
										b = rand() % two + 0;

										if (ball[a][b]!=0)
											--k;
										else
										{
											ball[a][b] = next[k];
											++ballnum[next[k]];
											cct_gotoxy(4 * b + 2, 2 * a + 2);
											cct_setcolor(14, ball[a][b]);
											cout << "��";
											cct_setcolor(0, 7);
										}
									}
									break;
								}
							}
							cct_gotoxy(45, 10);
							ballnum[0] = one * two - n;
							cct_setcolor(7, 0);
							cout << setw(2) << setiosflags(ios::right) 
								<< one * two - n << "/(" << setw(5) << setiosflags(ios::right) 
								<< setprecision(2) << setiosflags(ios::fixed) 
								<< 100.0 * (one * two - n) / (one * two);

							for (int i = 1; i <= 7; ++i)
							{
								cct_gotoxy(45, 10 + i);

								cct_setcolor(7, 0);
								cout << setw(2) << setiosflags(ios::right) 
									<< ballnum[i] << "/(" << setw(5) 
									<< setiosflags(ios::right) << setprecision(2) 
									<< setiosflags(ios::fixed) << 100.0 * ballnum[i] / (one * two);
								cct_gotoxy(62, 10 + i);
								cout << out[i];
								cct_setcolor(0, 7);
							}
						}
					}
					else
					{
						cct_gotoxy(4 * y + 2, 2 * x + 2);
						cct_setcolor(14, ball[x][y]);
						cout << "��";
						cct_setcolor(0, 7);
					}
				}

				if (lab && el && ball[i][j] != 0)
				{
					cct_gotoxy(4 * j + 2, 2 * i + 2);
					cct_setcolor(14, ball[i][j]);
					cout << "��";
					cct_setcolor(0, 7);
					labelone = 1;
					x = i;
					y = j;
				}
			}
			else if (MAction == MOUSE_RIGHT_BUTTON_CLICK)
				break;
		}
	}

	cct_gotoxy(0, 2 * one + 2);
	end();

	cct_cls();
	menu();
	return;
}