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
	cout << "���� ѧ������ �γ�����" << endl;
	cin >> xszong >> kczong;
	cout << "������#�����֣����в���" << endl;
	cout << " #1 ����ѧ����Ϣ ���� ���� ѧ�� �Ա�" << endl;
	cout << " #2 ����γ���Ϣ ���� ���� �κ� ѧ��" << endl;
	cout << " #3 Ϊѧ��ע��γ� ���� ѧ�� �κ�" << endl;
	cout << " #4 ����ѧ����¼ ���� ���� ѧ�� �Ա�" << endl;
	cout << " #5 ����γ̼�¼ ���� ���� �κ� ѧ��" << endl;
	cout << " #6 ɾ��ѧ����¼ ���� ѧ��" << endl;
	cout << " #7 ɾ���γ̼�¼ ���� �κ�" << endl;
	cout << " #8 ����ѧ����Ϣ ���� ѧ��" << endl;
	cout << " #9 ���ҿγ���Ϣ ���� �κ�" << endl;
	cout << " #0 �������� �˳�" << endl;
	cout << "���� # ����ÿ�β���" << endl;
	char do1[5];
	SHURUCAOZUO:
	cout << "\n�������#������" << endl;
	cin >> do1;
	switch (do1[1])
	{
		case '1':
		{
			cout << "���� ���� ѧ�� �Ա�" << endl;
			stu a;
			while (xuesheng.length < xszong) 
			{
				cin >> a.xingming >> a.xuehao >> a.xingbie;
				if (a.xingming[0] == '#')
				{
					cout << "\nѧ����Ϣδ����" << endl;
					goto SHURUCAOZUO;
				}
				if (a.xuehao[0] == '#')
				{
					cout << "\nѧ����Ϣδ����" << endl;
					goto SHURUCAOZUO;
				}
				if (a.xingbie[0] == '#')
				{
					cout << "\nѧ����Ϣδ����" << endl;
					goto SHURUCAOZUO;
				}
				sqliststuinsert(xuesheng, xuesheng.length + 1, a);
			}
			cout << "ѧ������" << endl;
			goto SHURUCAOZUO;
		}
		case '2':
		{
			cout << "���� ���� �κ� ѧ��" << endl;
			cour b;
			while (kecheng.length < kczong)
			{
				cin >> b.keming >> b.kehao >> b.xuefen;
				if (b.keming[0] == '#')
				{
					cout << "\n�γ���Ϣδ����" << endl;
					goto SHURUCAOZUO;
				}
				if (b.kehao[0] == '#')
				{
					cout << "\n�γ���Ϣδ����" << endl;
					goto SHURUCAOZUO;
				}
				if (b.xuefen[0] == '#')
				{
					cout << "\n�γ���Ϣδ����" << endl;
					goto SHURUCAOZUO;
				}
				sqlistcourseinsert(kecheng, kecheng.length + 1, b);
			}
			cout << "�γ�����" << endl;
			goto SHURUCAOZUO;
		}
		case '3':
		{
			cout << "���� ѧ�� �κ�" << endl;
			char chu[10], cun[10];
			while (1)
			{
				cin >> chu >> cun;
				if (chu[0] == '#')
				{
					cout << "\nѧ���γ�δע��ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				if (cun[0] == '#')
				{
					cout << "\nѧ���γ�δע��ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				int m, n;
				if (xuesheng.length)
					cout << "û��ѧ��" << endl;
				if(kecheng.length)
					cout << "û�пγ�" << endl;
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
								cout << "ע��ɹ�" << endl;
								break;
							}
						break;
					}
				if (m == xuesheng.length + 1)
					cout << "δ�ҵ���ؿγ�ѧ����Ϣ" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '4':
		{
			cout << "���� ���� ѧ�� �Ա� ����λ��" << endl;
			stu e;
			int m;
			while (1)
			{
				cin >>e.xingming >> e.xuehao >> e.xingbie>>m;
				if (e.xingming[0] == '#')
				{
					cout << "\nѧ����Ϣδ����ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				if (e.xuehao[0] == '#')
				{
					cout << "\nѧ����Ϣδ����ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				if (e.xingbie[0] == '#')
				{
					cout << "\nѧ����Ϣδ����ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				sqliststuinsert(xuesheng, m, e);
				cout << "����ɹ�" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '5':
		{
			cout << "���� ���� �κ� ѧ�� ����λ��" << endl;
			cour f;
			int m;
			while (1)
			{
				cin >> f.keming >> f.kehao >> f.xuefen >> m;
				if (f.keming[0] == '#')
				{
					cout << "\n�γ���Ϣδ����ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				if (f.kehao[0] == '#')
				{
					cout << "\n�γ���Ϣδ����ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				if (f.xuefen[0] == '#')
				{
					cout << "\n�γ���Ϣδ����ɹ�" << endl;
					goto SHURUCAOZUO;
				}
				sqlistcourseinsert(kecheng, m, f);
				cout << "����ɹ�" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '6':
		{
			cout << "���� ѧ��" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\nѧ����Ϣδɾ���ɹ�" << endl;
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
									cout << "ɾ���ɹ�" << endl;
									break;
								}
							break;
						}
						break;
					}
				if (m == xuesheng.length + 1)
					cout << "δ�ҵ�ѧ����Ϣ" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '7':
		{
			cout << "���� �κ�" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n�γ���Ϣδɾ���ɹ�" << endl;
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
									cout << "ɾ���ɹ�" << endl;
									break;
								}
							break;
						}
						break;
					}
				if (m == kecheng.length + 1)
					cout << "δ�ҵ��γ���Ϣ" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '8':
		{
			cout << "���� ѧ��" << endl;
			char chucun[10];
			while(1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\nѧ����Ϣδ���ҳɹ�" << endl;
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
						cout << "\n����ѧ����Ϣ�ɹ�" << endl;
						break;
					}
				if (m == xuesheng.length + 1)
					cout << "δ�ҵ�ѧ����Ϣ" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '9':
		{
			cout << "���� �κ�" << endl;
			char chucun[10];
			while (1)
			{
				cin >> chucun;
				if (chucun[0] == '#')
				{
					cout << "\n�γ���Ϣδ���ҳɹ�" << endl;
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
						cout << "\n���ҿγ���Ϣ�ɹ�" << endl;
						break;
					}
				if (m ==kecheng.length + 1)
					cout << "δ�ҵ��γ���Ϣ" << endl;
			}
			goto SHURUCAOZUO;
		}
		case '0':
		{
			cout << "���������˳�" << endl;
			return 0;
		}
	}
}