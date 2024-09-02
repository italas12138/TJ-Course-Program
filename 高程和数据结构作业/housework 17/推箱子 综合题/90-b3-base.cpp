/*2152118 ʷ���� �ƿ�*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <io.h>

#include "90-b3.h"
#include "cmd_console_tools.h"

using namespace std;

//��stage���ļ��У�������е�txt�ļ���Ϣ
int read_file(int& number, char problem_number[100][5])
{
	/*
	in_path  stage�ļ��ĵ�ַ
	in_name  ��Ҫ�򿪵�txt�ļ����ļ���
	curr     ��������stage�ļ��е�txt�ļ�
	*/
	struct _finddata_t fileinfo;
	char in_path[100] = ".\\stage", in_name[100], curr[100];
	char txt_ch[5] = ".txt";
	bool compareone = 0;


	//��curr�����ʼ��
	strcpy(curr, in_path);
	strcat(curr, "\\*.txt");

	long handle;
	if ((handle = _findfirst(curr, &fileinfo)) == -1L)
	{
		cct_cls();
		cout << "�޷��ҵ��κιؿ��ļ�!" << endl;
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
			cout << "�޷��ҵ��κιؿ��ļ�!" << endl;
			return 1;
		}
	}
	return 0;
}

//��ӡѡ��ؿ��Ĳ˵�
void problem_menu(int number, char problem_number[100][5])
{
	int i = 0;
	cct_gotoxy(100, 2);
	cout << "��ѡ��ؿ�";
	cct_gotoxy(100, 3);
	cout << "�X�T�T�T�T�[";
	for (i = 0; i < number && i < 25; ++i)
	{
		cct_gotoxy(100, 4 + i);
		cout << "�U �ؿ�" << problem_number[i] << "�U";
	}
	cct_gotoxy(100, 4 + i);
	cout << "�^�T�T�T�T�a";

	return;
}

//ʵ�ֹؿ�ѡ���ʱ�򣬲˵����ƶ�
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
	cout << "�U �ؿ�" << problem_number[place] << "�U";
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
					cout << "�U �ؿ�" << problem_number[low + place] << "�U";
					--place;
					cct_gotoxy(100, 4 + place);
					cct_setcolor(7, 0);
					cout << "�U �ؿ�" << problem_number[low + place] << "�U";
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
									cout << "�U �ؿ�" << problem_number[low + k] << "�U";
									cct_setcolor(0, 7);
								}
								else
								{
									cct_gotoxy(100, 4 + k);
									cout << "�U �ؿ�" << problem_number[low + k] << "�U";
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
					cout << "�U �ؿ�" << problem_number[low + place] << "�U";
					++place;
					cct_gotoxy(100, 4 + place);
					cct_setcolor(7, 0);
					cout << "�U �ؿ�" << problem_number[low + place] << "�U";
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
									cout << "�U �ؿ�" << problem_number[low + k] << "�U";
									cct_setcolor(0, 7);
								}
								else
								{
									cct_gotoxy(100, 4 + k);
									cout << "�U �ؿ�" << problem_number[low + k] << "�U";
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
			cout << "�U �ؿ�" << problem_number[place] << "�U";
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
				cout << "��С�������������End����...";

				cin >> stringone;
				cct_gotoxy(0, 45);
				cout << (28, 45);
				cout << "                         " << endl;
				cout << "�����������������";
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
		cout << "Sokoban-Level-" << ch << ".txt�ļ���ʧ��";
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
		cout << "�����������ļ�[Sokoban-Level-" << ch << ".txt]�зǷ��ַ���"
			<< line + 1 << "��" << column + 1 << "��" << "�������س�������" << endl;
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
		cout << "�ؿ���ʾ��ɣ���C/c����";
		str = ' ';
		while (!((str = _getch()) == 'C' || str == 'c'));

		cct_cls();
		problem_menu(number, problem_number);
		return;
	}
}