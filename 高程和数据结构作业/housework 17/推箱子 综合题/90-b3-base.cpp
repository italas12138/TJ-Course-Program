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

//读stage的文件夹，获得其中的txt文件信息
int read_file(int& number, char problem_number[100][5])
{
	/*
	in_path  stage文件的地址
	in_name  需要打开的txt文件的文件名
	curr     帮助查找stage文件中的txt文件
	*/
	struct _finddata_t fileinfo;
	char in_path[100] = ".\\stage", in_name[100], curr[100];
	char txt_ch[5] = ".txt";
	bool compareone = 0;


	//对curr数组初始化
	strcpy(curr, in_path);
	strcat(curr, "\\*.txt");

	long handle;
	if ((handle = _findfirst(curr, &fileinfo)) == -1L)
	{
		cct_cls();
		cout << "无法找到任何关卡文件!" << endl;
		return 1;
	}
	else
	{
		if (!strncmp(fileinfo.name, "Sokoban-Level-", 14))
		{
			for (int i = 17; i < 20; ++i)
				if (fileinfo.name[i] == txt_ch[i - 17])
					continue;
				else
				{
					compareone = 1;
					break;
				}
			if (!compareone)
			{
				for (int i = 14; i < 17; ++i)
					problem_number[number][i - 14] = fileinfo.name[i];
				problem_number[number][3] = '\0';

				++number;
			}
		}
		compareone = 0;


		while (!_findnext(handle, &fileinfo))
		{
			if (!strncmp(fileinfo.name, "Sokoban-Level-", 14))
			{
				for (int i = 17; i < 20; ++i)
					if (fileinfo.name[i] == txt_ch[i - 17])
						continue;
					else
					{
						compareone = 1;
						break;
					}
				if (!compareone)
				{
					strcpy(in_name, in_path);
					strcat(in_name, "\\");
					strcat(in_name, fileinfo.name);
					for (int i = 14; i < 17; ++i)
						problem_number[number][i - 14] = fileinfo.name[i];
					problem_number[number][3] = '\0';

					++number;
				}
			}
			compareone = 0;
		}
		_findclose(handle);
		if (number == 0)
		{
			cout << "无法找到任何关卡文件!" << endl;
			return 1;
		}
	}
	return 0;
}

//打印选择关卡的菜单
void problem_menu(int number, char problem_number[100][5])
{
	int i = 0;
	cct_gotoxy(100, 2);
	cout << "请选择关卡";
	cct_gotoxy(100, 3);
	cout << "╔════╗";
	for (i = 0; i < number && i < 25; ++i)
	{
		cct_gotoxy(100, 4 + i);
		cout << "║ 关卡" << problem_number[i] << "║";
	}
	cct_gotoxy(100, 4 + i);
	cout << "╚════╝";

	return;
}

