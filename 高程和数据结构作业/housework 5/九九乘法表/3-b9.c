/* �ƿ� 2152118 ʷ���� */

#include <stdio.h>

int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		    printf("%dx%d=%-4d", j, i, i * j);
		printf("\n");
	}

	return 0;
}