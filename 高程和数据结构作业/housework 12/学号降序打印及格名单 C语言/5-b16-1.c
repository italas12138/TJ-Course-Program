/* 计科 2152118 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char name[10][9],number[10][8];
	int score[10];

	for (int i = 1; i <= 10; ++i)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n",i);
		scanf("%s %s %d", &number[i - 1], &name[i - 1], &score[i - 1]);
	}

	printf("\n及格名单(学号降序) :\n");

	int paixu[10] = { 0 },geshu=0,change;
	for (int i = 1; i <= 10; ++i)
	{
		if (score[i - 1] >= 60)
			paixu[geshu++] = i;
	}

	for (int i = 0; i < geshu-1; ++i)
	{
		for(int j=0;j<geshu-(i+1); ++j)
			if (strcmp(number[paixu[j]], number[paixu[j+1]]) < 0)
			{
				change = paixu[j];
				paixu[j] = paixu[j + 1];
				paixu[j + 1] = change;
			}
	}

	for (int i = 0; i < geshu; ++i)
		printf("%s %s %d\n", name[paixu[i]-1], number[paixu[i]-1], score[paixu[i]-1]);

	return 0;
}