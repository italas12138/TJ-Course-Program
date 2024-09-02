/* ¼Æ¿Æ 2152118 Ê·¾ý±¦ */

#include <iostream>
using namespace std;

int CheckCode(bool arc, int number, int code[4], int codenew[4], char chucun[17])
{
	for (int i = 0; i < 4; ++i)
		codenew[i] = 0;
	cin >> chucun;
	int chucunlen;
	chucunlen = strlen(chucun);
	for (int i = 0; i < chucunlen; ++i)
	{
		if (chucun[i] >= 'A' && chucun[i] <= 'Z')
			++codenew[0];
		else if (chucun[i] >= 'a' && chucun[i] <= 'z')
			++codenew[1];
		else if (chucun[i] >= '0' && chucun[i] <= '9')
			++codenew[2];
		else 
			++codenew[3];
	}
	if (chucunlen != number)
		return 1;
	if (code[0] > codenew[0])
		return 1;
	if (code[1] > codenew[1])
		return 1;
	if (code[2] > codenew[2])
		return 1;
	if (code[3] > codenew[3])
		return 1;

	return 0;
}

int main()
{
	int number, code[4];
	bool arc = 1;

	char suggestion[100];
	char chucun[17];
	cin.getline(suggestion, 100, '\n');
	cin >> number >> code[0] >> code[1] >> code[2] >> code[3];

	if (cin.good() == 0)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	if (number < 12 || number > 16)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	if (code[0] < 2 || code[0]>number)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	if (code[1] < 2 || code[1]>number)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	if (code[2] < 2 || code[2]>number)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	if (code[3] < 2 || code[3]>number)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	if (code[0] + code[1] + code[2] + code[3] > number)
	{
		cout << "´íÎó" << endl;
		return 0;
	}

	int codenew[4];
	bool shifou = 0;
	for (int i = 0; i < 10; ++i)
	{
		shifou=CheckCode(arc, number, code, codenew, chucun);
		if (shifou == 1)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
	}

	cout << "ÕýÈ·" << endl;
	return 0;
}
