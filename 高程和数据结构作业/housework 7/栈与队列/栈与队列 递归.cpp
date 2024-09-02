#include <iostream>
using namespace std;

long f(int n) {
    if (n == 1) 
        return 1; //停止调用
    if (n>4000&&n%100 == 0)
        cout << n << endl;
    if(n<4000&&n%1000==0)
        cout << n << endl;
    return n * f(n - 1); //调用自身
}

int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}