/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <cmath>
using namespace std;

void xiangdeng(double a, double b)
{
	cout << "���������ʵ����" << endl;
	double x1, x2;
	x1 = x2 = -b / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	cout << "x1=x2=" << x1 << endl;
	return;
}