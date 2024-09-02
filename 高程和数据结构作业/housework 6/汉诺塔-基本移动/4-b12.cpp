/* 2152118 ʷ���� �ƿ� */
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
    cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
    cin >> n;
    cout << "��������ʼ��(A-C)" << endl;
    cin >> qishi;
    cout << "������Ŀ����(A-C)" << endl;
    cin >> mubiao;
    cout << "�ƶ�����Ϊ:" << endl;
    zhongjian = 'A' + 'B' + 'C' - qishi - mubiao;
    hanoi(n, qishi, zhongjian, mubiao);

    return 0;
}