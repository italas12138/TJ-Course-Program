#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, m, na = 0, num = 0;
    double p;
    cin >> n; // 总人数
    int al, bl;
    char name[20005][10];
    char no[20005][10];
    for (int i = 0; i < n; ++i)
    {
        cin >> no[i];
        cin >> name[i];
    } // 对
    char do1[10], do2[10];
    char a[10], b[10], c[10];
    char in[10] = "insert", re[10] = "remove", ch[10] = "check", nam[10] = "name", noo[10] = "no", en[10] = "end";
    while (1)
    {
        for (int j = 0; j < 10; ++j)
            do1[j] = do2[j] = a[j] = b[j] = c[j] = ' ';
        cin >> do1;
        if (!strcmp(do1, in))
        {
            cin >> p;
            cin >> a;
            cin >> b;
            if (p <1 || p>n + 1)
                cout << "-1" << endl;
            else if(p!=int(p))
                cout << "-1" << endl;
            else
            {
                for (m = n/*100*/; m >= p; --m)
                    for (int k = 0; k < 10; ++k)
                    {
                        name[m][k] = name[m - 1][k];
                        no[m][k] = no[m - 1][k];
                    }
                cout << "0" << endl;
                strcpy(name[m], b);
                strcpy(no[m], a);
                n++;
            }
        }
        if (!strcmp(do1, re))
        {
            cin >> p;
            if (p < 1 || p>n)
                cout << "-1" << endl;
            else if (p != int(p))
                cout << "-1" << endl;
            else {
                for (int j = p; j < n; ++j)
                    for (int n = 0; n < 10; ++n)
                    {
                        name[j - 1][n] = name[j][n];
                        no[j - 1][n] = no[j][n];
                    }
                cout << "0" << endl;
                n--;
            }
        }
        if (!strcmp(do1, ch))
        {
            cin >> do2;
            if (!strcmp(do2, nam))
            {
                cin >> c;
                for (na = 0; na < n; ++na)
                    if (!strcmp(name[na], c))
                        break;
                if (na == n)
                    cout << "-1" << endl;
                else
                    cout << na + 1 << " " << no[na] << " " << name[na] << endl;
            }
            else if (!strcmp(do2, noo))
            {
                cin >> c;
                for (num = 0; num < n; ++num)
                    if (!strcmp(no[num], c))
                        break;
                if (num == n)
                    cout << "-1" << endl;
                else
                    cout << num + 1 << " " << no[num] << " " << name[num] << endl;
            }
        }
        if (!strcmp(do1, en))
        {
            cout << n << endl;
            return 0;
        }
    }
}