/* 2152118 史君宝 计科 */
#include <iostream>
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
string result;

void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
			{
				result.push_back(chnstr[0]);
				result.push_back(chnstr[1]);
			}
			break;
		case 1:
		{
			result.push_back(chnstr[2]);
			result.push_back(chnstr[3]);
		}
			break;
		case 2:
		{
			result.push_back(chnstr[4]);
			result.push_back(chnstr[5]);
		}
			break;
		case 3:
		{
			result.push_back(chnstr[6]);
			result.push_back(chnstr[7]);
		}
			break;
		case 4:
		{
			result.push_back(chnstr[8]);
			result.push_back(chnstr[9]);
		}
			break;
		case 5:
		{
			result.push_back(chnstr[10]);
			result.push_back(chnstr[11]);
		}
			break;
		case 6:
		{
			result.push_back(chnstr[12]);
			result.push_back(chnstr[13]);
		}
			break;
		case 7:
		{
			result.push_back(chnstr[14]);
			result.push_back(chnstr[15]);
		}
			break;
		case 8:
		{
			result.push_back(chnstr[16]);
			result.push_back(chnstr[17]);
		}
			break;
		case 9:
		{
			result.push_back(chnstr[18]);
			result.push_back(chnstr[19]);
		}
			break;
		default:
			cout << "error" << endl;
			break;
	}
}

int main()
{
	double renminbi;
	int ling = 0;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, ge, jiao, fen;

	cout << "请输入[0-100亿)之间的数字:" << endl;
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
		result += "拾";
	}
	daxie(yi, ling);
	if (shiyi || yi)
		result += "亿";
	if ((shiyi || yi) && qianwan + baiwan + shiwan + wan > 0)
		ling = 1;
	daxie(qianwan, ling);
	ling = 0;
	if (qianwan)
		result += "仟";
	if (qianwan != 0 && baiwan + shiwan + wan > 0)
		ling = 1;
	daxie(baiwan, ling);
	ling = 0;
	if (baiwan)
		result += "佰";
	if (baiwan != 0 && shiwan + wan > 0)
		ling = 1;
	daxie(shiwan, ling);
	ling = 0;
	if (shiwan)
		result += "拾";
	daxie(wan, ling);
	if (qianwan + baiwan + shiwan + wan > 0)
		result += "万";
	if (shiyi + yi + qianwan + baiwan + shiwan + wan > 0 && qian + bai + shi + ge > 0)
		ling = 1;
	daxie(qian, ling);
	ling = 0;
	if (qian)
		result += "仟";
	if (qian != 0 && bai + shi + ge > 0)
		ling = 1;
	daxie(bai, ling);
	ling = 0;
	if (bai)
		result += "佰";
	if (bai != 0 && shi + ge > 0)
		ling = 1;
	daxie(shi, ling);
	ling = 0;
	if (shi)
		result += "拾";
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian
		+ bai + shi > 0)
	{
		ling = 0;
		daxie(ge, ling);
		result += "圆";
	}
	else if (jiao + fen == 0)
	{
		ling = 1;
		daxie(ge, ling);
		result += "圆";
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
		result += "角";
	}
	if (fen)
	{
		daxie(fen, ling);
		result += "分";
	}
	else
		result += "整";

	cout << result << endl;

	return 0;
}