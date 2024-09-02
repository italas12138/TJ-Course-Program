/* 2152118 ʷ���� �ƿ� */
/*2152095 ���� 2053932 ���� 2152180 ��Ϫ 2152472 ˾ʢ�� 2152069 ������*/

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
		printf("����1\n");
		return 0;
	}
	checktwo = findmine(str);
	if (checktwo == 0)
	{
		printf("����2\n");
		return 0;
	}
	printf("��ȷ\n");
	return 0;
}