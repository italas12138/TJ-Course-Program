/* 计科 2152118 史君宝 */

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

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void menu();

//按回车返回菜单的函数
void return_menu(int choice)
{
    char m;
    if (choice == 1 || choice == 2||choice==3)
        cout << endl << endl;
    else
        cct_gotoxy(0, 35);
    cout << "按回车键继续";
    while ((m = getchar()) != '\n');
    a_top = b_top = c_top = cishu = 0;
    speed = 4;
    for (int i = 0; i < 10; ++i)
        a[i] = b[i] = c[i] = 0;
    cct_cls();
    menu();
}

//延时函数
void wait()               //设置等待方式的函数
{
    char a;
    if (speed == 0)      //回车——>下一步 
        while ((a = getchar()) != '\n');
    if (speed == 1)       //速度最慢   
        Sleep(1000);  
    if (speed == 2)  
        Sleep(500);      
    if (speed == 3)    
        Sleep(200);   
    if (speed == 4)
        Sleep(50);    
    if (speed == 5)//速度最快 
        Sleep(10);       
    return;
}

//实现在图上将A圆盘移到B上
void moveAB()
{
    int x, y;
    for (y = 14 - a_top; y >= 1; --y) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(12 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(12 - a[a_top], y, ' ', 0, 0, 2 * a[a_top]);//黑色
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(12, y, ' ', 0, 0, 1);//黑色
            cct_showch(13, y, ' ', 0, 0, 2 * a[a_top]);//黑色
        }
    } //end of for

    for (x = 12 - a[a_top]; x <= 44 - a[a_top]; x++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(x, 1, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x < 44 - a[a_top]) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, 1, ' ', 0, 0, 2 * a[a_top] + 1);//黑色
        }
    } //end of for


    for (y = 1; y <= 15 - b_top; y++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(44 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - b_top) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(44 - a[a_top], y, ' ', 0, 0, a[a_top]);//黑色
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(44, y, ' ', 0, 0, 1);//黑色
            cct_showch(45, y, ' ', 0, 0, a[a_top]);//黑色
        }
    } //end of for
}

//实现在图上将A圆盘移到C上
void moveAC()
{
    int x, y;
    for (y = 14 - a_top; y >= 1; --y) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(12 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(12 - a[a_top], y, ' ', 0, 0, 2 * a[a_top]);//黑色
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(12, y, ' ', 0, 0, 1);//黑色
            cct_showch(13, y, ' ', 0, 0, 2 * a[a_top]);//黑色
        }
    } //end of for

    for (x = 12 - a[a_top]; x <= 76 - a[a_top]; x++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(x, 1, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x < 76 - a[a_top]) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, 1, ' ', 0, 0, 2 * a[a_top] + 1);//黑色
        }
    } //end of for

    for (y = 1; y <= 15 - c_top; y++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(76 - a[a_top], y, ' ', 14 - a[a_top], 0, 2 * a[a_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - c_top) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(76 - a[a_top], y, ' ', 0, 0, a[a_top]);//黑色
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(76, y, ' ', 0, 0, 1);//黑色
            cct_showch(77, y, ' ', 0, 0, a[a_top]);//黑色
        }
    } //end of for
}

//实现在图上将B圆盘移到A上
void moveBA()
{
    int x, y;
    for (y = 14 - b_top; y >= 1; --y) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(44 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(44 - b[b_top], y, ' ', 0, 0, 2 * b[b_top]);//黑色
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(44, y, ' ', 0, 0, 1);//黑色
            cct_showch(45, y, ' ', 0, 0, 2 * b[b_top]);//黑色
        }
    } //end of for

    for (x = 44 - b[b_top]; x >= 12 - b[b_top]; --x) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(x, 1, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x > 12 - b[b_top]) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, 1, ' ', 0, 0, 2 * b[b_top] + 1);//黑色
        }
    } //end of for


    for (y = 1; y <= 15 - a_top; y++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(12 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - a_top) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(12 - b[b_top], y, ' ', 0, 0, b[b_top]);//黑色
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(12, y, ' ', 0, 0, 1);//黑色
            cct_showch(13, y, ' ', 0, 0, b[b_top]);//黑色
        }
    } //end of for
}

