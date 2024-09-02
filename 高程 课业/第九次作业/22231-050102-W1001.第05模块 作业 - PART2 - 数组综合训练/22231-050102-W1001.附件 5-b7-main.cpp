#include <iostream>
using namespace std;

int main()
{
 cout << "请输入9*9的矩阵，值为1-9之间" << endl;
 int sudoku[9][9];
 int offset[9][2] = { {0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };
 int temp = 0;
 for (int i = 0; i < 81; i++)
 {
  while (1)
  {
   cin >> temp;
   if (cin.fail() || !cin.good())
   {
    cin.clear();
    cin.ignore(1024, '\n');
    continue;
   }
   if (temp >= 1 && temp <= 9) {
    sudoku[i / 9][i % 9] = temp;
    break;
   }
  }
 }
 for (int t = 0; t < 9; t++)
 {
  int r[9] = { 0 };
  int c[9] = { 0 };
  int grid[9] = { 0 };
  for (int k = 0; k < 9; k++)
  {
   if (r[sudoku[t][k]-1])
   {
    cout << "不是数独的解" << endl;
    return 0;
   }
   else {
    r[sudoku[t][k]-1] = 1;
   }
   if (c[sudoku[k][t]-1])
   {
    cout << "不是数独的解" << endl;
    return 0;
   }
   else {
    c[sudoku[k][t]-1] = 1;
   }
   if (grid[sudoku[t / 3 * 3 + offset[k][0]][t % 3 * 3 + offset[k][1]]-1])
   {
    cout << "不是数独的解" << endl;
    return 0;
   }
   else {
    grid[sudoku[t / 3 * 3 + offset[k][0]][t % 3 * 3 + offset[k][1]] - 1] = 1;
   }
  }
 }
 cout << "是数独的解" << endl;
 return 0;
}
