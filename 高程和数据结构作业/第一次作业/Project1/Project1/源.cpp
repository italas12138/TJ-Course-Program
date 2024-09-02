/* 2152118 计科 史君宝 */

#define Pi 3.14159
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed);
	cout << "圆周长     " << ": " 
		 << setprecision(2) << 2 * r * Pi << endl;
	cout << "圆面积     " << ": " 
		 << setprecision(2) << Pi * r * r << endl;
	cout << "圆球表面积 " << ": " 
		 << setprecision(2) << 4 * Pi * r * r << endl;
	cout << "圆球体积   " << ": " 
		 << setprecision(2) << 4 / 3.0 * Pi * r * r * r << endl;
	cout << "圆柱体积   " << ": " 
		 << setprecision(2) << Pi * r * r * h << endl;

	return 0;
}