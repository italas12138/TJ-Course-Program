#pragma once
/*2152118 Ê·¾ý±¦ ¼Æ¿Æ*/


void print_nine();
void print_W();
void print_zero();
void print_B();
void print_F();
void print_S();
void print_R();

void menu();
int read_file(int& number, char problem_number[100][5]);
void problem_menu(int number, char problem_number[100][5]);
void move_menu(int number, char problem_number[100][5]);
void open_txt(char ch[5], int number, char problem_number[100][5]);