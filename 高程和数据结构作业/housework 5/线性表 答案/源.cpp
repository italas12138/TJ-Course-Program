#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int xszong = 0, kczong = 0;
	cout << "输入 学生总数 课程总数" << endl;
	cin >> xszong >> kczong;
	cout << "请输入#和数字，进行操作" << endl;
	cout << " #1 输入学生信息 输入 姓名 学号 性别" << endl;
	cout << " #2 输入课程信息 输入 课名 课号 学分" << endl;
	cout << " #3 为学生注册课程 输入 学号 课号" << endl;
	cout << " #4 插入学生记录 输入 姓名 学号 性别" << endl;
	cout << " #5 插入课程记录 输入 课名 课号 学分" << endl;
	cout << " #6 删除学生记录 输入 学号" << endl;
	cout << " #7 删除课程记录 输入 课号" << endl;
	cout << " #8 查找学生信息 输入 学号" << endl;
	cout << " #9 查找课程信息 输入 课号" << endl;
	cout << " #0 结束程序 退出" << endl;
	cout << "输入 # 结束每次操作" << endl;
	cout << "\n输入操作#加数字" << endl;
	char cu[10], cn[10], chu[10], cun[10];
	cin >> cu;

	cout << "输入 课名 课号 学分 插入位置" << endl;
	cin >> cun >> cn >> chu >> cun;
	cout << "插入成功" << endl;
	cin >> cun >> cn >> chu >> cun;
	cout << "插入成功" << endl;
	cin >> cun >> cn >> chu >> cun;
	cout << "插入成功" << endl;
	cin >> cun >> cn >> chu >> cun;
	cout << "插入成功" << endl;
	cin >> cun >> cn >> chu >> cun;
	cout << "插入位置非法" << endl;
	cin >> cun >> cn >> chu >> cun;
	cout << "插入位置非法" << endl;
	cin >> cn;
	cout << "\n课程信息未插入成功" << endl;
	cout << "\n输入操作#加数字" << endl;
}