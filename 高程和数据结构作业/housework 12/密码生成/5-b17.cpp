/* 计科 2152118 史君宝 */

#include <iostream>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

void randnum(int number, int codenew[4])
{
	int suiji;
	for (int i = 0; i < (number - codenew[0] - codenew[1] - codenew[2] - codenew[3]);
		++i)
	{
		suiji = rand() % 4;
		if (suiji == 0)
			++codenew[0];
		if (suiji == 1)
			++codenew[1];
		if (suiji == 2)
			++codenew[2];
		if (suiji == 3)
			++codenew[3];
		++number;
	}

	return;
}

void CreateCode(bool arc, int number, int code[4], int codenew[4], char chucun[17])
{
	for (int i = 0; i < 4; ++i)
		codenew[i] = code[i];
	if (arc == 0)
		randnum(number, codenew);
	for (int i = 0; i < codenew[0]; ++i)
		chucun[i] = rand() % 26 + 'A';
	for (int i = 0; i < codenew[1]; ++i)
		chucun[codenew[0] + i] = rand() % 26 + 'a';
	for (int i = 0; i < codenew[2]; ++i)
		chucun[codenew[0] + codenew[1] + i] = rand() % 10 + '0';
	for (int i = 0; i < codenew[3]; ++i)
		chucun[codenew[0] + codenew[1] + codenew[2] + i] = other[rand() % 15];
	chucun[number] = '\0';

	return;
}

void OutputCode(int number, int codenew[4], char chucun[17])
{
	int fuzhu;
	int zero, one, two, three;
	zero = one = two = three = 0;
	for (int i = 0; i < number; ++i)
	{
		fuzhu = rand() % 4;
		while ((fuzhu == 0 && zero == codenew[0]) || (fuzhu == 1 && one == codenew[1]) ||
			(fuzhu == 2 && two == codenew[2]) || (fuzhu == 3 && three == codenew[3]))
			fuzhu = rand() % 4;
		if (fuzhu == 0 && zero < codenew[0])
		{
			cout << chucun[zero];
			++zero;
		}
		if (fuzhu == 1 && one < codenew[1])
		{
			cout << chucun[codenew[0] + one];
			++one;
		}
		if (fuzhu == 2 && two < codenew[2])
		{
			cout << chucun[codenew[0] + codenew[1] + two];
			++two;
		}
		if (fuzhu == 3 && three < codenew[3])
		{
			cout << chucun[codenew[0] + codenew[1] + codenew[2] + three];
			++three;
		}
	}
	return;
}

int main()
{
	srand((unsigned)time(NULL));
	int number, code[4];
	bool arc = 1;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， ";
	cout << "小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> number >> code[0] >> code[1] >> code[2] >> code[3];

	if (cin.good() == 0)
	{
		cout << "输入非法" << endl;
		return 0;
	}

	if (number < 12 || number > 16)
	{
		cout << "密码长度[" << number << "]不正确" << endl;
		return 0;
	}

	if (code[0] < 2 || code[0]>number)
	{
		cout << "大写字母个数[" << code[0] << "]不正确" << endl;
		return 0;
	}

	if (code[1] < 2 || code[1]>number)
	{
		cout << "小写字母个数[" << code[1] << "]不正确" << endl;
		return 0;
	}

	if (code[2] < 2 || code[2]>number)
	{
		cout << "数字个数[" << code[2] << "]不正确" << endl;
		return 0;
	}

	if (code[3] < 2 || code[3]>number)
	{
		cout << "其它符号个数[" << code[3] << "]不正确" << endl;
		return 0;
	}

	if (code[0] + code[1] + code[2] + code[3] > number)
	{
		cout << "所有字符类型之和[" << code[0] << "+" << code[1] << "+" << code[2]
			<< "+" << code[3] << "]大于总密码长度[" << number << "]" << endl;
		return 0;
	}

	cout << number << " " << code[0] << " " << code[1] << " " << code[2]
		<< " " << code[3] << endl;

	if (code[0] + code[1] + code[2] + code[3] < number)
		arc = 0;

	char chucun[17];
	int codenew[4];
	for (int i = 0; i < 10; ++i)
	{
		CreateCode(arc, number, code, codenew, chucun);

		OutputCode(number, codenew, chucun);
		cout << endl;
	}

	return 0;
}