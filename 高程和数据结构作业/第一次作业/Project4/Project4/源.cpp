/* 2152118 计科 史君宝 */

#define Pi 3.14159
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int a, b, jiao;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> jiao;
	double hu, s;
	hu = jiao /180.0*Pi;
	s = 0.5 * a * b * sin(hu);
	cout << setiosflags(ios::fixed);
	cout << "三角形面积为 : " <<setprecision(3)<< s << endl;

	return 0;
}