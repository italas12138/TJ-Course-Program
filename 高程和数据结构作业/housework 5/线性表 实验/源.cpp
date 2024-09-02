#define sqlistinitsize 1000
#define sqlistaddsize 100
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;

typedef struct stu
{
	char xingming[10];
	char xuehao[10];
	char xingbie[10];
	char kechenghao[20][10];
	int kechengshu = 0;
}stu;

typedef struct cour
{
	char kehao[10];
	char keming[10];
	char xuefen[5];
	char xueshenghao[50][10];
	int xueshengshu = 0;
}cour;

typedef struct londe
{
	stu* student;
	struct londe* next;
}linkliststu;

typedef struct lon
{
	cour* course;
	struct lon* next;
}linklistcourse;

int initlinkliststu(linkliststu& xuesheng)
{
	
}

int initlinklistcourse(linklistcourse& kecheng)
{
	
}

int linkliststuinsert(linkliststu& xuesheng, int i, stu e)
{
	
}

int linklistcourseinsert(linklistcourse& kecheng, int i, cour f)
{
	
}

int linkliststudelete(linkliststu& xuesheng, int i, stu e)
{
	
}

int linklistcoursedelete(linklistcourse& kecheng, int i, cour f)
{
	
}

int locatelinkliststu(linkliststu& xuesheng, int i,stu e)
{
	
}

int locatelinklistcoourse(linklistcourse& kecheng, int i, cour f)
{
	
}

