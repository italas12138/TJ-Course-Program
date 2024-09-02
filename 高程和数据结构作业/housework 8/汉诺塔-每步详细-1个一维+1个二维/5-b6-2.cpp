/* 2152118 史君宝 计科 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int cishu = 0;
int top[3];
int yuanpan[3][10];

void printhannuota(char qishi, char mubiao, int n)
{
    ++cishu;
    if (qishi == 'A')
    {
        --top[0];
        if (mubiao == 'B')
        {
            yuanpan[1][top[1]] = yuanpan[0][top[0]];
            ++top[1];
        }
        else if (mubiao == 'C')
        {
            yuanpan[2][top[2]] = yuanpan[0][top[0]];
            ++top[2];
        }
    }

    else if (qishi == 'B')
    {
        --top[1];
        if (mubiao == 'A')
        {
            yuanpan[0][top[0]] = yuanpan[1][top[1]];
            ++top[0];
        }
        else if (mubiao == 'C')
        {
            yuanpan[2][top[2]] = yuanpan[1][top[1]];
            ++top[2];
        }
    }
     
    else
    {
        --top[2];
        if (mubiao == 'A')
        {
            yuanpan[0][top[0]] = yuanpan[2][top[2]];
            ++top[0];
        }
        else if (mubiao == 'B')
        {
            yuanpan[1][top[1]] = yuanpan[2][top[2]];
            ++top[1];
        }
    }
    cout<<"第"<<setw(4)<<cishu<<" 步("<<setw(2)<<n<<"): "
        <<qishi<<"-->"<<mubiao <<" A:";
    for (int i = 0; i < top[0]; ++i)
        cout << setw(2) << yuanpan[0][i];
    for (int i = top[0]; i < 10; ++i)
        cout << "  ";
    cout << " B:";
    for (int i = 0; i <top[1]; ++i)
        cout << setw(2) << yuanpan[1][i];
    for (int i = top[1]; i < 10; ++i)
        cout << "  ";
    cout << " C:";
    for (int i = 0; i < top[2]; ++i)
        cout << setw(2) << yuanpan[2][i];
    for (int i = top[2]; i < 10; ++i)
        cout << "  ";
    cout << endl;
}

void hannuota(char qishi, char zhongjian, char mubiao, int n)
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
    char qishi, mubiao, zhongjian, fuzhu;
    int n;

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

    zhongjian = 'A' + 'B' + 'C' - mubiao - qishi;

    if (qishi == 'A')
    {
       top[0] = n;
        for (int i = 0; i < n; ++i)
            yuanpan[0][i] = n - i;
    }
    else if (qishi == 'B')
    {
        top[1] = n;
        for (int i = 0; i < n; ++i)
            yuanpan[1][i] = n - i;
    }
    else
    {
        top[2] = n;
        for (int i = 0; i < n; ++i)
            yuanpan[2][i] = n - i;
    }

    cout<<"初始:                A:";
    for (int i = 0; i < top[0]; ++i)
        cout << setw(2) << yuanpan[0][i];
    for (int i = top[0]; i < 10; ++i)
        cout << "  ";
    cout << " B:";
    for (int i = 0; i < top[1]; ++i)
        cout << setw(2) << yuanpan[1][i];
    for (int i = top[1]; i < 10; ++i)
        cout << "  ";
    cout << " C:";
    for (int i = 0; i < top[2]; ++i)
        cout << setw(2) << yuanpan[2][i];
    for (int i = top[2]; i < 10; ++i)
        cout << "  ";
    cout << endl;

    hannuota(qishi, zhongjian, mubiao, n);

    return 0;
}
