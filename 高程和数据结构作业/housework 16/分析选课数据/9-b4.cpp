/* 2152118 计科 史君宝 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list;
class stu_info {
private:
	int  stu_no=0;			//学号
	char stu_name[MAX_NAME_LEN]=" ";	//姓名
	int courseone = 0;
	int coursetwo = 0;

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	friend stu_list;

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int size=0;

	/* 允许按需加入private数据成员和成员函数 */

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */

int stu_list::read(const char* filename, const int append)
{
	ifstream filein;
	filein.open(filename, ios::in | ios::binary);
	if (filein.is_open() == 0)
	{
		cout << filename << "文件打开失败" << endl;
		return -1;
	}
	char ch;
	int num=0,i=0;
	if (append == 0)
	{
		size = 0;

		while (filein.get() != -1)
		{
			filein.seekg(-1, ios::cur);
			while ((ch = filein.get()) != '\t')
				num = 10 * num + (ch - '0');
			stu[size].stu_no = num;
			stu[size].courseone = 1;
			num = 0;

			for (i = 0; (ch = filein.get()) != '\r' && ch!= -1; ++i)
				stu[size].stu_name[i] = ch;

			if (ch != -1)
			{
				stu[size].stu_name[i] = '\0';
				ch = filein.get();
			}
			else
				stu[size].stu_name[i] = '\0';
			++size;
		}
	}
	else
	{
		bool arm = 0;
		while (filein.get() != -1)
		{
			filein.seekg(-1, ios::cur);
			num = 0;
			arm = 0;
			while ((ch = filein.get()) != '\t')
				num = 10 * num + ch - '0';
			for (int i = 0; i < size; ++i)
				if (stu[i].stu_no == num)
				{
					arm = 1;
					stu[i].coursetwo = 1;
					break;
				}
			if (arm)
			{
				for (i = 0; (ch = filein.get()) != '\r' && ch != -1; ++i);
				if (ch != -1)
					ch = filein.get();
			}
			else
			{
				stu[size].stu_no = num;
				stu[size].coursetwo = 1;
				for (i = 0; (ch = filein.get()) != '\r' && ch != -1; ++i)
					stu[size].stu_name[i] = ch;
				stu[size].stu_name[i] = '\0';
				++size;
				if (ch != -1)
					ch = filein.get();	
			}
		}
	}

	filein.close();
	return 0;
}

int stu_list::print(const char* prompt)
{
	int cixu[MAX_STU_NUM + 1];
	for (int i = 0; i < MAX_STU_NUM; ++i)
		cixu[i] = i;

	int help = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (stu[cixu[i]].stu_no > stu[cixu[j]].stu_no)
			{
				help = cixu[i];
				cixu[i] = cixu[j];
				cixu[j] = help;
			}
		}
	}

	cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << "===========================================================" << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << setiosflags(ios::left) << setw(3) << i + 1 << "  " << stu[cixu[i]].stu_no << " " << setw(16) << stu[cixu[i]].stu_name << "                 ";
		if (stu[cixu[i]].courseone == 1)
			cout << "Y";
		else
			cout<<"/";
		cout << "      ";
		if (stu[cixu[i]].courseone == 1&&stu[cixu[i]].coursetwo == 1)
			cout << "Y" << endl;
		else if(stu[cixu[i]].courseone == 0)
			cout << "补选" << endl;
		else
			cout << "退课" << endl;
	}

	cout << "===========================================================" << endl;

	return 0;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}