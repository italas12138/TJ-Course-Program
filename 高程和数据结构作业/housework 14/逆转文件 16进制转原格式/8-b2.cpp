/*2152118 ʷ���� �ƿ�*/
/* 2152095 ����  2051877 �˿���  2053932 ����  2151569 ����ʶ  2152069 ������ */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream filein;
	ofstream fileout;

	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "a.hex                     : ����·����ʽ" << endl;
	cerr << "..\\data\\b.txt             : ���·����ʽ" << endl;
	cerr << "C : \\Windows\\System32\\c.hex : �������·����ʽ" << endl;
	cerr << "������Ҫת����hex��ʽ�ļ��� : ";

	char fileinname[200],fileoutname[200];

	cin.getline(fileinname,200);

	cerr << "������ת������ļ���        : ";

	cin.getline(fileoutname, 200);

	filein.open(fileinname,ios::in|ios::binary);

	fileout.open(fileoutname, ios::out| ios::binary);

	if (filein.is_open() == 0)
	{
		clog << "�����ļ�" << fileinname << "��ʧ��!"<<endl;
		return -1;
	}

	if (fileout.is_open() == 0)
	{
		clog << "�����ļ�" << fileoutname << "��ʧ��!"<<endl;
		return -1;
	}

	int sum;
	bool goout = 1;
	char k[100];
	int ch;

	while (1)
	{
		if ((ch = filein.get()) == -1)
			break;
		else 
			filein.seekg(-1, ios::cur);

		filein.read(k, 11 * sizeof(char));

		for (int i = 0; i < 8; ++i)
		{
			filein.read(k, 3 * sizeof(char));
			if (k[0] == ' ' && k[1] == ' ')
			{
				goout = 0;
				break;
			}

			if (k[0] >= 'A' && k[0] <= 'F')
				k[0] = k[0] - 'A' + 10+'0';
			if (k[1] >= 'A' && k[1] <= 'F')
				k[1] = k[1] - 'A' + 10+'0';

			sum = (k[0] - '0') * 16 + (k[1] - '0');
			fileout << char(sum);
		}

		if (goout == 0)
			break;

		filein.read(k, 2 * sizeof(char));

		for (int i = 0; i < 8; ++i)
		{
			filein.read(k, 3 * sizeof(char));
			if (k[0] == ' ' && k[1] == ' ')
			{
				goout = 0;
				break;
			}

			if (k[0] >= 'A' && k[0] <= 'F')
				k[0] = k[0] - 'A' + 10+'0';
			if (k[1] >= 'A' && k[1] <= 'F')
				k[1] = k[1] - 'A' + 10+ '0';

			sum = (k[0] - '0') * 16 + (k[1] - '0');
			fileout << char(sum);
		}

		if (goout == 0)
			break;

		filein.read(k, 17 * sizeof(char));
		
		if ((ch = filein.get()) == -1) {
			break;
		}
		if ((ch = filein.get()) == -1) {
			break;
		}
	}

	filein.close();
	fileout.close();

	return 0;
}