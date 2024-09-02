/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */

	cout << "请输入间隔含有若干正负数字的字符串" << endl;

	//输入字符串
	gets_s(str, 256);

	//pa和pnum与一维数组地址对应
	pa = a;
	pnum = a;
	//p与str字符串数组对应
	p = str;

	while (*p != '\0'&&pa-pnum<10)
	{
		//如果发现了有符合循环的，开启循环
		if (*p >= '0' && *p <= '9')
		{
			while (*p >= '0' && *p <= '9')
			{
				//采用进位的方式来实现字符串转为数
				*pa = *pa * 10 + (*p - '0');
				++p;
			}
			++pa;
		}
		else
			++p;
	}

	cout << "共有" << pa - pnum << "个整数" << endl;

	while (pa - pnum)
	{
		cout << *pnum << " ";
		++pnum;
	}

	cout << endl;

	return 0;
}