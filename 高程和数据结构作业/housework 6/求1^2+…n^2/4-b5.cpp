/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

int sum_of_square(int n)
{
	int sum = 0;
	if (n == 2)
		sum = 5;
	else
		sum += n * n + sum_of_square(n - 1);
	return sum;
}

int main()
{
	int n;
	cout << "��1^2+2^2+...+n^2��������nֵ[3..1860]" << endl;
	cin >> n;
	cout << "1^2+2^2+...+" << n << "^2=" << sum_of_square(n) << endl;

	return 0;
}
