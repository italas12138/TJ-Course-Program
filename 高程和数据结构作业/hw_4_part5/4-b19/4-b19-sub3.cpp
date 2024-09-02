/* 2152118 史君宝 计科 */
#include <iostream>
#include <cmath>
using namespace std;

void budeng(double a, double b, double gongshi)
{
	cout << "有两个不等实根：" << endl;
	double x1, x2;
	x1 = (-b + sqrt(gongshi)) / (2 * a);
	x2 = (-b - sqrt(gongshi)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	return;
}