#include <iostream>
#include <cmath>
using namespace std;

void yiyuan()
{
	cout << "不是一元二次方程" << endl;
	return;
}

void xiangdeng(double a,double b)
{
	cout << "有两个相等实根：" << endl;
	double x1, x2;
	x1 = x2 = -b / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	cout << "x1=x2=" << x1 << endl;
	return;
}

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

void xugen(double a, double b,double c,double gongshi)
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

int main()
{
	double a, b, c,gongshi;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
	{
		a = 0;
		yiyuan();
		return 0;
	}
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	gongshi = b * b - 4 * a * c;
	if (fabs(gongshi) < 1e-6)
		gongshi = 0;
	if (gongshi > 0)
		budeng(a,b,gongshi);
	else if (gongshi == 0)
		xiangdeng(a,b);
	else if (gongshi < 0)
		xugen(a,b,c,gongshi);
	return 0;
}
