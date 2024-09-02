/* 2152118 Ê·¾ý±¦ ¼Æ¿Æ */

#include <iostream>
#include <ctime> 
using namespace std;

void randmine(char str[10][26])
{
	srand((unsigned)time(NULL));
	int s1, s2,i=0;
	while (i < 50)
	{
		s1 = rand() % 10;
		s2 = rand() % 26;
		if (str[s1][s2] != '*')
		{
			str[s1][s2] = '*';
			++i;
		}
	}
}

void findaround(char str[10][26])
{
	for(int i=0;i<10;++i)
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
			str[i][j] = number + '0';
		}
}
int main()
{
	char str[10][26] = {};

	randmine(str);

	findaround(str);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 26; ++j)
			cout << str[i][j] << " ";
		cout << endl;
	}

	return 0;
}
