/* 计科 2152118 史君宝 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
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


