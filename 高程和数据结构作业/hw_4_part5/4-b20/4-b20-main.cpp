/* 2152118 史君宝 计科 */
#include <iostream>
#include <cmath>
using namespace std;
 
double a, b, c,gongshi;

void yiyuan();
void budeng();
void xiangdeng();
void xugen();

int main()
{
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
		budeng();
	else if (gongshi == 0)
		xiangdeng();
	else if (gongshi < 0)
		xugen();
	return 0;
}