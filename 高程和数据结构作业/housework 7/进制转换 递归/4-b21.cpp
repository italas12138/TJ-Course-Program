/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

void dec_to_base_n(int num, int base)
{
	unsigned int a;
	a = (unsigned int)(num);
	int yushu;
	if(a<base)
		if (a >= 10)
		{
			cout << char(a - 10 + 'A');
			return;
		}
		else
		{
			cout << a;
			return;
		}	
	yushu =a % base;
	a = a / base;
	num = (int)(a);
	dec_to_base_n(num, base);
	if (yushu >= 10)
	{
		cout << char(yushu - 10 + 'A');
		return;
	}
	cout << yushu;
	return;

	
}

int main()
{
	int num, base;

	cout << "������ʮ��������(int��)��Ҫת���Ľ���[2..16]" << endl;
	cin >> num >> base;		//�������������numΪint�ͷ�Χ�κ�ֵ���ɣ�baseΪ2~16��������10����

	if (base == 10) //����Ϊ10ֱ���˳�
		return -1;

	/* ��ɽ���ת������ӡ */
	dec_to_base_n(num, base);
	cout << endl;

	return 0;
}