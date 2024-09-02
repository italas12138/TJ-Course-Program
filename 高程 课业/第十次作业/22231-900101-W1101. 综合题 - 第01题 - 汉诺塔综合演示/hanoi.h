/* �ƿ� 2152118 ʷ���� */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

void choosemenu();

void menu();

void menu();

void return_menu(int choice);

void wait();

void moveAB();

void moveAC();

void moveBA();

void moveBC();

void moveCA();

void moveCB();

void photo_hanoi();

void photo_circle(char qishi);

void move_circle(int choice, char qishi, char zhongjian, char mubiao);

void print_heng(int n, char qishi, char zhongjina, char mubiao, int choice);

void move(char qishi, char zhongjian, char mubiao, int choice, int X);

void print_zong(char qishi, int X);

void input(int& n, char& qishi, char& mubiao, int& choice);

void output(int choice, int n, char src, char tmp, char dst);

void cinplay(char qishi, char zhongjian, char mubiao, int n);

void hanoi(int n, char src, char tmp, char dst, int choice);

void makesurerod(int n, char qishi, char mubiao, char& zhongjian);

void choicenum(int choice);


