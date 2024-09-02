/* 2152118 史君宝 计科 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw(2*(end_ch-'A'+1)) <<" " << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A' + 1)) << " " << endl;/* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A',end_ch, end_ch - 'A',1);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw(2 * (end_ch - 'A' + 1)) << " " << endl;/* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A' + 1)) << " " << endl;/* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower( end_ch,'A', end_ch - 'A', 0);
	cout << endl;

	return 0;
}