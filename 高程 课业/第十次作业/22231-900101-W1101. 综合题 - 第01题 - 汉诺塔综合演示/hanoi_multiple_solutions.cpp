/* �ƿ� 2152118 ʷ���� */

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

static int a_top = 0, b_top = 0, c_top = 0;
static int cishu = 0;
static int a[10], b[10], c[10];
static int speed=4;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void menu();

//���س����ز˵��ĺ���
void return_menu(int choice)
{
    char m;
    if (choice == 1 || choice == 2||choice==3)
        cout << endl << endl;
    else
        cct_gotoxy(0, 35);
    cout << "���س�������";
    while ((m = getchar()) != '\n');
    a_top = b_top = c_top = cishu = 0;
    speed = 4;
    for (int i = 0; i < 10; ++i)
        a[i] = b[i] = c[i] = 0;
    cct_cls();
    menu();
}

//��ʱ����
void wait()               //���õȴ���ʽ�ĺ���
{
    char a;
    if (speed == 0)      //�س�����>��һ�� 
        while ((a = getchar()) != '\n');
    if (speed == 1)       //�ٶ�����   
        Sleep(1000);  
    if (speed == 2)  
        Sleep(500);      
    if (speed == 3)    
        Sleep(200);   
    if (speed == 4)
        Sleep(50);    
    if (speed == 5)//�ٶ���� 
        Sleep(10);       
    return;
}

//ʵ����ͼ�Ͻ�AԲ���Ƶ�B��
void moveAB()
{
    int x, y;
    for (y = 14 - a_top; y >= 1; --y) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(12 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(12 - a[a_top], y, ' ', 0, 0, 2 * a[a_top]);//��ɫ
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(12, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(13, y, ' ', 0, 0, 2 * a[a_top]);//��ɫ
        }
    } //end of for

    for (x = 12 - a[a_top]; x <= 44 - a[a_top]; x++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(x, 1, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x < 44 - a[a_top]) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(x, 1, ' ', 0, 0, 2 * a[a_top] + 1);//��ɫ
        }
    } //end of for


    for (y = 1; y <= 15 - b_top; y++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(44 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - b_top) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(44 - a[a_top], y, ' ', 0, 0, a[a_top]);//��ɫ
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(44, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(45, y, ' ', 0, 0, a[a_top]);//��ɫ
        }
    } //end of for
}

//ʵ����ͼ�Ͻ�AԲ���Ƶ�C��
void moveAC()
{
    int x, y;
    for (y = 14 - a_top; y >= 1; --y) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(12 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(12 - a[a_top], y, ' ', 0, 0, 2 * a[a_top]);//��ɫ
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(12, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(13, y, ' ', 0, 0, 2 * a[a_top]);//��ɫ
        }
    } //end of for

    for (x = 12 - a[a_top]; x <= 76 - a[a_top]; x++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(x, 1, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x < 76 - a[a_top]) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(x, 1, ' ', 0, 0, 2 * a[a_top] + 1);//��ɫ
        }
    } //end of for

    for (y = 1; y <= 15 - c_top; y++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(76 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - c_top) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(76 - a[a_top], y, ' ', 0, 0, a[a_top]);//��ɫ
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(76, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(77, y, ' ', 0, 0, a[a_top]);//��ɫ
        }
    } //end of for
}

//ʵ����ͼ�Ͻ�BԲ���Ƶ�A��
void moveBA()
{
    int x, y;
    for (y = 14 - b_top; y >= 1; --y) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(44 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(44 - b[b_top], y, ' ', 0, 0, 2 * b[b_top]);//��ɫ
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(44, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(45, y, ' ', 0, 0, 2 * b[b_top]);//��ɫ
        }
    } //end of for

    for (x = 44 - b[b_top]; x >= 12 - b[b_top]; --x) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(x, 1, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x > 12 - b[b_top]) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(x, 1, ' ', 0, 0, 2 * b[b_top] + 1);//��ɫ
        }
    } //end of for


    for (y = 1; y <= 15 - a_top; y++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(12 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - a_top) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(12 - b[b_top], y, ' ', 0, 0, b[b_top]);//��ɫ
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(12, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(13, y, ' ', 0, 0, b[b_top]);//��ɫ
        }
    } //end of for
}

