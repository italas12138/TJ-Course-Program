#include <iostream>
using namespace std;

#define maxsize 1000

int nums[maxsize], queries[maxsize], answer[maxsize];

int main()
{
	int m, n;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	for (int i = 0; i < m; ++i)
		cin >> queries[i];

	int help;

	for (int i = n; i > 0; --i)
	{
		for(int j=0;j<i-1;++j)
			if (nums[j] > nums[j + 1])
			{
				help = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = help;
			}
	}


	int sum=0, number=0;

	for (int i = 0; i < m; ++i)
	{
		if (sum <= queries[i])
		{
			while (sum + nums[number] <= queries[i]&&number<n)
			{
				sum += nums[number];
				++number;
			}
		}
		else
		{
			--number;
			sum -= nums[number];
			while (sum > queries[i] && number != 0)
			{
				--number;
				sum -= nums[number];
			}
		}
		cout << number << " ";
	}
	cout << endl;
	
	return 0;

}