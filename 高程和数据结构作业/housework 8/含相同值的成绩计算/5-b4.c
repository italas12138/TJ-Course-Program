/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int chengji[1100] = { 0 },chengjibiao[101]={0};
	int a = 0, n = 0;
	printf("请输入成绩（最多1000个），以-1结束\n");
	while (1)
	{
		scanf("%d",&a);
		chengji[n] = a;
		if (a == -1)
			break;
		++chengjibiao[a];
		++n;
	}
	if (n == 0)
	{
		printf("无有效输入\n");
		return 0;
	}
	printf("输入的数组为:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", chengji[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	if(n%10!=0)
		printf("\n");
	printf("分数与人数的对应关系为:\n");
	for (int i = 100; i >= 0; --i)
		if (chengjibiao[i] > 0)
			printf("%d %d\n", i, chengjibiao[i]);

	return 0;
}