int main()
{
	linkliststu xuesheng;
	linklistcourse kecheng;
	initlinkliststu(xuesheng);
	initlinklistcourse(kecheng);
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
	char do1[5];
SHURUCAOZUO:
	cout << "\n输入操作#加数字" << endl;
	cin >> do1;
	switch (do1[1])
	{
		case '1':
		{
			cout << "输入 姓名 学号 性别" << endl;
			stu a;
			while (kecheng.course->xueshengshu < xszong)
			{
				cin >> a.xingming >> a.xuehao >> a.xingbie;
				if (a.xingming[0] == '#')
				{
					cout << "\n学生信息未储存" << endl;
					goto SHURUCAOZUO;
				}
				if (a.xuehao[0] == '#')
				{
					cout << "\n学生信息未储存" << endl;
					goto SHURUCAOZUO;
				}
				if (a.xingbie[0] == '#')
				{
					cout << "\n学生信息未储存" << endl;
					goto SHURUCAOZUO;
				}
				linkliststuinsert(xuesheng, kecheng.course->xueshengshu + 1, a);
			}
			cout << "学生已满" << endl;
			goto SHURUCAOZUO;
		}
		case '2':
		{
			cout << "输入 课名 课号 学分" << endl;
			cour b;
			while (xuesheng.student->kechengshu < kczong)
			{
				cin >> b.keming >> b.kehao >> b.xuefen;
				if (b.keming[0] == '#')
				{
					cout << "\n课程信息未储存" << endl;
					goto SHURUCAOZUO;
				}
				if (b.kehao[0] == '#')
				{
					cout << "\n课程信息未储存" << endl;
					goto SHURUCAOZUO;
				}
				if (b.xuefen[0] == '#')
				{
					cout << "\n课程信息未储存" << endl;
					goto SHURUCAOZUO;
				}
				linklistcourseinsert(kecheng, xuesheng.student->kechengshu + 1, b);
			}
			cout << "课程已满" << endl;
			goto SHURUCAOZUO;
		}
		case '3':
		{
			cout << "输入 学号 课号" << endl;
			char chu[10], cun[10];
			while (1)
			{
				cin >> chu >> cun;
				if (chu[0] == '#')
				{
					cout << "\n学生课程未注册成功" << endl;
					goto SHURUCAOZUO;
				}
				if (cun[0] == '#')
				{
					cout << "\n学生课程未注册成功" << endl;
					goto SHURUCAOZUO;
				}
				int m, n;
				if (kecheng.course->xueshengshu)
					cout << "没有学生" << endl;
				if (xuesheng.student->kechengshu)
					cout << "没有课程" << endl;
				for (m = 1; m <= kecheng.course->xueshengshu; ++m)
					if (!(strcmp(chu, xuesheng.student[m - 1].xuehao)))
					{
						for (n = 1; n <= xuesheng.student->kechengshu; ++n)
							if (!(strcmp(cun, kecheng.course[n - 1].kehao)))
							{
								strcpy(xuesheng.student[m - 1].kechenghao
									[xuesheng.student[m - 1].kechengshu], chu);
								strcpy(kecheng.course[n - 1].xueshenghao
									[kecheng.course[n - 1].xueshengshu], cun);
								++kecheng.course[n - 1].xueshengshu;
								++xuesheng.student[m - 1].kechengshu;
								cout << "注册成功" << endl;
								break;
							}
						break;
					}
				if (m == kecheng.course->xueshengshu + 1)
					cout << "未找到相关课程学生信息" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '4':
		{
			cout << "输入 姓名 学号 性别 插入位置" << endl;
			stu e;
			int m;
			while (1)
			{
				cin >> e.xingming >> e.xuehao >> e.xingbie >> m;
				if (e.xingming[0] == '#')
				{
					cout << "\n学生信息未插入成功" << endl;
					goto SHURUCAOZUO;
				}
				if (e.xuehao[0] == '#')
				{
					cout << "\n学生信息未插入成功" << endl;
					goto SHURUCAOZUO;
				}
				if (e.xingbie[0] == '#')
				{
					cout << "\n学生信息未插入成功" << endl;
					goto SHURUCAOZUO;
				}
				linkliststuinsert(xuesheng, m,e);
				cout << "插入成功" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '5':
		{
			cout << "输入 课名 课号 学分 插入位置" << endl;
			cour f;
			int m;
			while (1)
			{
				cin >> f.keming >> f.kehao >> f.xuefen >> m;
				if (f.keming[0] == '#')
				{
					cout << "\n课程信息未插入成功" << endl;
					goto SHURUCAOZUO;
				}
				if (f.kehao[0] == '#')
				{
					cout << "\n课程信息未插入成功" << endl;
					goto SHURUCAOZUO;
				}
				if (f.xuefen[0] == '#')
				{
					cout << "\n课程信息未插入成功" << endl;
					goto SHURUCAOZUO;
				}
				linklistcourseinsert(kecheng, m, f);
				cout << "插入成功" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '6':
		{
			cout << "输入 学号" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n学生信息未删除成功" << endl;
					goto SHURUCAOZUO;
				}
				int m;
				stu e;
				for (m = 1; m <= kecheng.course->xueshengshu; ++m)
					if (!(strcmp(chucun, xuesheng.student[m - 1].xuehao)))
					{
						for (int i = 1; i <= xuesheng.student[m - 1].kechengshu; ++i)  
						{
							for (int j = 1; j <= xuesheng.student->kechengshu; ++j)                  
								if (!(strcmp(xuesheng.student[m - 1].kechenghao[i - 1],
									kecheng.course[j - 1].kehao)))   
								{
									linkliststudelete(xuesheng, m, e);
									cout << "删除成功" << endl;
									break;
								}
							break;
						}
						break;
					}
				if (m == kecheng.course->xueshengshu + 1)
					cout << "未找到学生信息" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '7':
		{
			cout << "输入 课号" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n课程信息未删除成功" << endl;
					goto SHURUCAOZUO;
				}
				int m;
				cour e;
				for (m = 1; m <= kecheng.course->xueshengshu; ++m)
					if (!(strcmp(chucun, kecheng.course[m - 1].kehao)))
					{
						for (int i = 1; i <= kecheng.course[m - 1].xueshengshu; ++i)
						{
							for (int j = 1; j <= kecheng.course->xueshengshu; ++j)                  
								if (!(strcmp(kecheng.course[m - 1].xueshenghao[i - 1],
									xuesheng.student[j - 1].xuehao)))    
								{
									linklistcoursedelete(kecheng, m, e);
									cout << "删除成功" << endl;
									break;
								}
							break;
						}
						break;
					}
				if (m == xuesheng.student->kechengshu + 1)
					cout << "未找到课程信息" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '8':
		{
			cout << "输入 学号" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n学生信息未查找成功" << endl;
					goto SHURUCAOZUO;
				}
				int m;
				for (m = 1; m <= kecheng.course->xueshengshu; ++m)
					if (!(strcmp(chucun, xuesheng.student[m - 1].xuehao)))
					{
						cout << xuesheng.student[m - 1].xingming << endl;
						cout << xuesheng.student[m - 1].xuehao << endl;
						cout << xuesheng.student[m - 1].xingbie << endl;
						for (int n = 1; n <= xuesheng.student[m - 1].kechengshu; ++n)
							cout << xuesheng.student[m - 1].kechenghao[n - 1] << " ";
						cout << "\n查找学生信息成功" << endl;
						break;
					}
				if (m == kecheng.course->xueshengshu + 1)
					cout << "未找到学生信息" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '9':
		{
			cout << "输入 课号" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n课程信息未查找成功" << endl;
					goto SHURUCAOZUO;
				}
				int m;
				for (m = 1; m <= xuesheng.student->kechengshu; ++m)
					if (!(strcmp(chucun, kecheng.course[m - 1].kehao)))
					{
						cout << kecheng.course[m - 1].keming << endl;
						cout << kecheng.course[m - 1].kehao << endl;
						cout << kecheng.course[m - 1].xuefen << endl;
						for (int n = 1; n <= kecheng.course[m - 1].xueshengshu; ++n)
							cout << kecheng.course[m - 1].xueshenghao[n - 1] << " ";
						cout << "\n查找课程信息成功" << endl;
						break;
					}
				if (m == xuesheng.student->kechengshu + 1)
					cout << "未找到课程信息" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '0':
		{
			cout << "结束程序，退出" << endl;
			return 0;
		}
	}
}
