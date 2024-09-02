/*2152118 史君宝 计科*/
/* 2152095 龚宣  2051877 邓凯伦  2053932 雷翔  2151569 明添识  2152069 马明扬 */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream filein;
	ofstream fileout;

	cerr << "文件名以下形式均可以:" << endl;
	cerr << "a.hex                     : 不带路径形式" << endl;
	cerr << "..\\data\\b.txt             : 相对路径形式" << endl;
	cerr << "C : \\Windows\\System32\\c.hex : 绝对相对路径形式" << endl;
	cerr << "请输入要转换的hex格式文件名 : ";

	char fileinname[200],fileoutname[200];

	cin.getline(fileinname,200);

	cerr << "请输入转换后的文件名        : ";

	cin.getline(fileoutname, 200);

	filein.open(fileinname,ios::in|ios::binary);

	fileout.open(fileoutname, ios::out| ios::binary);

	if (filein.is_open() == 0)
	{
		clog << "输入文件" << fileinname << "打开失败!"<<endl;
		return -1;
	}

	if (fileout.is_open() == 0)
	{
		clog << "输入文件" << fileoutname << "打开失败!"<<endl;
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