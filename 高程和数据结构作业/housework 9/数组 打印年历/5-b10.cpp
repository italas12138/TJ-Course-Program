/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)         //���ò��չ�ʽ���ÿ���µĵ�һ�����ܼ�
{
	int w = 0, c;
	if (m == 1 || m == 2)
	{
		m = 12 + m;
		--y;
	}
	c = y / 100;
	y = y % 100;
	w = y + int(y / 4) + int(c / 4) - 2 * c + int(13 * (m + 1) / 5) + d - 1;
	if (w >= 0)
		w %= 7;
	else
	{
		while (w < 0)
			w += 7;
		w %= 7;
	}
	return w;
}

int main()
{
	system("mode con cols=120 lines=45");

	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };       //�·�������
	int year;                                                     
	bool run = 0;            //�ж��Ƿ�������

	cout << "���������[1900-2100]" << endl;
	cin >> year;

	//�ж��Ƿ�������
	if (year % 4 == 0)
	{
		run = 1;
		if (year % 100 == 0)
		{
			run = 0;
			if (year % 400 == 0)
				run = 1;
		}
	}
	
	if(run==1)                    //������·ݼ�1
		++month[1];

	cout << year << "�������:" << endl;
	cout << endl;

	int a, b, c, aday, bday, cday;

	for (int i = 0; i < 4; ++i)               //��һ���Ϊ4���֣�ÿ�δ�ӡͬ�е�������
	{
		//��ӡ��ͷ �·�
		cout << setw(13) << i * 3 + 1 << "��" << setw(30) << i * 3 + 2 << "��"    
			<< setw(30) << i * 3 + 3 << "��" << endl;

		//��ӡ���ڱ�ͷ
		for (int w = 0; w < 3; ++w)
			cout << "Sun Mon Tue Wed Thu Fri Sat     ";
		cout << endl;

		//���ò��չ�ʽ��ÿ�µ�һ�����ڼ�
		if(i * 3 + 1<3)
			a= zeller(year-1, i * 3 + 13, 1);
		else
			a = zeller(year, i * 3 + 1, 1);
		if (i * 3 + 2 < 3)
			b = zeller(year - 1, i * 3 + 14, 1);
		else
			b = zeller(year, i * 3 + 2, 1);
		c = zeller(year, i * 3 + 3, 1);

		//��ӡ��ʼ��ʼ�ĵ�һ���ǵڼ��졣������ֵ��������������
		//�������1������������ô��ʼ��ӡ��������������-2�ţ�Ϊ�˴�ӡ���㣩
		aday = 1 - a;
		bday = 1 - b;
		cday = 1 - c;

		//����������������������������µ�������ֹͣ��ӡ
		while (aday <= month[i * 3] || bday <= month[i * 3 + 1] || cday <= month[i * 3 + 2])
		{
			for (int m = 0; m < 7; ++m)         //��ӡͬ�ŵ�һ���µ�����
			{
				//�������������ָ��1�����£����߶��ڵ������������ɴ�ӡ�ո�
				if (aday<1 || aday>month[i * 3]) 
				{
					++aday;
					cout << "    ";
				}
				//�����ӡ���¡�
				else
					cout << setw(4) << setiosflags(ios::left) << aday++;
			}
			cout << "    ";

			//��ӡͬ�ŵĵĵڶ����µ�����
			for (int m = 0; m < 7; ++m)
			{
				if (bday<1 || bday>month[i * 3 + 1])
				{
					++bday;
					cout << "    ";
				}
				else
					cout << setw(4) << setiosflags(ios::left) << bday++;
			}
			cout << "    ";

			//��ӡͬ�ŵĵĵ������µ�����
			for (int m = 0; m < 7; ++m)
			{
				if (cday<1 || cday>month[i * 3 + 2])
				{
					++cday;
					cout << "    ";
				}
				else
					cout << setw(4) << setiosflags(ios::left) << cday++;
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}