/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

int main()
{
	int shudu[9][9];
	int cintrue = 0,sx,sy;
	int m=1;
	int jiugong[9][9] = { 0 };          //存放九宫格型的数据

	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	for(int i=0;i<9;++i)             //向数独中输入数据
		for (int j = 0; j < 9; ++j)
		{
			cin >> shudu[i][j];
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(65535,'\n');
				cout << "请重新输入第" << i + 1 << "行" << j + 1 
					 << "列(行列均从1开始计数)的值" << endl;
				--j;
			}
			else if (shudu[i][j] < 1 || shudu[i][j]>9)
			{
				--j;
				cout << "请重新输入第" << i + 1 << "行" << j + 1
					<< "列(行列均从1开始计数)的值" << endl;
			}	
		}
	
	for(int i=0;i<9&&m;++i)                  //对数组进行行遍历
		for (int j = 0; j < 9&&m; ++j)
			for (int k = j + 1;k<9; ++k)
			{
				if (shudu[i][k] == shudu[i][j])
					m = 0;
			}

	for (int i = 0; i < 9&&m; ++i)           //对数组进行列遍历
		for (int j = 0; j < 9&&m; ++j)
			for (int k = j + 1;k<9; ++k)
			{
				if (shudu[k][i] == shudu[j][i])
					m = 0;
			}
	
	for(int i=0;i<9&&m;++i)                   //对数组进行遍历，并把它们存放到九宫格数组中
		for (int j = 0; j < 9&&m; ++j)
			jiugong[(i/3)*3+j/3][shudu[i][j] - 1] = shudu[i][j];

	for (int i = 0; i < 9&&m; ++i)           //遍历九宫格数组，找到其中未出现的数。
		for (int j = 0; j < 9&&m; ++j)
			if (jiugong[i][j] == 0)
				m = 0;

	if (m == 1)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;

	return 0;
}