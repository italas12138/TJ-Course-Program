/* 2152118 �ƿ� ʷ���� */

#define _CRT_SECURE_NO_WARNINGS
#define Pi 3.14159
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, jiao;
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	scanf("%d %d %d",&a,&b,&jiao);
	double hu, s;
	hu = jiao/180.0 * Pi;
	s = 0.5 * a * b * sin(hu);;
	printf("���������Ϊ : ""%.3f\n",s );

	return 0;
}