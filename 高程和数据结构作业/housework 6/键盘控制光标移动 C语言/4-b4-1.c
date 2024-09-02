/* 2152118 史君宝 计科 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
char menu()
{
	char fanhui;
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n" );
	printf("3.用箭头键控制上下左右，边界停止\n" );
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("0.退出\n" );
	printf("[请选择0-4]");
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
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
			/* 此句的作用是调用系统的cls命令清屏 */
			cls(hout);

			/* 显示初始的边框及其中的随机字符 */
			init_border(hout);
			gotoxy(hout, x, y);
			if (xuanze == '1' || xuanze == '2')
				move_by_ijkl(hout, x, y, xuanze);
			else if (xuanze == '3' || xuanze == '4')
				move_by_arrow(hout, x, y, xuanze);
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键退出.\n");
			caozuo = _getch();
			while (caozuo != 13)
				caozuo = _getch();
			cls(hout);
		}
	}
}
/*不一定有20个是因为，生成的伪随机数可能会重复，位置是一样的，所以不一定有20个*/