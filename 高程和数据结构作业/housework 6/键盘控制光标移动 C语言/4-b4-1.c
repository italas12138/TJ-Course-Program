/* 2152118 ʷ���� �ƿ� */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
char menu()
{
	char fanhui;
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n" );
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n" );
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("0.�˳�\n" );
	printf("[��ѡ��0-4]");
	do
		fanhui = _getch();
	while (!(fanhui == '0' || fanhui == '1' || fanhui == '2' || fanhui == '3'
		|| fanhui == '4' || fanhui == '5' || fanhui == '6'));
	return fanhui;
}

void move_by_ijkl(const HANDLE hout, int X, int Y, const char ch)
{
	char caozuo;
	caozuo = _getch();
	while (caozuo != 'q')
	{
		if (caozuo == 'i' || caozuo == 'I')
			if (ch == '2' && Y == 1)
				gotoxy(hout, X, Y = 17);
			else
				if (Y > 1)
					gotoxy(hout, X, --Y);
		if (caozuo == 'j' || caozuo == 'J')
			if (ch == '2' && X == 1)
				gotoxy(hout, X = 69, Y);
			else
				if (X > 1)
					gotoxy(hout, --X, Y);
		if (caozuo == 'k' || caozuo == 'K')
			if (ch == '2' && Y == 17)
				gotoxy(hout, X, Y = 1);
			else
				if (Y < 17)
					gotoxy(hout, X, ++Y);
		if (caozuo == 'l' || caozuo == 'L')
			if (ch == '2' && X == 69)
				gotoxy(hout, X = 1, Y);
			else
				if (X < 69)
					gotoxy(hout, ++X, Y);
		if (caozuo == ' ')
		{
			showch(hout, X, Y, ' ');
			gotoxy(hout, X, Y);
		}
		caozuo = _getch();
	}
	return;
}
void move_by_arrow(const HANDLE hout, int X, int Y, const char ch)
{
	char caozuo1, caozuo2 = ' ', cm = ' ';
	caozuo1 = _getch();
	while (caozuo1 != 'q')
	{
		if (caozuo1 == -32)
		{
			caozuo2 = _getch();
			if (caozuo2 == 72)
			{
				if (ch == '4' && Y == 1)
					gotoxy(hout, X, Y = 17);
				if (Y > 1)
					gotoxy(hout, X, --Y);
			}
			else if (caozuo2 == 77)
			{
				if (ch == '4' && X == 69)
					gotoxy(hout, X = 1, Y);
				else
					if (X < 69)
						gotoxy(hout, ++X, Y);
			}
			else if (caozuo2 == 75)
			{
				if (ch == '4' && X == 1)
					gotoxy(hout, X = 69, Y);
				else
					if (X > 1)
						gotoxy(hout, --X, Y);
			}
			else if (caozuo2 == 80)
			{
				if (ch == '4' && Y == 17)
					gotoxy(hout, X, Y = 1);
				else
					if (Y < 17)
						gotoxy(hout, X, ++Y);
			}
		}
		else if (caozuo1 == ' ')
		{
			showch(hout, X, Y, ' ');
			gotoxy(hout, X, Y);
		}
		caozuo1 = _getch();
	}
	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	int x = 35, y = 9;
	char xuanze, caozuo;
	while (1)
	{
		x = 35;
		y = 9;
		xuanze = menu();
		if (xuanze == '0')
			return 0;
		else
		{
			/* �˾�������ǵ���ϵͳ��cls�������� */
			cls(hout);

			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);
			gotoxy(hout, x, y);
			if (xuanze == '1' || xuanze == '2')
				move_by_ijkl(hout, x, y, xuanze);
			else if (xuanze == '3' || xuanze == '4')
				move_by_arrow(hout, x, y, xuanze);
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س����˳�.\n");
			caozuo = _getch();
			while (caozuo != 13)
				caozuo = _getch();
			cls(hout);
		}
	}
}
/*��һ����20������Ϊ�����ɵ�α��������ܻ��ظ���λ����һ���ģ����Բ�һ����20��*/