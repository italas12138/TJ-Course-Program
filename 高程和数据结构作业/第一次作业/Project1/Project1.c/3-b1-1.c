/* 2152118 计科 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#define Pi 3.14159
#include <stdio.h>

int main()
{
	double r, h;
	printf("请输入半径和高度\n");
	scanf("%lf %lf",&r, &h);
	printf("圆周长     : ""%.2f\n", 2 * r * Pi);
	printf("圆面积     : ""%.2f\n", Pi * r * r);
	printf("圆球表面积 : ""%.2f\n", 4 * Pi * r * r);
	printf("圆球体积   : ""%.2f\n", 4 / 3.0 * Pi * r * r * r);
	printf("圆柱体积   : ""%.2f\n", Pi * r * r * h);

	return 0;
}