/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;

int a_top = 0, b_top = 0, c_top = 0;
int cishu = 0;
int a[10], b[10], c[10];
int speed;
int output;


void wait()               //���õȴ���ʽ�ĺ���
{
    if (speed == 0)      //�س�����>��һ��
    {
        char a;
        while ((a = getchar()) != '\n');
    }
    if (speed==1)       //�ٶ�����
    {
        Sleep(1000);
        return;
    }
    if (speed == 2)
    {
        Sleep(500);
        return;
    }
    if (speed == 3)
    {
        Sleep(200);
        return;
    }
    if (speed == 4)
    {
        Sleep(100);
        return;
    }
    if (speed == 5)      //�ٶ����
    {
        Sleep(50);
        return;
    }
}

void print()            //��ӡ��ʾ���麯��
{
    cout << "  A:";
    for (int i = 0; i < a_top; ++i)
        cout << setw(2) << a[i];
    for (int i = a_top; i < 10; ++i)
        cout << "  ";
    cout << " B:";
    for (int i = 0; i < b_top; ++i)
        cout << setw(2) << b[i];
    for (int i = b_top; i < 10; ++i)
        cout << "  ";
    cout << " C:";
    for (int i = 0; i < c_top; ++i)
        cout << setw(2) << c[i];
    for (int i = c_top; i < 10; ++i)
        cout << "  ";
}

void printpicture(char qishi)        //��ӡ��ʼ�ĺ�ŵ��ͼ
{
    cct_gotoxy(0, 12);
    cout << "         =========================" << endl;
    cout << setw(12) << "A" << setw(10) << "B" << setw(10) << "C" << endl;

    cct_gotoxy(0, 12 - a_top - b_top - c_top);
    if (qishi == 'A')
    {
        for (int i = a_top - 1; i >= 0; --i)
            cout << setw(12) << a[i] << endl;
        cct_gotoxy(12, 12 - a_top - b_top - c_top);
    }
    else if (qishi == 'B')
    {
        for (int i = b_top - 1; i >= 0; --i)
            cout << setw(22) << b[i] << endl;
        cct_gotoxy(22, 12 - a_top - b_top - c_top);
    }
    else
    {
        for (int i = c_top - 1; i >= 0; --i)
            cout << setw(32) << c[i] << endl;
        cct_gotoxy(32, 12 - a_top - b_top - c_top);
    }
}

void printhannuota(char qishi, char mubiao, int n)          //��ӡ�����е�Բ���ƶ�Ч��
{
    ++cishu;

    wait();

    cct_gotoxy(0, 17);
    cout << "��" << setw(4) << cishu << "��(" << n << "# " << qishi << "--> " << mubiao << ")";
    if (output == 1)
        print();
   
    if (qishi == 'A')
    {
        --a_top;
       
        
        if (mubiao == 'B')
        {
            b[b_top] = a[a_top];
           
            cct_gotoxy(11, 11 - a_top);
            cout << " ";
            cct_gotoxy(21, 11 - b_top);
            cout << b[b_top];

            ++b_top;
        }
        else if (mubiao == 'C')
        {
            c[c_top] = a[a_top]; 

            cct_gotoxy(11, 11 - a_top);
            cout << " ";
            cct_gotoxy(31, 11 - c_top);
            cout << c[c_top];

            ++c_top;
        }

    }

    else if (qishi == 'B')
    {
        --b_top;
       
        if (mubiao == 'A')
        {
            a[a_top] = b[b_top];
           
            cct_gotoxy(21, 11 - b_top);
            cout << " ";
            cct_gotoxy(11, 11 - a_top);
            cout << a[a_top];

            ++a_top;
        }
        else if (mubiao == 'C')
        {
            c[c_top] = b[b_top];

            cct_gotoxy(21, 11 - b_top);
            cout << " ";
            cct_gotoxy(31, 11 - c_top);
            cout << c[c_top];

            ++c_top;
        }
    }

    else
    {
        --c_top;
      
        if (mubiao == 'A')
        {
            a[a_top] = c[c_top];        

            cct_gotoxy(31, 11 - c_top);
            cout << " ";
            cct_gotoxy(11, 11 - a_top);
            cout << a[a_top];

            ++a_top;
        }
        else if (mubiao == 'B')
        {
            b[b_top] = c[c_top];
          
            cct_gotoxy(31, 11 - c_top);
            cout << " ";
            cct_gotoxy(21, 11 - b_top);
            cout << b[b_top];

            ++b_top;
        }
    }
    if (output == 1)
    {
        cct_gotoxy(21, 17);
        print();
    }
}

void hannuota(char qishi, char zhongjian, char mubiao, int n)    //��ŵ���߼����ݹ麯��
{
    if (n == 1)
    {
        printhannuota(qishi, mubiao, n);
        return;
    }
    hannuota(qishi, mubiao, zhongjian, n - 1);
    printhannuota(qishi, mubiao, n);
    hannuota(zhongjian, qishi, mubiao, n - 1);
}

int main()
{
    char qishi, mubiao, zhongjian;
    int n;

    //���뺺ŵ����������������
    cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
    cin >> n;
    while (!(n <= 10 && n >= 1))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
    }
    cin.clear();
    cin.ignore(65535, '\n');

    //������ʼ������������
    cout << "��������ʼ��(A-C)" << endl;
    cin >> qishi;
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "��������ʼ��(A-C)" << endl;
        cin >> qishi;
    }
    cin.clear();
    cin.ignore(65535, '\n');
    if (qishi <= 'c' && qishi >= 'a')
        qishi -= 32;

    //����Ŀ��������������
    cout << "������Ŀ����(A-C)" << endl;
    cin >> mubiao;
    while (!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')
        || mubiao == qishi || fabs(mubiao - qishi) == 32)
    {
        cin.clear();
        cin.ignore(65535, '\n');
        if (mubiao <= 'c' && mubiao >= 'a')
            mubiao -= 32;
        if (mubiao == qishi)
            cout << "Ŀ����" << mubiao << "��������ʼ��" << qishi << "��ͬ" << endl;
        cout << "������Ŀ����(A-C)" << endl;;
        cin >> mubiao;
    }

    if (mubiao <= 'c' && mubiao >= 'a')
        mubiao -= 32;

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

    //�����ƶ��ٶ�0-5����������
    cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
    cin >> speed;
    while (!(speed <= 5 && speed >= 0))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
    }
    cin.clear();
    cin.ignore(65535, '\n');


    //�����Ƿ���ʾ0-1����������
    cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
    cin >> output;
    while (!(output <= 1 && output >= 0))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> output;
    }
    cin.clear();
    cin.ignore(65535, '\n');

    //����
    cct_cls();

    //��ʾ�ĳ�ʼ��ӡ
    if (output == 1)
    {
        cout << "�� " << qishi << " �ƶ��� " << mubiao << "���� " << n
             << " �㣬��ʱ����Ϊ " << speed << "����ʾ�ڲ�����ֵ" << endl;
        cct_gotoxy(0, 17);
        cout << "��ʼ:             ";
        print();

        wait();
        printpicture(qishi);
    }

    //����ʾ�ĳ�ʼ��ӡ
    if (output == 0)
    {
        cout << "�� " << qishi << " �ƶ��� " << mubiao << "���� " << n
             << " �㣬��ʱ����Ϊ " << speed << "������ʾ�ڲ�����ֵ" << endl;
        
        printpicture(qishi);
       
    }

    hannuota(qishi, zhongjian, mubiao, n);

    cct_gotoxy(0,20);

    system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
    return 0;
}
