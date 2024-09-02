/* 2152118 史君宝 计科 */
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


void wait()               //设置等待方式的函数
{
    if (speed == 0)      //回车——>下一步
    {
        char a;
        while ((a = getchar()) != '\n');
    }
    if (speed==1)       //速度最慢
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
    if (speed == 5)      //速度最快
    {
        Sleep(50);
        return;
    }
}

void print()            //打印显示数组函数
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

void printpicture(char qishi)        //打印初始的汉诺塔图
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

void printhannuota(char qishi, char mubiao, int n)          //打印过程中的圆盘移动效果
{
    ++cishu;

    wait();

    cct_gotoxy(0, 17);
    cout << "第" << setw(4) << cishu << "步(" << n << "# " << qishi << "--> " << mubiao << ")";
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

void hannuota(char qishi, char zhongjian, char mubiao, int n)    //汉诺塔逻辑，递归函数
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

    //输入汉诺塔层数，并错误处理
    cout << "请输入汉诺塔的层数(1-10)" << endl;
    cin >> n;
    while (!(n <= 10 && n >= 1))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
    }
    cin.clear();
    cin.ignore(65535, '\n');

    //输入起始柱，并错误处理
    cout << "请输入起始柱(A-C)" << endl;
    cin >> qishi;
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "请输入起始柱(A-C)" << endl;
        cin >> qishi;
    }
    cin.clear();
    cin.ignore(65535, '\n');
    if (qishi <= 'c' && qishi >= 'a')
        qishi -= 32;

    //输入目标柱，并错误处理
    cout << "请输入目标柱(A-C)" << endl;
    cin >> mubiao;
    while (!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')
        || mubiao == qishi || fabs(mubiao - qishi) == 32)
    {
        cin.clear();
        cin.ignore(65535, '\n');
        if (mubiao <= 'c' && mubiao >= 'a')
            mubiao -= 32;
        if (mubiao == qishi)
            cout << "目标柱" << mubiao << "不能与起始柱" << qishi << "相同" << endl;
        cout << "请输入目标柱(A-C)" << endl;;
        cin >> mubiao;
    }

    if (mubiao <= 'c' && mubiao >= 'a')
        mubiao -= 32;

    zhongjian = 'A' + 'B' + 'C' - mubiao - qishi;

    //确定起始柱是哪个柱，并为相对应的数组赋值
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

    //输入移动速度0-5，并错误处理
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> speed;
    while (!(speed <= 5 && speed >= 0))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> speed;
    }
    cin.clear();
    cin.ignore(65535, '\n');


    //输入是否显示0-1，并错误处理
    cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    cin >> output;
    while (!(output <= 1 && output >= 0))
    {
        cin.clear();
        cin.ignore(65535, '\n');
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> output;
    }
    cin.clear();
    cin.ignore(65535, '\n');

    //清屏
    cct_cls();

    //显示的初始打印
    if (output == 1)
    {
        cout << "从 " << qishi << " 移动到 " << mubiao << "，共 " << n
             << " 层，延时设置为 " << speed << "，显示内部数组值" << endl;
        cct_gotoxy(0, 17);
        cout << "初始:             ";
        print();

        wait();
        printpicture(qishi);
    }

    //不显示的初始打印
    if (output == 0)
    {
        cout << "从 " << qishi << " 移动到 " << mubiao << "，共 " << n
             << " 层，延时设置为 " << speed << "，不显示内部数组值" << endl;
        
        printpicture(qishi);
       
    }

    hannuota(qishi, zhongjian, mubiao, n);

    cct_gotoxy(0,20);

    system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    return 0;
}
