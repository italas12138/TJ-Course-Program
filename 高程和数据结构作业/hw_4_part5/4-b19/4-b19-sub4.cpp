/* 2152118 史君宝 计科 */
#include <iostream>
#include <cmath>
using namespace std;

void xugen(double a, double b, double c, double gongshi)
{
	cout << "有两个虚根" << endl;
	double x1shi, x1xu;
	x1shi = -b / (2 * a);
	x1xu = sqrt(c / a - x1shi * x1shi);
	if (fabs(x1shi) < 1e-6)
		x1shi = 0;
	if (fabs(x1xu) < 1e-6)
		x1xu = 0;
	if (x1xu == 0)
	{
		cout << "x1=" << x1shi << endl;
		cout << "x2=" << x1shi << endl;
		return;
	}
	else if (x1shi == 0)
	{
		if (x1xu != 1)
		{
			cout << "x1=+" << x1xu << "i" << endl;
			cout << "x2=-" << x1xu << "i" << endl;
			return;
		}
		else
		{
			cout << "x1=+i" << endl;
			cout << "x2=-i" << endl;
			return;
		}
	}
	else
	{
		if (x1xu != 1)
		{
			cout << "x1=" << x1shi << "+" << x1xu << "i" << endl;
			cout << "x2=" << x1shi << "-" << x1xu << "i" << endl;
			return;
		}
		else
		{
			cout << "x1=" << x1shi << "+i" << endl;
			cout << "x2=" << x1shi << "-i" << endl;
			return;
		}
	}
}