
#include <iostream>
using namespace std;

#define N 20005

int number[N];
int str[N];

//采用归并排序进行求解

int judge(int number[N], int left, int mid, int right);


int exchange(int number[N], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        return exchange(number, left, mid) + exchange(number, mid + 1, right) + judge(number, left, mid, right);
    }
    else
        return 0;
}

int judge(int number[N], int left, int mid, int right)
{
    int count = 0;
    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k)
    {
        if ((j > right) || (i <= mid && number[i] <= number[j]))
        {
            str[k] = number[i];
            ++i;
        }
        else
        {
            str[k] = number[j];
            ++j;
            count += mid - i + 1;
        }
    }
    for (int m = left; m <= right; ++m)
        number[m] = str[m];
    return count;
}


int main()
{
    int n,cixu=0;
    int number[N];
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; ++i)
            cin >> number[i];
        cixu = exchange(number,0,n-1);
        cout << cixu << endl;
    }

    return 0;
}