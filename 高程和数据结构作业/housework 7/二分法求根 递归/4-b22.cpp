/* 2152118 ʷ���� �ƿ� */
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

/* --- �˴�����˼����Ĵ𰸣�����ܸ��� double fun(double x1, double x2) ��ʽ��ʵ�֣�Ҳ��������ע���� ---
	����һ���е�����ʵ���� fabs(a) < 1e-6 ���������������return�˳���ʱ��
���ں�������Ϊvoid���ͣ����ص��������ϲ���ֳ���ʱ�򣬾Ϳ��Խ������������
�������̹���ֻ���󵽸��˲���������������Ϊdouble�͵Ļ��ͻ��ж���ط����
�ͻ�Ѷ��ַ����������е��м�㶼����������ǲ��Եġ�

*/
