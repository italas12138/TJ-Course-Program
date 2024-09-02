/* 2152118 史君宝 计科 */
/*2152095 龚宣 2053932 雷翔 2152180 文溪 2152472 司盛宇 2152069 马明扬*/

#include <stdio.h>

int countmine(char str[10][26])
{
	int number = 0;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 26; ++j)
			if (str[i][j] == '*')
				++number;
	if (number == 50)
		return 1;
	else
		return 0;
}

int findmine(char str[10][26])
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 26; ++j)
		{
			if (str[i][j] == '*')
				continue;
			int number = 0;
			for (int m = i - 1; m <= i + 1; ++m)
				for (int n = j - 1; n <= j + 1; ++n)
				{
					if (m >= 0 && m < 10 && n >= 0 && n < 26)
						if (str[m][n] == '*')
							++number;
				}
			if (str[i][j] != number + '0')
				return 0;
		}
	return 1;
}

int main()
{
	char str[10][26], fuzhu;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 26; ++j)
		{
			while ((fuzhu = getchar()) == ' ' || fuzhu == '\n');
			str[i][j] = fuzhu;
		}
	int checkone, checktwo;
	checkone = countmine(str);
	if (checkone == 0)
	{
		printf("错误1\n");
		return 0;
	}
	checktwo = findmine(str);
	if (checktwo == 0)
	{
		printf("错误2\n");
		return 0;
	}
	printf("正确\n");
	return 0;
}