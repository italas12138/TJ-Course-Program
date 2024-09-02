#include <iostream>
#include <iomanip>
using namespace std;

//KFC 餐名 结构体数组
struct KFC
{
	char number;
	char name[20];
	double price;
};

//SPECIAL 优惠餐 结构体数组
struct SPECIAL
{
	char menu[20];
	char name[100];
	double price;
};

//判断是否是A-Z，不区分大小写，辅助函数
char judge_AZ(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch;
	if (ch - 32 >= 'A' && ch - 32 <= 'Z')
		return ch-32;
	return ' ';
}

//优惠餐输出函数，将结构体中的优惠餐信息输出出来
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

//点餐输出函数，将顾客点的餐输出
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

//优惠计算函数，将点餐中可以优惠的部分计算出来
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
	{'A', "香辣鸡腿堡",         18.5},
	{'B', "劲脆鸡腿堡",         18.5},
	{'C', "新奥尔良烤鸡腿堡",   19},
	{'D', "老北京鸡肉卷",       17},
	{'E', "川辣嫩牛卷",         19.5},
	{'F', "深海鳕鱼堡",         18.5},
	{'G', "吮指原味鸡(1块)",    11.5},
	{'H', "芝芝肉酥热辣脆皮鸡", 12.5},
	{'I', "新奥尔良烤翅(2块)",  12.5},
	{'J', "劲爆鸡米花",         11.5},
	{'K', "香辣鸡翅(2块)",      12.0},
	{'L', "藤椒无骨大鸡柳(2块)",12.5},
	{'M', "鲜蔬色拉",           13},
	{'N', "薯条(小)",           9},
	{'O', "薯条(中)",           12},
	{'P', "薯条(大)",           14},
	{'Q', "芙蓉蔬荟汤",         9},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         7},
	{'T', "香甜粟米棒",         9.0},
	{'U', "葡式蛋挞",           8.0},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.5},
	{'Z', "纯纯玉米饮",         11.5},
	{'\0', NULL,                0}
};


const struct SPECIAL special[] = {
		//{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
		{"BMV", "劲脆鸡腿堡超值套餐",    26},
		{"ABCGGIIKKOUWWW", "超值全家桶", 115},
		{"KIIRRJUWW", "缤纷小吃桶",      65},
		{"JJ","劲爆鸡米花(2份小)",       12.5},
		{NULL, NULL, 0}
};

int main()
{
	system("mode con cols=120 lines=35");

	while (1)
	{

		cout << "=============================================================" << endl;
		cout << "                      KFC 2021秋季菜单" << endl;
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


		cout << endl << "【优惠信息】：" << endl;

		int number[10][26] = { 0 };

		special_output(special, list, number);

		cout << endl << "【输入规则说明】：" << endl;
		cout << "ANV = 香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak = 香辣鸡腿堡*3+香辣鸡翅*2" << endl;
		cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;

		char order[100], getch;
		int order_number[26] = { 0 };
		double price = 0;

		cout << endl << "请点单:";
		fgets(order, 80, stdin);

		if (order[0] == '0')
			return 0;

		if (order[0] != '\n')
		{
			for (int i = 0; order[i] != '\0'; ++i)
				++order_number[judge_AZ(order[i]) - 'A'];

			cout << "您的点餐=";

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

			cout << endl << "共计：" << price << "元" << endl;

			cout << "点单完成，按任意键继续." << endl;

			getch = getchar();
		}

		system("cls");
	}

	return 0;

}