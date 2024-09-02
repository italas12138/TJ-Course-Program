/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

int main()
{
	int chengji[1100] = { 0 }, chengjibiao[101] = { 0 };
	int a = 0, n = 0,cixu=0;
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
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
		cout<<"无有效输入"<<endl;
		return 0;
	}
	cout<<"输入的数组为:"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<chengji[i]<<" ";
		if ((i + 1) % 10 == 0)
			cout<<endl;
	}
	if (n % 10 != 0)
		cout << endl;
	cout<<"分数与名次的对应关系为:\n"<<endl;
	for (int i = 100; i >= 0; --i)
		if (chengjibiao[i] > 0)
		{
			for (int j = chengjibiao[i]; j > 0; --j)
				cout << i << " " << cixu + 1<<endl;
			cixu += chengjibiao[i];
		}

	return 0;
}