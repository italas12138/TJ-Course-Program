/* 2152118 史君宝 计科 */
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
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    while (!(qishi <= 'C' && qishi >= 'A' || qishi <= 'c' && qishi >= 'a'))
    {
        cout << "请输入起始柱(A-C)" << endl;
        qishi = getchar();
        cin.clear();
        cin.ignore(65535, '\n');
    }
    while ((!(mubiao <= 'C' && mubiao >= 'A' || mubiao <= 'c' && mubiao >= 'a')) && (mubiao != qishi))
    {
        cout << "请输入目标柱(A-C)" << endl;
        mubiao = getchar();
        if (mubiao == qishi)
           cout<<"目标柱("<<mubiao<<")不能与起始柱("<<qishi<<")相同"<<endl;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    cout << mubiao;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;
    cout << "移动步骤为" << endl;
    hanoi(n, qishi,zhongjian,mubiao);
    return 0;
}