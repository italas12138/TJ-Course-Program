/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ����;�̬�ֲ�����
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
   **************************************************************************/


void printfqian(char qishi, int i)
{
	cout << char(qishi + i);
	if (i == 1)
		return;
	--i;
	printfqian(qishi, i);
}
void printfqian0(char qishi, int i)
{
	cout << char(qishi - i);
	if (i == 1)
		return;
	--i;
	printfqian0(qishi, i);
}
void printfhou(char qishi, int i)
{
	--i;
	if (i == 0)
		return;
	printfhou(qishi, i);
	cout << char(qishi + i);
}
void printfhou0(char qishi, int i)
{
	--i;
	if (i == 0)
		return;
	printfhou0(qishi, i);
	cout << char(qishi - i);
}
void printfhang(char qishi, int n)
{
	printfqian(qishi, n);
	cout << qishi;
	printfhou(qishi, n + 1);
}
void printfhang0(char qishi, int n)
{
	printfqian0(qishi, n);
	cout << qishi;
	printfhou0(qishi, n + 1);
}
void printf(char qishi, char end_ch, int n)
{
	--n;
	if (n == 0)
		return;
	printf(qishi, end_ch, n);
	cout <<setw(end_ch - qishi - n + 1);
	printfhang(qishi, n);
	cout << endl;
}
void printf0(char qishi, char end_ch, int n)
{
	--n;
	if (n == 0)
		return;
	cout << setw(qishi - end_ch - n + 1);
	printfhang0(qishi, n);
	cout << endl;
	printf0(qishi, end_ch, n);
}
void print_tower(char qishi, char end_ch, int n, bool zhengni)
{
	if (zhengni == 1)
	{
		cout << setfill(' ') << setw(n + 1) << qishi << endl;
		printf(qishi, end_ch, n + 1);
	}
	if (zhengni == 0)
	{
		cout << setfill(' ');
		printf0(qishi, end_ch, n + 1);
		cout<< setw(n + 1) << qishi << endl;
	}
	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw(2*(end_ch-'A'+1)) <<" " << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A' + 1)) << " " << endl;/* ����ĸ����������=(��������ѭ��) */
	print_tower('A',end_ch, end_ch - 'A',1);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw(2 * (end_ch - 'A' + 1)) << " " << endl;/* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A' + 1)) << " " << endl;/* ����ĸ����������=(��������ѭ��) */
	print_tower( end_ch,'A', end_ch - 'A', 0);
	cout << endl;

	return 0;
}