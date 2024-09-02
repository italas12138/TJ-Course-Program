/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int a_top=0, b_top=0, c_top=0;
int cishu = 0;
int a[10], b[10], c[10];

void printhannuota(char qishi, char mubiao,int n)
{
    ++cishu;
    if (qishi == 'A')
    {
        --a_top;
        if (mubiao == 'B')
        {
            b[b_top] = a[a_top];
            ++b_top;
        }
        else if (mubiao == 'C')
        {
            c[c_top] = a[a_top];
            ++c_top;
        }
    }

    else if (qishi == 'B')
    {
        --b_top;
        if (mubiao == 'A')
        {
            a[a_top] = b[b_top];
            ++a_top;
        }
        else if (mubiao == 'C')
        {
            c[c_top] = b[b_top];
            ++c_top;
        }
    }

    else
    {
        --c_top;
        if (mubiao == 'A')
        {
            a[a_top] = c[c_top];
            ++a_top;
        }
        else if (mubiao == 'B')
        {
            b[b_top] = c[c_top];
            ++b_top;
        } 
    }
    printf("第%4d 步(%2d): %c-->%c A:", cishu, n, qishi, mubiao);
    for (int i = 0; i < a_top; ++i)
        printf("%2d", a[i]);
    for (int i = a_top; i < 10; ++i)
        printf("  ");
    printf(" B:");
    for (int i = 0; i < b_top; ++i)
        printf("%2d", b[i]);
    for (int i = b_top; i < 10; ++i)
        printf("  ");
    printf(" C:");
    for (int i = 0; i < c_top; ++i)
        printf("%2d", c[i]);
    for (int i = c_top; i < 10; ++i)
        printf("  ");
    printf("\n");
}

void hannuota(char qishi, char zhongjian, char mubiao,int n)
{
    if (n == 1)
    {
        printhannuota(qishi, mubiao,n);
        return;
    }
    hannuota(qishi, mubiao, zhongjian, n - 1);
    printhannuota(qishi, mubiao,n);
    hannuota(zhongjian, qishi, mubiao, n - 1);
}

int main()
{
    char qishi,mubiao,zhongjian,fuzhu;
    int n;

    printf("请输入汉诺塔的层数(1-10)\n");
    scanf("%d", &n);
    while (!(n <= 10 && n >= 1))
    {
        while ((fuzhu = getchar()) != '\n');
        printf("请输入汉诺塔的层数(1-10)\n");
        scanf("%d", &n);
    }
    while ((fuzhu = getchar()) != '\n');

    printf("请输入起始柱(A-C)\n");
    scanf("%c", &qishi);
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        while ((fuzhu = getchar()) != '\n');
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &qishi);
    }
    while ((fuzhu = getchar()) != '\n');
    if (qishi <= 'c' && qishi >= 'a')
        qishi -= 32;

    printf("请输入目标柱(A-C)\n");
    scanf("%c", &mubiao);
    while (!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a') 
        ||mubiao == qishi||fabs(mubiao-qishi)==32)
    {
        while ((fuzhu = getchar()) != '\n');
        if (mubiao <= 'c' && mubiao >= 'a')
            mubiao -= 32;
        if (mubiao == qishi)
            printf("目标柱(%c)不能与起始柱(%c)相同\n", mubiao, qishi);
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &mubiao);
    }
   
    if (mubiao <= 'c' && mubiao >= 'a')
        mubiao -= 32;

    zhongjian = 'A' + 'B' + 'C' - mubiao - qishi;

    if (qishi == 'A')
    {
        a_top = n;
        for (int i = 0; i < n; ++i)
            a[i] = n - i;
    }
    else if (qishi == 'B')
    {
        b_top = n;
        for (int i = 0; i < n; ++i)
            b[i] = n - i;
    }
    else
    {
        c_top = n;
        for (int i = 0; i < n; ++i)
            c[i] = n - i;
    }

    printf("初始:                A:");
    for (int i = 0; i < a_top; ++i)
        printf("%2d", a[i]);
    for (int i = a_top; i < 10; ++i)
        printf("  ");
    printf(" B:");
    for (int i = 0; i < b_top; ++i)
        printf("%2d", b[i]);
    for (int i = b_top; i < 10; ++i)
        printf("  ");
    printf(" C:");
    for (int i = 0; i < c_top; ++i)
        printf("%2d", c[i]);
    for (int i = c_top; i < 10; ++i)
        printf("  ");
    printf("\n");

    hannuota(qishi, zhongjian, mubiao, n);

    return 0;
}
