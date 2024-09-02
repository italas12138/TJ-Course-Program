/* 2152118 ʷ���� �ƿ�*/
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
		cout << "������Fibonacci���е�����[1-46]" << endl;
		cin >> n;

		LARGE_INTEGER tick, begin, end;
		QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
		QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
		f = fibonacci(n);
		cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;

		QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
		cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
		cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
		cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}