#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x,w;
    double a;
    printf("请输入[1..99999]间的整数及显示宽度[6..10]\n");
    scanf("%lf %d %d",&a,&x, &w); //不考虑输入错误
    printf("01234567890123456789\n"); //标尺

    char fmt[16];
    sprintf(fmt, "%%.%%ddf*\n", x,w);
    printf(fmt, a);

    return 0;
}
