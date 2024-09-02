#pragma once

/* 2152118 史君宝 计科 */

#define max_num 9

void choice_one();

void choice_two();

void choice_three();

void choice_four();

void choice_five();

void choice_six();

void choice_seven();

void menu();

//输入菜单，完成每个子程序，行列的输入
void input_menu(int& one, int& two);

//为彩球的二维数组ball[][]，赋初值，根据level,确定是5个还是60%。
void get_int(int one, int two, int ball[max_num][max_num], int level);

//打印彩球的二维数组形式
void print_int(int one, int two, int ball[max_num][max_num], 
	int label[max_num][max_num], int level);

//结束函数，输入end，回到主菜单。
void end();

//深度优先搜索函数，找到移动路径
//x,y为搜索的位置，标签数组label,彩球数组ball,one和two是行列信息，ball_num和ball_ber储存移动前后位置
int DFS(int x, int y, int label[max_num][max_num], int ball[max_num][max_num], 
	int one, int two, char ball_num[], char ball_ber[]);

//搜索移动后的彩球上下左右，将能够消掉的球消掉，并返回消掉的彩球数
int score(int x, int y, int one, int two, int ball[max_num][max_num], 
	int& score_get, int& score_num);
