#include <iostream>
using namespace std;
char c[100000];
int cixu = 0;
char v,w;
char tiqu(char s[])
{
   
    w = s[cixu];
    ++cixu;
    return w;
}
int main()
{
    int s[5000] = {};
    int i = 0, j = 0, k = 0;
    int n = 0, num = 0, position = 0, p = 0, p1 = 0;
    cin >> c;
    v = tiqu(c);
    if (v == '"')
    {
        v = tiqu(c);
        if (v == '"')
            ++p;
        while (v != '"')
        {
            switch (v)
            {
                case ')':
                    ++position;
                    if (j > 0)
                        --j;
                    else
                    {
                        k = j;
                        n = position - p1 - 1;
                        p1 = position;
                        if (num < n)
                        {
                            num = n;
                            p = position - n - 1;
                        }
                    }
                    break;
                case '(':
                    ++position;
                    s[j] = position;
                    ++j;
                    break;
            }
            v = tiqu(c);
        }
    }
    if (j == 0 && p1 != position)
    {
        n = position - p1;
        if (num < n)
        {
            num = n;
            p = position - n;
        }
    }
    else if (j > 0)
    {
        n = s[k] - p1 - 1;
        if (num < n)
        {
            num = n;
            p = s[k] - n - 1;
        }
        for (int i = k + 1; i < j; ++i)
            if (s[i] - s[i - 1] - 1 > n)
                n = s[i] - s[i - 1] - 1;
        if (num < n)
        {
            num = n;
            p = s[i] - n - 1;
        }
        n = position - s[j - 1];
        if (num < n)
        {
            num = n;
            p = position - n;
        }
    }
    cout << num << " " << p << endl;
    return 0;
}