/* 2152118 ʷ���� �ƿ� */
#include <iostream>
using namespace std;

void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	double renminbi;
	int ling = 0;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, ge, jiao, fen;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> renminbi;
	shiyi = renminbi / 1e9;
	renminbi -= shiyi * 1e9;
	yi = renminbi / 1e8;
	renminbi -= yi * 1e8;
	qianwan = renminbi / 1e7;
	renminbi -= qianwan * 1e7;
	baiwan = renminbi / 1e6;
	renminbi -= baiwan * 1e6;
	shiwan = renminbi / 1e5;
	renminbi -= shiwan * 1e5;
	wan = renminbi / 1e4;
	renminbi -= wan * 1e4;
	qian = renminbi / 1e3;
	renminbi -= qian * 1e3;
	bai = renminbi / 1e2;
	renminbi -= bai * 1e2;
	shi = renminbi / 10;
	renminbi -= shi * 10;
	ge = int(renminbi);
	renminbi -= ge;
	jiao = int(renminbi / 0.1 + 0.05);
	renminbi -= jiao * 0.1;
	fen = int(renminbi / 0.01 + 0.005);
	if (shiyi)
	{
		daxie(shiyi, ling);
		cout << "ʰ";
	}
	daxie(yi, ling);
	if (shiyi || yi)
		cout << "��";
	if ((shiyi || yi) && qianwan + baiwan + shiwan + wan > 0)
		ling = 1;
	daxie(qianwan, ling);
	ling = 0;
	if (qianwan)
		cout << "Ǫ";
	if (qianwan != 0 && baiwan + shiwan + wan > 0)
		ling = 1;
	daxie(baiwan, ling);
	ling = 0;
	if (baiwan)
		cout << "��";
	if (baiwan != 0 && shiwan + wan > 0)
		ling = 1;
	daxie(shiwan, ling);
	ling = 0;
	if (shiwan)
		cout << "ʰ";
	daxie(wan, ling);
	if (qianwan + baiwan + shiwan + wan > 0)
		cout << "��";
	if (shiyi + yi + qianwan + baiwan + shiwan + wan > 0 && qian + bai + shi + ge > 0)
		ling = 1;
	daxie(qian, ling);
	ling = 0;
	if (qian)
		cout << "Ǫ";
	if (qian != 0 && bai + shi + ge > 0)
		ling = 1;
	daxie(bai, ling);
	ling = 0;
	if (bai)
		cout << "��";
	if (bai != 0 && shi + ge > 0)
		ling = 1;
	daxie(shi, ling);
	ling = 0;
	if (shi)
		cout << "ʰ";
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian
		+ bai + shi > 0)
	{
		ling = 0;
		daxie(ge, ling);
		cout << "Բ";
	}
	else if (jiao + fen == 0)
	{
		ling = 1;
		daxie(ge, ling);
		cout << "Բ";
	}
	ling = 0;
	if (jiao == 0)
	{
		if (fen != 0)
			if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian
				+ bai + shi + ge > 0)
			{
				ling = 1;
				daxie(jiao, ling);
			}
	}
	else
	{
		daxie(jiao, ling);
		cout << "��";
	}
	if (fen)
	{
		daxie(fen, ling);
		cout << "��" << endl;
	}
	else
		cout << "��" << endl;

	return 0;
}