//实现关卡选择的时候，菜单的移动
void move_menu(int number, char problem_number[100][5])
{
	int low, high, place;
	if (number <= 25)
	{
		low = place = 0;
		high = number - 1;
	}
	else
	{
		low = place = 0;
		high = 24;
	}
	cct_gotoxy(100, 4 + place);
	cct_setcolor(7, 0);
	cout << "║ 关卡" << problem_number[place] << "║";
	cct_setcolor(0, 7);

	char caozuo1 = ' ', caozuo2 = ' ';
	while (1)
	{
		caozuo1 = _getch();
		if (caozuo1 == -32)
		{
			caozuo2 = _getch();
			if (caozuo2 == 72)
			{
				if (place)
				{
					cct_gotoxy(100, 4 + place);
					cout << "║ 关卡" << problem_number[low + place] << "║";
					--place;
					cct_gotoxy(100, 4 + place);
					cct_setcolor(7, 0);
					cout << "║ 关卡" << problem_number[low + place] << "║";
					cct_setcolor(0, 7);
				}
				else
				{
					if (number <= 25);
					else
					{
						if (!low);
						else
						{
							--low;
							--high;
							for (int k = 0; k < number && k < 25; ++k)
							{
								if (k == 0)
								{
									cct_setcolor(7, 0);
									cct_gotoxy(100, 4 + k);
									cout << "║ 关卡" << problem_number[low + k] << "║";
									cct_setcolor(0, 7);
								}
								else
								{
									cct_gotoxy(100, 4 + k);
									cout << "║ 关卡" << problem_number[low + k] << "║";
								}
							}
						}
					}
				}
			}
			else if (caozuo2 == 80)
			{
				if (place < number - 1 && place < 24)
				{
					cct_gotoxy(100, 4 + place);
					cout << "║ 关卡" << problem_number[low + place] << "║";
					++place;
					cct_gotoxy(100, 4 + place);
					cct_setcolor(7, 0);
					cout << "║ 关卡" << problem_number[low + place] << "║";
					cct_setcolor(0, 7);
				}
				else
				{
					if (number <= 25);
					else
					{
						if (place != 24);
						else if (high < number - 1)
						{
							++low;
							++high;
							for (int k = 0; k < number && k < 25; ++k)
							{
								if (k == 24)
								{
									cct_setcolor(7, 0);
									cct_gotoxy(100, 4 + k);
									cout << "║ 关卡" << problem_number[low + k] << "║";
									cct_setcolor(0, 7);
								}
								else
								{
									cct_gotoxy(100, 4 + k);
									cout << "║ 关卡" << problem_number[low + k] << "║";
								}
							}
						}
					}
				}
			}
		}
		else if (caozuo1 == '\r')
		{
			open_txt(problem_number[low + place], number, problem_number);
			if (number <= 25)
			{
				low = place = 0;
				high = number - 1;
			}
			else
			{
				low = place = 0;
				high = 24;
			}
			cct_gotoxy(100, 4 + place);
			cct_setcolor(7, 0);
			cout << "║ 关卡" << problem_number[place] << "║";
			cct_setcolor(0, 7);
		}
		else if (caozuo1 == 27)
		{
			char stringone[10] = " ";
			while (!(stringone[0] == 'e' || stringone[0] == 'E') &&
				!(stringone[1] == 'n' || stringone[1] == 'N') &&
				!(stringone[2] == 'd' || stringone[1] == 'D'))
			{
				cct_gotoxy(0, 45);
				cout << "本小题结束，请输入End继续...";

				cin >> stringone;
				cct_gotoxy(0, 45);
				cout << (28, 45);
				cout << "                         " << endl;
				cout << "输入错误，请重新输入";
			}
			menu();
			break;
		}
	}
	return;
}

void open_txt(char ch[5], int number, char problem_number[100][5])
{
	char in_name[100], in_path[100] = ".\\stage";
	strcpy(in_name, in_path);
	strcat(in_name, "\\");
	strcat(in_name, "Sokoban-Level-");
	strcat(in_name, ch);
	strcat(in_name, ".txt");

	ifstream infile;
	infile.open(in_name, ios::in | ios::binary);
	if (infile.is_open() == 0)
	{
		cout << "Sokoban-Level-" << ch << ".txt文件打开失败";
		return;
	}

	char str = ' ';
	bool error = 0;
	int line = 0, column = 0, print[14][16] = { 0 };
	for (line = 0; str != EOF && line < 14 && error == 0; ++line)
	{
		for (column = 0; str != EOF && column < 16; ++column)
		{
			str = infile.get();
			if (str == '9')
				print[line][column] = 1;

			else if (str == 'W' || str == 'w')
				print[line][column] = 2;

			else if (str == '0')
				print[line][column] = 3;

			else if (str == 'B' || str == 'b')
				print[line][column] = 4;

			else if (str == 'F' || str == 'f')
				print[line][column] = 5;

			else if (str == 'S' || str == 's')
				print[line][column] = 6;

			else if (str == 'R' || str == 'r')
				print[line][column] = 7;

			else if (str == EOF)
				break;
			else if (str == '\r')
			{
				str = infile.get();
				break;
			}
			else
			{
				error = 1;
				break;
			}
		}
	}
	if (error == 1)
	{
		--line;
		cct_gotoxy(0, 45);
		cout << "推箱子数据文件[Sokoban-Level-" << ch << ".txt]有非法字符（"
			<< line + 1 << "行" << column + 1 << "列" << "），按回车键继续" << endl;
		str = ' ';
		while ((str = _getch()) != '\r');
		cct_cls();
		problem_menu(number, problem_number);
		return;
	}
	else
	{
		for (int i = 0; i < 14; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 1)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_nine();
				}
			}
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 2)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_W();
				}
			}
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 3)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_zero();
				}
			}
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 4)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_B();
				}
			}
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 5)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_F();
				}
			}
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 6)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_S();
				}
			}
			for (int j = 0; j < 16; ++j)
			{
				if (print[i][j] == 7)
				{
					cct_gotoxy(6 * j, 3 * i);
					print_R();
				}
			}
		}
		cct_gotoxy(0, 45);
		cout << "关卡显示完成，按C/c继续";
		str = ' ';
		while (!((str = _getch()) == 'C' || str == 'c'));

		cct_cls();
		problem_menu(number, problem_number);
		return;
	}
}