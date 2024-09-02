/* 计科 2152118 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char name[10][9], number[10][8];
	int score[10];

	for (int i = 1; i <= 10; ++i)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i);
		scanf("%s %s %d", &number[i - 1], &name[i - 1], &score[i - 1]);
	}

	printf("\n全部学生(成绩降序):\n");

	int paixu[10] = { 0 }, change;
	for (int i = 1; i <= 10; ++i)
	{
		paixu[i-1] = i;
	}

	for (int i = 0; i < 10-1; ++i)
	{
		for (int j = 0; j < 10 - (i + 1); ++j)
			if (score[paixu[j]-1]-score[paixu[j + 1]-1] < 0)
			{
				change = paixu[j];
				paixu[j] = paixu[j + 1];
				paixu[j + 1] = change;
			}
	}

	for (int i = 0; i <10; ++i)
		printf("%s %s %d\n", name[paixu[i] - 1], number[paixu[i] - 1], score[paixu[i] - 1]);

	return 0;
}