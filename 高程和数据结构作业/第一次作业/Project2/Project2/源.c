#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a = 1200000000000;
	cout << setiosflags(ios::scientific);
	cout << setprecision(4) << a << endl;
	return 0;
}