//实现在图上将B圆盘移到C上
void moveBC()
{
    int x, y;
    for (y = 14 - b_top; y >= 1; --y) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(44 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(44 - b[b_top], y, ' ', 0, 0, 2 * b[b_top]);//黑色
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(44, y, ' ', 0, 0, 1);//黑色
            cct_showch(45, y, ' ', 0, 0, 2 * b[b_top]);//黑色
        }
    } //end of for

    for (x = 44 - b[b_top]; x <= 76 - b[b_top]; ++x) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(x, 1, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x < 76 - b[b_top]) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, 1, ' ', 0, 0, 2 * b[b_top] + 1);//黑色
        }
    } //end of for


    for (y = 1; y <= 15 - c_top; y++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(76 - b[b_top], y, ' ', 14 - b[b_top], 0, 2 * b[b_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - c_top) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(76 - b[b_top], y, ' ', 0, 0, b[b_top]);//黑色
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(76, y, ' ', 0, 0, 1);//黑色
            cct_showch(77, y, ' ', 0, 0, b[b_top]);//黑色
        }
    } //end of for
}

//实现在图上将C圆盘移到A上
void moveCA()
{
    int x, y;
    for (y = 14 - c_top; y >= 1; --y) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(76 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(76 - c[c_top], y, ' ', 0, 0, 2 * c[c_top]);//黑色
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(76, y, ' ', 0, 0, 1);//黑色
            cct_showch(77, y, ' ', 0, 0, 2 * c[c_top]);//黑色
        }
    } //end of for

    for (x = 76 - c[c_top]; x >= 12 - c[c_top]; --x) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(x, 1, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x > 12 - c[c_top]) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, 1, ' ', 0, 0, 2 * c[c_top] + 1);//黑色
        }
    } //end of for


    for (y = 1; y <= 15 - a_top; y++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(12 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - a_top) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(12 - c[c_top], y, ' ', 0, 0, c[c_top]);//黑色
            if (y >= 3)
                cct_showch(12, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(12, y, ' ', 0, 0, 1);//黑色
            cct_showch(13, y, ' ', 0, 0, c[c_top]);//黑色
        }
    } //end of for
}

//实现在图上将C圆盘移到B上
void moveCB()
{
    int x, y;
    for (y = 14 - c_top; y >= 1; --y) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(76 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y > 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(76 - c[c_top], y, ' ', 0, 0, 2 * c[c_top]);//黑色
            if (y >= 3)
                cct_showch(76, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(76, y, ' ', 0, 0, 1);//黑色
            cct_showch(77, y, ' ', 0, 0, 2 * c[c_top]);//黑色
        }
    } //end of for

    for (x = 76 - c[c_top]; x >= 44 - c[c_top]; --x) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(x, 1, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (x > 44 - c[c_top]) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, 1, ' ', 0, 0, 2 * c[c_top] + 1);//黑色
        }
    } //end of for


    for (y = 1; y <= 15 - b_top; y++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(44 - c[c_top], y, ' ', 14 - c[c_top], 0, 2 * c[c_top] + 1);

        if (speed != 0)
            wait();
        else
            Sleep(100);

        if (y < 15 - b_top) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(44 - c[c_top], y, ' ', 0, 0, c[c_top]);//黑色
            if (y >= 3)
                cct_showch(44, y, ' ', 14, 0, 1);//黑色
            else
                cct_showch(44, y, ' ', 0, 0, 1);//黑色
            cct_showch(45, y, ' ', 0, 0, c[c_top]);//黑色
        }
    } //end of for
}

//画出汉诺塔的柱子
void photo_hanoi()
{
    //画下面的底座
    cct_showch(1, 15, ' ', 14, 0, 23);
    cct_showch(33, 15, ' ', 14, 0, 23);
    cct_showch(65, 15, ' ', 14, 0, 23);

    //画上面的柱子
    for (int i = 15; i >= 3; --i)
    {
        Sleep(100);
        cct_showch(12, i, ' ', 14, 0, 1);
        cct_showch(44, i, ' ', 14, 0, 1);
        cct_showch(76, i, ' ', 14, 0, 1);
    }
    cct_gotoxy(0, 20);   //光标到（0,20）处
    cct_setcolor(0, 7);  //颜色调回初始值
}

//画出汉诺塔的圆盘
void photo_circle(char qishi)
{
    //判断起始柱是ABC，然后对应的画圆盘
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
    cct_setcolor(0, 7);    //颜色调回初始值
}

