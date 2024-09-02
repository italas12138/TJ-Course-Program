
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;



class Solution {
public:
    int solve(std::vector<vector<std::string>>& old_chart, std::vector<std::vector<std::string>>& new_chart) {

        int n = old_chart.size();
        int m = old_chart[0].size();
        int check_chart[100000];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int name = 0;
                for (int k = 0; k < (int)old_chart[i][j].size(); k++)
                    name = name * 26 + old_chart[i][j][k] - 'a' + 1;

                check_chart[name] = i * m + j;
            }
        }
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (old_chart[i][j] != new_chart[i][j])
                {
                    int idone = 0, idtwo = 0;
                    for (int k = 0; k < (int)new_chart[i][j].size(); k++)
                        idone = idone * 26 + new_chart[i][j][k] - 'a' + 1;

                    for (int k = 0; k < (int)old_chart[i][j].size(); k++)
                        idtwo = idtwo * 26 + old_chart[i][j][k] - 'a' + 1;


                    old_chart[check_chart[idone] / m][check_chart[idone] % m] = old_chart[i][j];
                    old_chart[i][j] = new_chart[i][j];
                    check_chart[idtwo] = check_chart[idone];
                    check_chart[idone] = i * m + j;
                    ++count;

                }
            }
        }

        return count;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::string>> old_chart(n, std::vector<std::string>(m));
    std::vector<std::vector<std::string>> new_chart(n, std::vector<std::string>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> old_chart[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> new_chart[i][j];
        }
    }

    Solution s;
    std::cout << s.solve(old_chart, new_chart) << std::endl;
    return true;
}