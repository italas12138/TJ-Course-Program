/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

int main()
{
	int chengji[1100] = { 0 }, chengjibiao[101] = { 0 };
	int a = 0, n = 0,cixu=0;
	cout << "������ɼ������1000��������-1����" << endl;
	while (1)
	{
		cin >> a;
		chengji[n] = a;
		if (a == -1)
			break;
		++chengjibiao[a];
		++n;
	}
	if (n == 0)
	{
		cout<<"����Ч����"<<endl;
		return 0;
	}
	cout<<"���������Ϊ:"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<chengji[i]<<" ";
		if ((i + 1) % 10 == 0)
			cout<<endl;
	}
	if (n % 10 != 0)
		cout << endl;
	cout<<"���������εĶ�Ӧ��ϵΪ:\n"<<endl;
	for (int i = 100; i >= 0; --i)
		if (chengjibiao[i] > 0)
		{
			for (int j = chengjibiao[i]; j > 0; --j)
				cout << i << " " << cixu + 1<<endl;
			cixu += chengjibiao[i];
		}

	return 0;
}