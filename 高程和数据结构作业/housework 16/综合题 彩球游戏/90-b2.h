#pragma once

/* 2152118 ʷ���� �ƿ� */

#define max_num 9

void choice_one();

void choice_two();

void choice_three();

void choice_four();

void choice_five();

void choice_six();

void choice_seven();

void menu();

//����˵������ÿ���ӳ������е�����
void input_menu(int& one, int& two);

//Ϊ����Ķ�ά����ball[][]������ֵ������level,ȷ����5������60%��
void get_int(int one, int two, int ball[max_num][max_num], int level);

//��ӡ����Ķ�ά������ʽ
void print_int(int one, int two, int ball[max_num][max_num], 
	int label[max_num][max_num], int level);

//��������������end���ص����˵���
void end();

//������������������ҵ��ƶ�·��
//x,yΪ������λ�ã���ǩ����label,��������ball,one��two��������Ϣ��ball_num��ball_ber�����ƶ�ǰ��λ��
int DFS(int x, int y, int label[max_num][max_num], int ball[max_num][max_num], 
	int one, int two, char ball_num[], char ball_ber[]);

//�����ƶ���Ĳ����������ң����ܹ��������������������������Ĳ�����
int score(int x, int y, int one, int two, int ball[max_num][max_num], 
	int& score_get, int& score_num);
