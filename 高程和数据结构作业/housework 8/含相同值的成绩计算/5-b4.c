/* 2152118 ʷ���� �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int chengji[1100] = { 0 },chengjibiao[101]={0};
	int a = 0, n = 0;
	printf("������ɼ������1000��������-1����\n");
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
		printf("����Ч����\n");
		return 0;
	}
	printf("���������Ϊ:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", chengji[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	if(n%10!=0)
		printf("\n");
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	for (int i = 100; i >= 0; --i)
		if (chengjibiao[i] > 0)
			printf("%d %d\n", i, chengjibiao[i]);

	return 0;
}