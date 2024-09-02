/* 2152118 史君宝 计科 */
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

double f(double x)
{
	return (2 * x * x * x - 9 * x * x + 12 * x - 3);
}

void fun(double x1, double x2)
{
	double a,x;
	x = (x1 + x2) / 2;
	a = f(x);
	if (fabs(a) < 1e-6)
	{
		cout << "x1=" <<setiosflags(ios::fixed) << setprecision(3) <<x << endl;
		return;
	}
	if (a < 0)
		fun(x, x2);
	else
		fun(x1, x);
}

int main()
{
	fun(0, 1);
	return 0;
}

/* --- 此处给出思考题的答案，如果能给出 double fun(double x1, double x2) 形式的实现，也可以贴在注释中 ---
	在这一题中当我们实现了 fabs(a) < 1e-6 将根输出出来并用return退出的时候，
由于函数类型为void类型，返回到函数的上层的现场的时候，就可以结束不输出根。
整个过程过程只有求到根了才输出，可是如果改为double型的话就会有多个地方输出
就会把二分法过程中所有的中间点都输出，这样是不对的。

*/
