/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <cmath>
using namespace std;

#include "4-b19.h"

int main()
{
	double a, b, c, gongshi;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
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
		budeng(a, b, gongshi);
	else if (gongshi == 0)
		xiangdeng(a, b);
	else if (gongshi < 0)
		xugen(a, b, c, gongshi);
	return 0;
}
