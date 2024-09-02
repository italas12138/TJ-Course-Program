/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;

void hanoi(int n, char src, char tmp, char dst)
{
    static int i=0;
    if (n == 1)
    {
        cout << setw(5) << setiosflags(ios::right) << ++i << ": " << setw(2)
             << setiosflags(ios::right) << n << "# " << src << "-- >" << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp); 
    cout <<setw(5)<<setiosflags(ios::right)<<++i << ": " << setw(2) 
         << setiosflags(ios::right) << n << "# " << src << "-- >" << dst << endl;
    hanoi(n - 1, tmp, src, dst);
    return;
}

int main()
{
    char qishi=' ', mubiao=' ', zhongjian;
    int n=-1;
    
    while (!(n >= 1 && n <= 16))
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        cout << "��������ʼ��(A-C)" << endl;
        qishi = getchar();
        cin.clear();
        cin.ignore(65535, '\n');
    }
    while ((!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')) && (mubiao != qishi))
    {
        cout << "������Ŀ����(A-C)" << endl;
        mubiao = getchar();
        if (mubiao == qishi)
           cout<<"Ŀ����("<<mubiao<<")��������ʼ��("<<qishi<<")��ͬ"<<endl;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    cout << mubiao;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;
    cout << "�ƶ�����Ϊ" << endl;
    hanoi(n, qishi,zhongjian,mubiao);
    return 0;
}