/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

int main()
{
	int shuzu[40]={0};
	int a=0,n = 0,charu,cixu;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	while (1)
	{
		cin >> a;
		shuzu[n] = a;
		if (a == -1)
			break;
		++n;
	}
	if (n == 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	if (n > 19)
		n = 20;
	cout << "原数组为：" << endl;
	for (int i = 0; i < n; ++i)
		cout << shuzu[i]<<" ";
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> charu;
	for (cixu = 0; cixu< n ; ++cixu)
		if (shuzu[cixu] > charu)
			break;
	if (cixu == n)
		shuzu[cixu] = charu;
	else
	{
		for (int y = n -1; y >= cixu; --y)
			shuzu[y + 1] = shuzu[y];
		shuzu[cixu] = charu;
	}
	++n;
	cout << "插入后的数组为：" << endl;
	for (int i = 0; i < n; ++i)
		cout << shuzu[i] << " ";
	cout << endl;
	return 0;
}