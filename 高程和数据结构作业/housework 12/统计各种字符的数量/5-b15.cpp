/* 计科 2152118 史君宝 */

#include <iostream>
#include <string.h>
using namespace std;

char str[3][128];

int main()
{
	//输入各行的字符数组
	cout << "请输入第1行" << endl;
	cin.getline(str[0],128,'\n');
	cout << "请输入第2行" << endl;
	cin.getline(str[1],128, '\n');
	cout << "请输入第3行" << endl;
	cin.getline(str[2],128, '\n');

	//求各行字符数组的长度
	int str0, str1, str2;
	str0 = strlen(str[0]);
	str1 = strlen(str[1]);
	str2 = strlen(str[2]);

	int daxie, xiaoxie, shuzi, kongge, qita;
	daxie=xiaoxie=shuzi=kongge=qita=0;
	
	//分别统计各种字符的数量
	for (int i = 0; i < str0; ++i)
	{
		if (str[0][i] == 32)
			++kongge;
		else if (str[0][i] >= 48 && str[0][i] <= 57)
			++shuzi;
		else if (str[0][i] >= 65 && str[0][i] <= 90)
			++daxie;
		else if (str[0][i] >= 97 && str[0][i] <= 122)
			++xiaoxie;
		else
			++qita;
	}

	for (int i = 0; i < str1; ++i)
	{
		if (str[1][i] == 32)
			++kongge;
		else if (str[1][i] >= 48 && str[1][i] <= 57)
			++shuzi;
		else if (str[1][i] >= 65 && str[1][i] <= 90)
			++daxie;
		else if (str[1][i] >= 97 && str[1][i] <= 122)
			++xiaoxie;
		else
			++qita;
	}

	for (int i = 0; i < str2; ++i)
	{
		if (str[2][i] == 32)
			++kongge;
		else if (str[2][i] >= 48 && str[2][i] <= 57)
			++shuzi;
		else if (str[2][i] >= 65 && str[2][i] <= 90)
			++daxie;
		else if (str[2][i] >= 97 && str[2][i] <= 122)
			++xiaoxie;
		else
			++qita;
	}

	cout << "大写 :" <<daxie <<endl;
	cout << "小写 :" << xiaoxie << endl;
	cout << "数字 :" << shuzi << endl;
	cout << "空格 :" << kongge << endl;
	cout << "其它 :" << qita << endl;

	return 0;
}