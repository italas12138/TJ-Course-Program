/* 2152118 �ƿ� ʷ���� */

#define Pi 3.14159
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int a, b, jiao;
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	cin >> a >> b >> jiao;
	double hu, s;
	hu = jiao /180.0*Pi;
	s = 0.5 * a * b * sin(hu);
	cout << setiosflags(ios::fixed);
	cout << "���������Ϊ : " <<setprecision(3)<< s << endl;

	return 0;
}