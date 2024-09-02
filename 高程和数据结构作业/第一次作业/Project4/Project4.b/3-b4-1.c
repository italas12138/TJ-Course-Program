/* 2152118 计科 史君宝 */

#define _CRT_SECURE_NO_WARNINGS
#define Pi 3.14159
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, jiao;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d %d %d",&a,&b,&jiao);
	double hu, s;
	hu = jiao/180.0 * Pi;
	s = 0.5 * a * b * sin(hu);;
	printf("三角形面积为 : ""%.3f\n",s );

	return 0;
}