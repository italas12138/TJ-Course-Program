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

typedef struct
{
	stu *student;
	int length;
	int listsize;
}sqliststu;

typedef struct
{
	cour *course;
	int length;
	int listsize;
}sqlistcourse;

int initsqliststu(sqliststu &xuesheng)
{
	xuesheng.student = (stu*)malloc(sqlistinitsize * sizeof(stu));
	if (!xuesheng.student)
		return -1;
	xuesheng.length = 0;
	xuesheng.listsize = sqlistinitsize;
	return 0;
}

int initsqlistcourse(sqlistcourse &kecheng)
{
	kecheng.course = (cour*)malloc(sqlistinitsize * sizeof(cour));
	if (!kecheng.course)
		return -1;
	kecheng.length = 0;
	kecheng.listsize = sqlistinitsize;
	return 0;
}

int sqliststuinsert(sqliststu &xuesheng,int i,stu e)
{
	if (i<1 || i>xuesheng.length + 1)
		return -1;
	if (xuesheng.length >= xuesheng.listsize)
	{
		stu* newstudent;
		newstudent = (stu*)realloc(xuesheng.student, 
			(xuesheng.listsize + sqlistaddsize) * sizeof(stu));
		if (!newstudent)
			return -1;
		xuesheng.student = newstudent;
		xuesheng.listsize += sqlistaddsize;
	}
	stu *p,*q;
	p = &(xuesheng.student[i - 1]);
	for (q = &(xuesheng.student[xuesheng.length - 1]); q >= p; --q)
		*(q + 1) = *q;
	e = *p;
	++xuesheng.length;
	return 0;
}

int sqlistcourseinsert(sqlistcourse &kecheng, int j, cour f)
{
	if (j<1 || j>kecheng.length + 1)
		return -1;
	if (kecheng.length >= kecheng.listsize)
	{
		cour* newcourse;
		newcourse = (cour*)realloc(kecheng.course, (kecheng.listsize + sqlistaddsize) * sizeof(cour));
		if (!newcourse)
			return -1;
		kecheng.course = newcourse;
		kecheng.listsize += sqlistaddsize;
	}
	cour* p, * q;
	p = &(kecheng.course[j - 1]);
	for (q = &(kecheng.course[kecheng.length - 1]); q >= p; --q)
		*(q + 1) = *q;
	f = *p;
	++kecheng.length;
	return 0;
}

int sqliststudelete(sqliststu &xuesheng, int i, stu e)
{
	if (i<1 || i>xuesheng.length)
		return -1;
	stu* p, * q;
	p = &(xuesheng.student[i - 1]);
	e = *p;
	for (q = &(xuesheng.student[xuesheng.length - 1]); p<q; ++p)
		*p = *(p+1);
	--xuesheng.length;
	return 0;
}

int sqlistcoursedelete(sqlistcourse &kecheng, int j, cour f)
{
	if (j<1 || j>kecheng.length)
		return -1;
	cour * p, * q;
	p = &(kecheng.course[j - 1]);
	f = *p;
	for (q = &(kecheng.course[kecheng.length - 1]); p < q; ++p)
		*p = *(p + 1);
	--kecheng.length;
	return 0;
}

int comparestu(stu e, stu e1)
{
	if (!(strcmp(e.xingming, e1.xingming)))
		if (!(strcmp(e.xuehao, e1.xuehao)))
			if (!(strcmp(e.xingming, e1.xingbie)))
				return 0;
	return -1;
}

int comparecourse(cour f, cour f1)
{
	if (!(strcmp(f.keming, f1.keming)))
		if (!(strcmp(f.kehao, f1.kehao)))
			if (f.xuefen == f1.xuefen)
				return 0;
	return -1;
}

int locatesqliststu(sqliststu &xuesheng, stu e)
{
	int i = 1;
	while (i <= xuesheng.length && !(comparestu(e, xuesheng.student[i - 1])))
		++i;
	if (i <= xuesheng.length)
		return i;
	else
		return 0;
}

int locatesqlistcourse(sqlistcourse &kecheng, cour f)
{
	int j = 1;
	while (j <= kecheng.length && !(comparecourse(f, kecheng.course[j - 1])))
		++j;
	if (j <= kecheng.length)
		return j;
	else
		return 0;
}

