#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n, x, y, m;
	char z;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char a[205] = "", b[205] = "";
		int c[405] = { 0 };
		cin >> a;
		cin >> b;
		if (a[0] =='0' || b[0] =='0') {
			cout << '0' << endl;
			continue;
		}
		x = strlen(a);
		y = strlen(b);
		for (int i = 0; i < 0.5 * x; ++i) {
			m = a[i];
			a[i] = a[x - i - 1];
			a[x - i - 1] = m;
		}
		for (int i = 0; i < 0.5 * y; ++i) {
			m = b[i];
			b[i] = b[y - i - 1];
			b[y - i - 1] = m;
		}
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				c[i + j] += (a[i] - '0') * (b[j] - '0');
		for (int i = 0; i < 400; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] = c[i] % 10;
		}
		for (m = 400; c[m] == 0; --m);
		for (int i = m; i >= 0; --i) {
			cout << c[i];
		
		}
		cout << endl;
	}
		return 0;
}
