/* 2152118 ʷ���� �ƿ� */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    char qishi, mubiao, zhongjian;
    int n=-1;
    printf("�����뺺ŵ���Ĳ���(1-16)\n");
    while (1)
    {
        scanf("%d", &n);
        if ((n <= 16 && n >= 1))
            break;
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
    }
    printf("��������ʼ��(A-C)\n");
    scanf("%c", &qishi);
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        char a;
        while ((a = getchar()) != '\n');
        printf("��������ʼ��(A-C)\n");
        scanf("%c", &qishi);
    }
    char a;
    while ((a = getchar()) != '\n');
    
    scanf("%c", &mubiao);
    while (!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')&&(mubiao!=qishi))
    {
         
        if (mubiao == qishi)
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ", mubiao, qishi);
        printf("������Ŀ����(A-C)\n");
        scanf("%c", &mubiao);
        char a;
        while ((a = getchar()) != '\n');
    }
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;
    printf("�ƶ�����Ϊ\n");
    hanoi(n, qishi, zhongjian, mubiao);
    return 0;
}