int shanchuxs(sqlistcourse& kecheng,int j,char chucun[])
{
	for(int i=1;i<=kecheng.course[j-1].xueshengshu;++i)
		if (!(strcmp(kecheng.course[j - 1].xueshenghao[i - 1], chucun)))
		{
			for (int k = kecheng.course[j - 1].xueshengshu; k > i; --k)
				strcpy(kecheng.course[j - 1].xueshenghao[k - 2], kecheng.course[j - 1].xueshenghao[k - 1]);
			--kecheng.course[j - 1].xueshengshu;
		}
	return 0;
}

int shanchukc(sqliststu& xuesheng, int j, char chucun[])
{
	for (int i = 1; i <= xuesheng.student[j - 1].kechengshu; ++i)
		if (!(strcmp(xuesheng.student[j - 1].kechenghao[i - 1], chucun)))
		{
			for (int k = xuesheng.student[j - 1].kechengshu; k > i; --k)
				strcpy(xuesheng.student[j - 1].kechenghao[k - 2], xuesheng.student[j - 1].kechenghao[k - 1]);
			--xuesheng.student[j - 1].kechengshu;
		}
	return 0;
}

int main()
{
	sqliststu xuesheng;
	sqlistcourse kecheng;
	initsqliststu(xuesheng);
	initsqlistcourse(kecheng);
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
			while (xuesheng.length < xszong) 
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
				sqliststuinsert(xuesheng, xuesheng.length + 1, a);
			}
			cout << "学生已满" << endl;
			goto SHURUCAOZUO;
		}
		case '2':
		{
			cout << "输入 课名 课号 学分" << endl;
			cour b;
			while (kecheng.length < kczong)
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
				sqlistcourseinsert(kecheng, kecheng.length + 1, b);
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
				if (xuesheng.length)
					cout << "没有学生" << endl;
				if(kecheng.length)
					cout << "没有课程" << endl;
				for (m = 1; m <= xuesheng.length; ++m)
					if (!(strcmp(chu, xuesheng.student[m - 1].xuehao)))
					{
						for (n = 1; n <= kecheng.length; ++n)
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
				if (m == xuesheng.length + 1)
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
				cin >>e.xingming >> e.xuehao >> e.xingbie>>m;
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
				sqliststuinsert(xuesheng, m, e);
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
				sqlistcourseinsert(kecheng, m, f);
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
				for(m = 1; m <= xuesheng.length; ++m)
					if (!(strcmp(chucun, xuesheng.student[m - 1].xuehao)))
					{
						for (int i = 1; i <= xuesheng.student[m - 1].kechengshu; ++i)  
						{
							for (int j = 1; j <= kecheng.length; ++j)                   
								if (!(strcmp(xuesheng.student[m - 1].kechenghao[i - 1], 
									kecheng.course[j - 1].kehao)))  
								{
									shanchuxs(kecheng, j, chucun);
									sqliststudelete(xuesheng, m, e);
									cout << "删除成功" << endl;
									break;
								}
							break;
						}
						break;
					}
				if (m == xuesheng.length + 1)
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
				for (m = 1; m <= kecheng.length; ++m)
					if (!(strcmp(chucun, kecheng.course[m - 1].kehao)))
					{
						for (int i = 1; i <= kecheng.course[m - 1].xueshengshu; ++i)   
						{
							for (int j = 1; j <= xuesheng.length; ++j)                  
								if (!(strcmp(kecheng.course[m - 1].xueshenghao[i - 1], 
									xuesheng.student[j - 1].xuehao))) 
								{
									shanchukc(xuesheng, j, chucun);
									sqlistcoursedelete(kecheng, m, e);
									cout << "删除成功" << endl;
									break;
								}
							break;
						}
						break;
					}
				if (m == kecheng.length + 1)
					cout << "未找到课程信息" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '8':
		{
			cout << "输入 学号" << endl;
			char chucun[10];
			while(1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n学生信息未查找成功" << endl;
					goto SHURUCAOZUO;
				}
				int m;
				for(m=1;m<=xuesheng.length;++m)
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
				if (m == xuesheng.length + 1)
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
				for (m = 1; m <= kecheng.length; ++m)
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
				if (m ==kecheng.length + 1)
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