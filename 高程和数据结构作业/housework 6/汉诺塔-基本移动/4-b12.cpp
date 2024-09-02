/* 2152118 史君宝 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        cout << n << "# " << src << "-->" << dst<<endl;
        return;
    }
    hanoi(n-1, src, dst, tmp);
    cout << n << "# " << src << "-->" << dst<<endl;
    hanoi(n-1, tmp, src, dst);
    return;
}

int main()
{
    int n;
    char qishi, zhongjian, mubiao;
    cout << "请输入汉诺塔的层数(1-16)" << endl;
    cin >> n;
    cout << "请输入起始柱(A-C)" << endl;
    cin >> qishi;
    cout << "请输入目标柱(A-C)" << endl;
    cin >> mubiao;
    cout << "移动步骤为:" << endl;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;
    hanoi(n, qishi, zhongjian, mubiao);

    return 0;
}