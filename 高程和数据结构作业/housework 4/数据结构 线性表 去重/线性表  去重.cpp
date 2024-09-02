#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[50000];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1;j<n; ++j)
			if (a[i] == a[j]) {
				for (int k = j + 1;k<n; ++k)
					a[k - 1] = a[k];
				--n;
				--j;
			}
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}