/* �ƿ� 2152118 ʷ���� */

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string name[10], number[10];
	int score[10];

	for (int i = 1; i <= 10; ++i)
	{
		cout<<"�������"<<i<<"���˵�ѧ�š��������ɼ�"<<endl;
		cin>>number[i - 1]>>name[i - 1]>>score[i - 1];
	}

	cout<<endl<<"ȫ��ѧ��(ѧ������) :"<<endl;

	int paixu[10] = { 0 }, change;
	for (int i = 1; i <= 10; ++i)
	{
		paixu[i - 1] = i;
	}


	for (int i = 0; i < 10 - 1; ++i)
	{
		for (int j = 0; j < 10 - (i + 1); ++j)
			if(number[paixu[j] - 1].compare(number[paixu[j + 1] - 1]) > 0)
			{
				change = paixu[j];
				paixu[j] = paixu[j + 1];
				paixu[j + 1] = change;
			}
	}

	for (int i = 0; i < 10; ++i)
		cout<<name[paixu[i] - 1]<<" "<<number[paixu[i] - 1]<<" "
		    <<score[paixu[i] - 1]<<endl;

	return 0;
}