//ʵ����ͼ�Ͻ�BԲ���Ƶ�C��
void moveBC()
{
    int x, y;
    for (y = 14 - b_top; y >= 1; --y) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(44 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(44 - b[b_top], y, ' ', 0, 0, 2 * b[b_top]);//��ɫ
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(44, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(45, y, ' ', 0, 0, 2 * b[b_top]);//��ɫ
        }
    } //end of for

    for (x = 44 - b[b_top]; x <= 76 - b[b_top]; ++x) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(x, 1, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x < 76 - b[b_top]) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(x, 1, ' ', 0, 0, 2 * b[b_top] + 1);//��ɫ
        }
    } //end of for


    for (y = 1; y <= 15 - c_top; y++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(76 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - c_top) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(76 - b[b_top], y, ' ', 0, 0, b[b_top]);//��ɫ
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(76, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(77, y, ' ', 0, 0, b[b_top]);//��ɫ
        }
    } //end of for
}

//ʵ����ͼ�Ͻ�CԲ���Ƶ�A��
void moveCA()
{
    int x, y;
    for (y = 14 - c_top; y >= 1; --y) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(76 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(76 - c[c_top], y, ' ', 0, 0, 2 * c[c_top]);//��ɫ
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(76, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(77, y, ' ', 0, 0, 2 * c[c_top]);//��ɫ
        }
    } //end of for

    for (x = 76 - c[c_top]; x >= 12 - c[c_top]; --x) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(x, 1, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x > 12 - c[c_top]) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(x, 1, ' ', 0, 0, 2 * c[c_top] + 1);//��ɫ
        }
    } //end of for


    for (y = 1; y <= 15 - a_top; y++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(12 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - a_top) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(12 - c[c_top], y, ' ', 0, 0, c[c_top]);//��ɫ
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(12, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(13, y, ' ', 0, 0, c[c_top]);//��ɫ
        }
    } //end of for
}

//ʵ����ͼ�Ͻ�CԲ���Ƶ�B��
void moveCB()
{
    int x, y;
    for (y = 14 - c_top; y >= 1; --y) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(76 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(76 - c[c_top], y, ' ', 0, 0, 2 * c[c_top]);//��ɫ
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(76, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(77, y, ' ', 0, 0, 2 * c[c_top]);//��ɫ
        }
    } //end of for

    for (x = 76 - c[c_top]; x >= 44 - c[c_top]; --x) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(x, 1, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x > 44 - c[c_top]) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(x, 1, ' ', 0, 0, 2 * c[c_top] + 1);//��ɫ
        }
    } //end of for


    for (y = 1; y <= 15 - b_top; y++) {
        /* ������(x,2)λ�ô�������ӡ10���ַ� */
        cct_showch(44 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - b_top) {
            /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
            cct_showch(44 - c[c_top], y, ' ', 0, 0, c[c_top]);//��ɫ
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//��ɫ
            else
                cct_showch(44, y, ' ', 0, 0, 1);//��ɫ
            cct_showch(45, y, ' ', 0, 0, c[c_top]);//��ɫ
        }
    } //end of for
}

//������ŵ��������
void photo_hanoi()
{
    //������ĵ���
    cct_showch(1, 15, ' ', 14, 0, 23);
    cct_showch(33, 15, ' ', 14, 0, 23);
    cct_showch(65, 15, ' ', 14, 0, 23);

    //�����������
    for (int i = 15; i >= 3; --i)
    {
        Sleep(100);
        cct_showch(12, i, ' ', 14, 0, 1);
        cct_showch(44, i, ' ', 14, 0, 1);
        cct_showch(76, i, ' ', 14, 0, 1);
    }
    cct_gotoxy(0, 20);   //��굽��0,20����
    cct_setcolor(0, 7);  //��ɫ���س�ʼֵ
}

//������ŵ����Բ��
void photo_circle(char qishi)
{
    //�ж���ʼ����ABC��Ȼ���Ӧ�Ļ�Բ��
    if (qishi == 'A')
        for (int i = 0; i < a_top; ++i)
        {
            Sleep(1000);
            for (int j = 12 - a_top + i; j <= 12 + a_top - i; ++j)                       
                cct_showch(j, 14 - i, ' ', 14 - a[i], 0, 1);        
        }
    if (qishi == 'B')
        for (int i = 0; i < b_top; ++i)
        {
            Sleep(1000);
            for (int j = 44 - b_top + i; j <= 44 + b_top - i; ++j)                        
                cct_showch(j, 14 - i, ' ', 14 - b[i], 0, 1);        
        }
    if (qishi == 'C')
        for (int i = 0; i < c_top; ++i)
        {
            Sleep(1000);
            for (int j = 76 - c_top + i; j <= 76 + c_top - i; ++j)                   
                cct_showch(j, 14 - i, ' ', 14 - c[i], 0, 1);           
        }
    cct_setcolor(0, 7);    //��ɫ���س�ʼֵ
}

