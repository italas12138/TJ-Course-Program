/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

int main()
{
	int shuzu[40]={0};
	int a=0,n = 0,charu,cixu;
	cout << "��������������������������20��������-1����" << endl;
	while (1)
	{
		cin >> a;
		shuzu[n] = a;
		if (a == -1)
			break;
		++n;
	}
	if (n == 0)
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	if (n > 19)
		n = 20;
	cout << "ԭ����Ϊ��" << endl;
	for (int i = 0; i < n; ++i)
		cout << shuzu[i]<<" ";
	cout << endl;
	cout << "������Ҫ�����������" << endl;
	cin >> charu;
	for (cixu = 0; cixu< n ; ++cixu)
		if (shuzu[cixu] > charu)
			break;
	if (cixu == n)
		shuzu[cixu] = charu;
	else
	{
		for (int y = n -1; y >= cixu; --y)
			shuzu[y + 1] = shuzu[y];
		shuzu[cixu] = charu;
	}
	++n;
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < n; ++i)
		cout << shuzu[i] << " ";
	cout << endl;
	return 0;
}