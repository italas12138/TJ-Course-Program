/* 2152118 �ƿ� ʷ���� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;
class stu_info {
private:
	int  stu_no=0;			//ѧ��
	char stu_name[MAX_NAME_LEN]=" ";	//����
	int courseone = 0;
	int coursetwo = 0;

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend stu_list;

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int size=0;

	/* ���������private���ݳ�Ա�ͳ�Ա���� */

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */

int stu_list::read(const char* filename, const int append)
{
	ifstream filein;
	filein.open(filename, ios::in | ios::binary);
	if (filein.is_open() == 0)
	{
		cout << filename << "�ļ���ʧ��" << endl;
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
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
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
			cout << "��ѡ" << endl;
		else
			cout << "�˿�" << endl;
	}

	cout << "===========================================================" << endl;

	return 0;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}