//�ò�������ʵ��Բ�̵��ƶ�����ʵ�ֶ�Ӧ����ķ���
void move_circle(int choice,char qishi,char zhongjian,char mubiao) 
{
    //��ʼ����A��Ŀ������B����ͨ��moveAB����ʵ���ƶ�Բ��
    if (qishi == 'A')
    {
        if (mubiao == 'B')            
            moveAB();
        if (mubiao == 'C')                 
            moveAC();       
    }
    if (qishi == 'B')
    {
        if (mubiao == 'A')        
            moveBA();       
        if (mubiao == 'C')       
            moveBC();       
    }
    if (qishi == 'C')
    {
        if (mubiao == 'A')
            moveCA();
        if (mubiao == 'B')
            moveCB();       
    }
}

//��ӡ���������
void print_heng(int n,char qishi,char zhongjina,char mubiao,int choice)
{
    if(choice==3)
        printf("��%4d ��(%2d#: %c-->%c)", ++cishu, n, qishi, mubiao);
    else
        cout << "��" << setw(4) << ++cishu << "��(" << n << "# " << qishi << "--> " << mubiao << ")";

    cout << " A:";
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

//��ӳ�ƶ������е�����仯�����ڹ����а���choice==9������ж��ƶ��Ƿ�����ȷ��
void move(char qishi, char zhongjian, char mubiao, int choice, int X)
{
    if (qishi == 'A')
    {
        if (mubiao == 'B')
        {
            //������ͨ�����������ж�choice==9ʱ���ƶ��Ƿ�����ȷ��
            if (choice == 9 && (a[a_top - 1] > b[b_top -1] && b[b_top - 1] != 0))
            {
                cct_gotoxy(0,31);
                cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && a_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "Դ��Ϊ��!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }

            //������ģ���������ݱ仯�Ĺ��̣���choice==4��8��9ʱ�������ڴ�ӡ�ĺ�ŵ����
            //���Ԫ�صı仯
            --a_top;
            b[b_top] = a[a_top];
            if (choice == 4 || choice == 8 || choice == 9)
            {
                cct_gotoxy(11, 11 - a_top + X);
                cout << " ";
                cct_gotoxy(21, 11 - b_top + X);
                cout << b[b_top];
            }
            ++b_top;
            if (choice == 9)
            {
                moveAB();
                cct_setcolor(0, 7);
                cct_gotoxy(0, 28);
                print_heng(b[b_top - 1], qishi, zhongjian, mubiao, 9);
            }
        }
        else if (mubiao == 'C')
        {
            if (choice == 9 && (a[a_top - 1] > c[c_top ] && c[c_top-1]!=0))
            {
                cct_gotoxy(0,31);
                cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && a_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "Դ��Ϊ��!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";

                return;
            }
          
            --a_top;
            c[c_top] = a[a_top];
            if (choice == 4 || choice == 8 || choice == 9)
            {
                cct_gotoxy(11, 11 - a_top + X);
                cout << " ";
                cct_gotoxy(31, 11 - c_top + X);
                cout << c[c_top];
            }
            ++c_top;
            if (choice == 9)
            {
                moveAC();
                cct_setcolor(0, 7);
                cct_gotoxy(0, 28);
                print_heng(c[c_top - 1], qishi, zhongjian, mubiao, 9);
            }
        }
    }

    else if (qishi == 'B')
    {
        if (mubiao == 'A')
        {
            if (choice == 9 && (b[b_top - 1] > a[a_top - 1] && a[a_top - 1] != 0))
            {
                cct_gotoxy(0,31);
                cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && b_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "Դ��Ϊ��!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            --b_top;
            a[a_top] = b[b_top];

            if (choice == 4 || choice == 8 || choice == 9)
            {
                cct_gotoxy(21, 11 - b_top + X);
                cout << " ";
                cct_gotoxy(11, 11 - a_top + X);
                cout << a[a_top];
            }

            ++a_top;
            if (choice == 9)
            {
                moveBA();
                cct_setcolor(0, 7);
                cct_gotoxy(0, 28);
                print_heng(a[a_top - 1], qishi, zhongjian, mubiao, 9);
            }
        }
        else if (mubiao == 'C')
        {
            if (choice == 9 && (b[b_top - 1] > c[c_top - 1] && c[c_top - 1] != 0))
            {
                cct_gotoxy(0,31);
                cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && b_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "Դ��Ϊ��!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
           
            --b_top;
            c[c_top] = b[b_top];

            if (choice == 4 || choice == 8 || choice == 9)
            {
                cct_gotoxy(21, 11 - b_top + X);
                cout << " ";
                cct_gotoxy(31, 11 - c_top + X);
                cout << c[c_top];
            }

            ++c_top;
            if (choice == 9)
            {
                moveBC();
                cct_setcolor(0, 7);
                cct_gotoxy(0, 28);
                print_heng(c[c_top - 1], qishi, zhongjian, mubiao, 9);
            }
        }
    }

    else
    {
        if (mubiao == 'A')
        {
            if (choice == 9 && (c[c_top - 1] > a[a_top - 1] && a[a_top - 1] != 0))
            {
                cct_gotoxy(0, 31);
                cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if(choice==9&&c_top==0)
            {
                cct_gotoxy(0, 31);
                cout << "Դ��Ϊ��!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            --c_top;

            a[a_top] = c[c_top];

            if (choice == 4 || choice == 8 || choice == 9)
            {
                cct_gotoxy(31, 11 - c_top + X);
                cout << " ";
                cct_gotoxy(11, 11 - a_top + X);
                cout << a[a_top];
            }

            ++a_top;
            if (choice == 9)
            {
                moveCA();
                cct_setcolor(0, 7);
                cct_gotoxy(0, 28);
                print_heng(a[a_top - 1], qishi, zhongjian, mubiao, 9);
            }
        }
        else if (mubiao == 'B')
        {
            if (choice == 9 && (c[c_top - 1] > b[b_top - 1] && b[b_top - 1] != 0))
            {
                cct_gotoxy(0, 31);
                cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && c_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "Դ��Ϊ��!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
        
            --c_top;

            b[b_top] = c[c_top];

            if (choice == 4 || choice == 8 || choice == 9)
            {
                cct_gotoxy(31, 11 - c_top + X);
                cout << " ";
                cct_gotoxy(21, 11 - b_top + X);
                cout << b[b_top];
            }

            ++b_top;
            if (choice == 9)
            {

                moveCB();
                cct_setcolor(0, 7);
                cct_gotoxy(0, 28);
                print_heng(b[b_top - 1], qishi, zhongjian, mubiao, 9);
            }
        }
    }
}

//��ӡ���������
void print_zong(char qishi,int X)
{
    cct_gotoxy(0, 12+X);
    cout << "         =========================" << endl;
    cout << setw(12) << "A" << setw(10) << "B" << setw(10) << "C" << endl;

    cct_gotoxy(0, 12 - a_top - b_top - c_top+X);
    if (qishi == 'A')
    {
        for (int i = a_top - 1; i >= 0; --i)
            cout << setw(12) << a[i] << endl;
        cct_gotoxy(12, 12 - a_top - b_top - c_top + X);
    }
    else if (qishi == 'B')
    {
        for (int i = b_top - 1; i >= 0; --i)
            cout << setw(22) << b[i] << endl;
        cct_gotoxy(22, 12 - a_top - b_top - c_top + X);
    }
    else
    {
        for (int i = c_top - 1; i >= 0; --i)
            cout << setw(32) << c[i] << endl;
        cct_gotoxy(32, 12 - a_top - b_top - c_top + X);
    }
}

//���뺯������(���ݲ�ͬ��choice���ò�ͬ������)
void input(int &n,char &qishi,char &mubiao,int &choice)
{
    cout << endl;
    //���뺺ŵ����������������
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65535, '\n');
        if (n <= 10 && n >= 1)
            break;
    }

    //������ʼ������������
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> qishi;
        cin.clear();
        cin.ignore(65535, '\n');
        if (qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a')
            break;
    }
    if (qishi <= 'c' && qishi >= 'a')
        qishi -= 32;

    //����Ŀ��������������
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> mubiao;
        cin.clear();
        cin.ignore(65535, '\n');
        if ((mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')
            && mubiao != qishi && fabs(mubiao - qishi) != 32)
            break;
    }
    if (mubiao <= 'c' && mubiao >= 'a')
        mubiao -= 32;

    if (choice == 4 || choice == 8)
    {
        //�����ƶ��ٶ�0-5����������
        while (1)
        {
            cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
            cin >> speed;
            cin.clear();
            cin.ignore(65535, '\n');
            if (speed <= 5 && speed >= 0)
                break;
        }
    }
    return;
}

//�����ʽ�Ļ���(����choice�Ĳ�ͬ���ò�ͬ�����)
void output(int choice,int n, char src, char tmp, char dst)
{
    if (choice == 1)
        cout << n << "# " << src << "---->" << dst << endl;

    if(choice==2)
        cout << "��"<<setw(5) << setiosflags(ios::right) << ++cishu << " ��(" << setw(2)
             << setiosflags(ios::right) << n << "#: " << src << "-- >" << dst <<")"<<endl;

    if (choice == 3)
    {
        move(src,tmp,dst,choice,0);
        print_heng(n, src, tmp, dst,choice);
    }

    if (choice == 4)
    {
        wait();
        move(src, tmp, dst,choice,0);
        cct_gotoxy(0, 20);
        print_heng(n,src, tmp, dst, choice);
       
    }

    if (choice == 7)
    {
        move(src, tmp, dst, choice, 15);
        move_circle(choice, src, tmp, dst);
        cct_setcolor(0, 7);
        cct_gotoxy(0, 30);
    }

    if (choice == 8)
    {
        if (speed == 0)
            wait();
        move(src, tmp, dst, choice, 15);
        cct_gotoxy(0, 30);
        print_heng(n, src, tmp, dst, choice);
        move_circle(choice, src, tmp, dst);
        cct_setcolor(0, 7);
    }    
}

//choice==9��ʱ�����������Ϸ����
void cinplay(char qishi,char zhongjian,char mubiao,int n)
{
    char one, two;
    while (1)
    {
        cct_gotoxy(60, 30);
        cin >> one;
        if (one == 'Q'||one=='q')
        {
            cct_gotoxy(0, 31);
            cout << "��Ϸ��ֹ!!!!!";
            Sleep(1000);
            return;
        }
        cin >> two;
        cin.clear();
        cin.ignore(65535, '\n');
        if (((one >= 'A' && one <= 'C') || (one - 32 >= 'A' && one - 32 <= 'C')) && 
            ((two >= 'A' && two <= 'C') || (two - 32 >= 'A' && two - 32 <= 'C')))      
            if (!(one - two == 0 || fabs(one - two) == 32))
                move(one, ' ', two, 9, 15);
        
            cct_gotoxy(60, 30);
            cout << "             "<<endl<<"          ";
            if ((mubiao == 'A'&&a_top==n)|| (mubiao == 'B' && b_top == n)
                || (mubiao == 'C' && c_top == n))
            {
                cct_gotoxy(0, 31);
                cout << "��Ϸ����!!!!!";
                Sleep(1000);
                return;
            }
    }
}

//��ŵ���ĵݹ麯��
void hanoi(int n, char src, char tmp, char dst, int choice)
{
    //src ��ʼ      tmp �м�        dst Ŀ��
    if (n == 1)
    {
        output(choice, n, src, tmp, dst);
        return;
    }
    hanoi(n - 1, src, dst, tmp, choice);
    if (choice == 7)
        return;
    output(choice, n, src, tmp, dst);
    hanoi(n - 1, tmp, src, dst, choice);
    return;
}

//ȷ���м�������ͨ�����ò��������м���
void makesurerod(int n,char qishi,char mubiao,char &zhongjian)
{
    zhongjian = 'A' + 'B' + 'C' - mubiao - qishi;

    //ȷ����ʼ�����ĸ�������Ϊ���Ӧ�����鸳ֵ
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
}

//��ɲ�ͬ��choiceֵ�����ò�ͬ�����Ĺ���
void choicenum(int choice)
{
    if (choice == 0)
        return;
    if (choice == 5)
    {
        cct_cls();
        photo_hanoi();
    }
    else
    {
        int n;
        char qishi, mubiao, zhongjian;
        input(n, qishi, mubiao, choice);
        makesurerod(n, qishi, mubiao, zhongjian);
      
        if (choice > 4)
        {
            cct_cls();
            cout << "�� " << qishi << "�ƶ��� " << mubiao << "���� " << n << " ��";
            if (choice == 8)
                cout << "����ʱ����Ϊ " << speed;
            photo_hanoi();
            photo_circle(qishi);
        }
        if (choice == 4)
        {
            cct_cls();
            print_zong(qishi, 0);
        }
        if(choice==8)
            print_zong(qishi, 15);

        if (choice == 6)       
            cct_gotoxy(0, 15);       

        if (choice == 9)
        {           
            print_zong(qishi, 15);
            cct_gotoxy(0, 30);
            cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
            cinplay(qishi,' ', mubiao, n);
        }
        else
            hanoi(n, qishi, zhongjian, mubiao, choice);
    }
    return_menu(choice);
    return;
}


