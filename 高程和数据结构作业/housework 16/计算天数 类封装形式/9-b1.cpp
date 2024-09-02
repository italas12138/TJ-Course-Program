/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
	int run();

public:
	int calc_days();     //�����ǵ���ĵڼ���

	Days(int x, int y, int z)
	{
		year = x;
		month = y;
		day = z;
	}
	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */

};

 /* --- �˴��������Ա����������ʵ�� --- */

int Days::run()
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
};

int Days::calc_days()
{
	int date=0;
	bool runday;
	int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };
	runday = run();
	monthday[1] += runday;

	if (!(month >= 1 && month <= 12))
		return -1;
	if (day<1 || day>monthday[month - 1])
		return -1;

	for (int i = 0; i < month - 1; ++i)
		date += monthday[i];
	date += day;

	return date;
};


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}