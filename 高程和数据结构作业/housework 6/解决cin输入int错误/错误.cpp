/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.good() == 0)
		{
			char ch;
			while ((ch =getchar())!= '\n')
			{
				cin.clear();
				cin.ignore();
			}
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}