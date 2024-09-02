#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solve(int number[100][2000],int result[2000],int m,int n)
{
    int temp;
    for (int i = 0; i < n; i++)
        result[i] = number[0][i];
   
    for (int i = 0; i < n ; ++i)
    {
        for (int j = 0; j < n-1 - i; ++j)
        {
            if (result[j + 1] < result[j])
            {
                temp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = temp;
            }
        }
    }

    for (int i = 1; i < m; ++i)
    {
        priority_queue<int> pque;
        for (int j = 0; j < n; ++j)
        {
            pque.push(number[i][0] + result[j]);
        }
        for (int z = 1; z < n; z++) {
            for (int j = 0; j < n; j++) {
                if (result[j] + number[i][z] < pque.top()) {
                    pque.pop();
                    pque.push(result[j] + number[i][z]);
                }
                else {
                    break;
                }
            }
        }
        for (int j = 1; j <= n; ++j) {
            result[n - j] = pque.top();
            pque.pop();
        }
    }
}

int main() {
    int T,number[100][2000];
    cin >> T;
    for(int i=0;i<T;++i)
    {
        int n, m;
        int result[2000] = { 0 };
        cin >> m >> n;
        for (int i = 0; i < m; i++)         
            for (int j = 0; j < n; j++)          
                cin >> number[i][j];         
        
        solve(number, result,m,n);
        for (int i = 0; i < n; i++) {
            std::cout << result[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}