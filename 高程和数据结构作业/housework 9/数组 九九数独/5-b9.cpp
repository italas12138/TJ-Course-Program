/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

int main()
{
	int shudu[9][9];
	int cintrue = 0,sx,sy;
	int m=1;
	int jiugong[9][9] = { 0 };          //��žŹ����͵�����

	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;

	for(int i=0;i<9;++i)             //����������������
		for (int j = 0; j < 9; ++j)
		{
			cin >> shudu[i][j];
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(65535,'\n');
				cout << "�����������" << i + 1 << "��" << j + 1 
					 << "��(���о���1��ʼ����)��ֵ" << endl;
				--j;
			}
			else if (shudu[i][j] < 1 || shudu[i][j]>9)
			{
				--j;
				cout << "�����������" << i + 1 << "��" << j + 1
					<< "��(���о���1��ʼ����)��ֵ" << endl;
			}	
		}
	
	for(int i=0;i<9&&m;++i)                  //����������б���
		for (int j = 0; j < 9&&m; ++j)
			for (int k = j + 1;k<9; ++k)
			{
				if (shudu[i][k] == shudu[i][j])
					m = 0;
			}

	for (int i = 0; i < 9&&m; ++i)           //����������б���
		for (int j = 0; j < 9&&m; ++j)
			for (int k = j + 1;k<9; ++k)
			{
				if (shudu[k][i] == shudu[j][i])
					m = 0;
			}
	
	for(int i=0;i<9&&m;++i)                   //��������б������������Ǵ�ŵ��Ź���������
		for (int j = 0; j < 9&&m; ++j)
			jiugong[(i/3)*3+j/3][shudu[i][j] - 1] = shudu[i][j];

	for (int i = 0; i < 9&&m; ++i)           //�����Ź������飬�ҵ�����δ���ֵ�����
		for (int j = 0; j < 9&&m; ++j)
			if (jiugong[i][j] == 0)
				m = 0;

	if (m == 1)
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;

	return 0;
}