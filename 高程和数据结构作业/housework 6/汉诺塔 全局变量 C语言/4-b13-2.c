/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int i = 0;

void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1)
    {
        printf("%5d: %2d# %c-- >%c\n", ++i, n, src, dst);
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    printf("%5d: %2d# %c-- >%c\n", ++i, n, src, dst);
    hanoi(n - 1, tmp, src, dst);
    return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    char qishi, mubiao, zhongjian;
    int n=-1;
    printf("请输入汉诺塔的层数(1-16)\n");
    while (1)
    {
        scanf("%d", &n);
        if ((n <= 16 && n >= 1))
            break;
        printf("请输入汉诺塔的层数(1-16)\n");
    }
    printf("请输入起始柱(A-C)\n");
    scanf("%c", &qishi);
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        char a;
        while ((a = getchar()) != '\n');
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &qishi);
    }
    char a;
    while ((a = getchar()) != '\n');
    
    scanf("%c", &mubiao);
    while (!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')&&(mubiao!=qishi))
    {
         
        if (mubiao == qishi)
            printf("目标柱(%c)不能与起始柱(%c)相同", mubiao, qishi);
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &mubiao);
        char a;
        while ((a = getchar()) != '\n');
    }
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;
    printf("移动步骤为\n");
    hanoi(n, qishi, zhongjian, mubiao);
    return 0;
}
