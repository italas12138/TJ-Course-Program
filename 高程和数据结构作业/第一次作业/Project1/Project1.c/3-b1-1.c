/* 2152118 �ƿ� ʷ���� */

#define _CRT_SECURE_NO_WARNINGS
#define Pi 3.14159
#include <stdio.h>

int main()
{
	double r, h;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf",&r, &h);
	printf("Բ�ܳ�     : ""%.2f\n", 2 * r * Pi);
	printf("Բ���     : ""%.2f\n", Pi * r * r);
	printf("Բ������ : ""%.2f\n", 4 * Pi * r * r);
	printf("Բ�����   : ""%.2f\n", 4 / 3.0 * Pi * r * r * r);
	printf("Բ�����   : ""%.2f\n", Pi * r * r * h);

	return 0;
}