//该操作用于实现圆盘的移动，并实现对应情况的分流
void move_circle(int choice,char qishi,char zhongjian,char mubiao) 
{
    //起始柱是A，目标柱是B，则通过moveAB函数实现移动圆盘
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

//打印横向的数组
void print_heng(int n,char qishi,char zhongjina,char mubiao,int choice)
{
    if(choice==3)
        printf("第%4d 步(%2d#: %c-->%c)", ++cishu, n, qishi, mubiao);
    else
        cout << "第" << setw(4) << ++cishu << "步(" << n << "# " << qishi << "--> " << mubiao << ")";

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

//反映移动过程中的数组变化，并在过程中帮助choice==9情况下判断移动是否是正确的
void move(char qishi, char zhongjian, char mubiao, int choice, int X)
{
    if (qishi == 'A')
    {
        if (mubiao == 'B')
        {
            //下面是通过数组内容判断choice==9时，移动是否是正确的
            if (choice == 9 && (a[a_top - 1] > b[b_top -1] && b[b_top - 1] != 0))
            {
                cct_gotoxy(0,31);
                cout << "大盘压小盘，非法移动!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && a_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "源柱为空!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }

            //下面是模拟数组内容变化的过程，在choice==4或8或9时，还将在打印的汉诺塔上
            //完成元素的变化
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
                cout << "大盘压小盘，非法移动!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && a_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "源柱为空!" << endl;
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
                cout << "大盘压小盘，非法移动!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && b_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "源柱为空!" << endl;
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
                cout << "大盘压小盘，非法移动!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && b_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "源柱为空!" << endl;
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
                cout << "大盘压小盘，非法移动!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if(choice==9&&c_top==0)
            {
                cct_gotoxy(0, 31);
                cout << "源柱为空!" << endl;
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
                cout << "大盘压小盘，非法移动!" << endl;
                Sleep(1000);
                cct_gotoxy(0, 31);
                cout << "                                                     ";
                return;
            }
            if (choice == 9 && c_top == 0)
            {
                cct_gotoxy(0, 31);
                cout << "源柱为空!" << endl;
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

//打印纵向的数组
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

//输入函数汇总(根据不同的choice采用不同的输入)
void input(int &n,char &qishi,char &mubiao,int &choice)
{
    cout << endl;
    //输入汉诺塔层数，并错误处理
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65535, '\n');
        if (n <= 10 && n >= 1)
            break;
    }

    //输入起始柱，并错误处理
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> qishi;
        cin.clear();
        cin.ignore(65535, '\n');
        if (qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a')
            break;
    }
    if (qishi <= 'c' && qishi >= 'a')
        qishi -= 32;

    //输入目标柱，并错误处理
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
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
        //输入移动速度0-5，并错误处理
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> speed;
            cin.clear();
            cin.ignore(65535, '\n');
            if (speed <= 5 && speed >= 0)
                break;
        }
    }
    return;
}

//输出格式的汇总(根据choice的不同采用不同的输出)
void output(int choice,int n, char src, char tmp, char dst)
{
    if (choice == 1)
        cout << n << "# " << src << "---->" << dst << endl;

    if(choice==2)
        cout << "第"<<setw(5) << setiosflags(ios::right) << ++cishu << " 步(" << setw(2)
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

//choice==9的时候，输入的玩游戏函数
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
            cout << "游戏中止!!!!!";
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
                cout << "游戏结束!!!!!";
                Sleep(1000);
                return;
            }
    }
}

//汉诺塔的递归函数
void hanoi(int n, char src, char tmp, char dst, int choice)
{
    //src 起始      tmp 中间        dst 目标
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

//确定中间柱，并通过引用参数传回中间柱
void makesurerod(int n,char qishi,char mubiao,char &zhongjian)
{
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
}

//完成不同的choice值，调用不同函数的过程
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
            cout << "从 " << qishi << "移动到 " << mubiao << "，共 " << n << " 层";
            if (choice == 8)
                cout << "，延时设置为 " << speed;
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
            cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
            cinplay(qishi,' ', mubiao, n);
        }
        else
            hanoi(n, qishi, zhongjian, mubiao, choice);
    }
    return_menu(choice);
    return;
}


