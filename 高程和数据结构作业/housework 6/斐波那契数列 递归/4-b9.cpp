/* 2152118 史君宝 计科*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int fibonacci(int n)
{
	int sum;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	sum = fibonacci(n - 1) + fibonacci(n - 2);
	return sum;
}

int main()
{
		int n, f;
		cout << "请输入Fibonacci数列的项数[1-46]" << endl;
		cin >> n;

		LARGE_INTEGER tick, begin, end;
		QueryPerformanceFrequency(&tick);	//获得时钟频率
		QueryPerformanceCounter(&begin);	//获得初始硬件定时器计数
		f = fibonacci(n);
		cout << "Fibonacci数列第" << n << "项的值 : " << f << endl;

		QueryPerformanceCounter(&end);//获得终止硬件定时器计数
		cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
		cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
		cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}