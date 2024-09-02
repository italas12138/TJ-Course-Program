#include <iostream>
#include <iomanip>
using namespace std;

//KFC ���� �ṹ������
struct KFC
{
	char number;
	char name[20];
	double price;
};

//SPECIAL �Żݲ� �ṹ������
struct SPECIAL
{
	char menu[20];
	char name[100];
	double price;
};

//�ж��Ƿ���A-Z�������ִ�Сд����������
char judge_AZ(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch;
	if (ch - 32 >= 'A' && ch - 32 <= 'Z')
		return ch-32;
	return ' ';
}

//�Żݲ�������������ṹ���е��Żݲ���Ϣ�������
void special_output(const struct SPECIAL special[], const struct KFC list[], int number[][26])
{
	int k = 0;
	while (special[k].price != 0)
	{
		cout << special[k].name << "=";

		int i = 0, j = 0;

		while (special[k].menu[i] != '\0')
		{
			++number[k][judge_AZ(special[k].menu[i]) - 'A'];
			++i;
		}

		for (i = 0; i < 26; ++i)
			if (number[k][i] > 0)
				++j;

		for (i = 0; i < 26; ++i)
		{
			if (number[k][i] > 0)
			{
				cout << list[i].name;
				if (number[k][i] > 1)
					cout << "*" << number[k][i];
				if (j - 1)
				{
					cout << "+";
					--j;
				}
			}
		}
		cout << "=" << special[k].price << endl;
		++k;
	}
}

//���������������˿͵�Ĳ����
void menu_output(const struct KFC list[], int order_number[])
{
	int i = 0, j = 0;

	for (i = 0; i < 26; ++i)
		if (order_number[i] > 0)
			++j;

	for (i = 0; i < 26; ++i)
	{
		if (order_number[i] > 0)
		{
			cout << list[i].name;
			if (order_number[i] > 1)
				cout << "*" << order_number[i];
			if (j - 1)
			{
				cout << "+";
				--j;
			}
		}
	}
}

//�Żݼ��㺯����������п����ŻݵĲ��ּ������
void special_count(int order_number[26],double &price,const struct SPECIAL special[],int number[][26])
{
	bool ram = 1;
	for (int i = 0; special[i].price != 0; ++i)
	{
		while (ram)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (order_number[j] < number[i][j])
				{
					ram = 0;
					break;
				}		
			}
			if (ram)
			{
				for (int j = 0; j < 26; ++j)
					order_number[j] -= number[i][j];
				price += special[i].price;
			}
		}
		ram = 1;
	}
}


const struct KFC list[] = {
	{'A', "�������ȱ�",         18.5},
	{'B', "���༦�ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "�������׻�",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ٽ��޹Ǵ���(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "�������װ�",         9.0},
	{'U', "��ʽ��̢",           8.0},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};


const struct SPECIAL special[] = {
		//{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};

int main()
{
	system("mode con cols=120 lines=35");

	while (1)
	{

		cout << "=============================================================" << endl;
		cout << "                      KFC 2021�＾�˵�" << endl;
		cout << "=============================================================" << endl;

		for (int i = 0; list[i].number != '\0'; ++i)
		{
			cout << " " << list[i].number << " " << setw(20) << setiosflags(ios::left)
				 << list[i].name << setw(7) << list[i].price;
			if (i % 2 == 0)
				cout << "|  ";
			else
				cout << endl;
		}


		cout << endl << "���Ż���Ϣ����" << endl;

		int number[10][26] = { 0 };

		special_output(special, list, number);

		cout << endl << "���������˵������" << endl;
		cout << "ANV = �������ȱ�+����(С)+���¿���(С) / akaak = �������ȱ�*3+��������*2" << endl;
		cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;

		char order[100], getch;
		int order_number[26] = { 0 };
		double price = 0;

		cout << endl << "��㵥:";
		fgets(order, 80, stdin);

		if (order[0] == '0')
			return 0;

		if (order[0] != '\n')
		{
			for (int i = 0; order[i] != '\0'; ++i)
				++order_number[judge_AZ(order[i]) - 'A'];

			cout << "���ĵ��=";

			menu_output(list, order_number);

			special_count(order_number, price, special, number);

			for (int i = 0; i < 26; ++i)
			{
				while (order_number[i])
				{
					--order_number[i];
					price += list[i].price;
				}
			}

			cout << endl << "���ƣ�" << price << "Ԫ" << endl;

			cout << "�㵥��ɣ������������." << endl;

			getch = getchar();
		}

		system("cls");
	}

	return 0;

}