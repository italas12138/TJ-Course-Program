/* �ƿ� 2152118 ʷ���� */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int cishu=1;
	double sum = 1,x;
	do
	{
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if (x<-10 || x>+65)
			cout << "����Ƿ�������������" << endl;
		else
		{
			for (double s = 1; fabs(s) >=1e-6; ++cishu)
				s *= x / cishu;
			for (int i = 1; i <= cishu; ++i)
			{
				double s = 1;
				for (int j = 1; j <= i; ++j)
					s *= x / j;
				sum += s;
			}
			cout << "e^"<<x<<"=" << setprecision(10) << sum << endl;
		}
	} while (x<-10 || x>+65);
	return 0;
}
