#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x,w;
    double a;
    printf("������[1..99999]�����������ʾ���[6..10]\n");
    scanf("%lf %d %d",&a,&x, &w); //�������������
    printf("01234567890123456789\n"); //���

    char fmt[16];
    sprintf(fmt, "%%.%%ddf*\n", x,w);
    printf(fmt, a);

    return 0;
}
