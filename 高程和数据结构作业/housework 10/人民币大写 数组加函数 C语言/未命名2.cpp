/* 2152118 史君宝 计科 */
#define _CRT_SECURE_NO_WARNINGS  //VS需要
#include <stdio.h>

#include <string.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖拾";
char result[256];

void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				strncat(result, &chnstr[0], 2);
			break;
		case 1:
			strncat(result, &chnstr[2], 2);
			break;
		case 2:
			strncat(result, &chnstr[4], 2);
			break;
		case 3:
			strncat(result, &chnstr[6], 2);
			break;
		case 4:
			strncat(result, &chnstr[8], 2);
			break;
		case 5:
			strncat(result, &chnstr[10], 2);
			break;
		case 6:
			strncat(result, &chnstr[12], 2);
			break;
		case 7:
			strncat(result, &chnstr[14], 2);
			break;
		case 8:
			strncat(result, &chnstr[16], 2);
			break;
		case 9:
			strncat(result, &chnstr[18], 2);
			break;
		default:
			printf("error\n");
			break;
	}
}

int main()
{
	double renminbi;
	int ling = 0;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, ge, jiao, fen;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &renminbi);
	shiyi = (int)(renminbi / 1e9);
	renminbi -= shiyi * 1e9;
	yi = (int)(renminbi / 1e8);
	renminbi -= yi * 1e8;
	qianwan = (int)(renminbi / 1e7);
	renminbi -= qianwan * 1e7;
	baiwan = (int)(renminbi / 1e6);
	renminbi -= baiwan * 1e6;
	shiwan = (int)(renminbi / 1e5);
	renminbi -= shiwan * 1e5;
	wan = (int)(renminbi / 1e4);
	renminbi -= wan * 1e4;
	qian = (int)(renminbi / 1e3);
	renminbi -= qian * 1e3;
	bai = (int)(renminbi / 1e2);
	renminbi -= bai * 1e2;
	shi = (int)(renminbi / 10);
	renminbi -= shi * 10;
	ge = (int)(renminbi);
	renminbi -= ge;
	jiao = (int)(renminbi / 0.1 + 0.05);
	renminbi -= jiao * 0.1;
	fen = (int)(renminbi / 0.01 + 0.005);
	if (shiyi)
	{
		daxie(shiyi, ling);
		strcat(result, "拾");
	}
	daxie(yi, ling);
	if (shiyi || yi)
		strcat(result, "亿");
	if ((shiyi || yi) && qianwan + baiwan + shiwan + wan > 0)
		ling = 1;
	daxie(qianwan, ling);
	ling = 0;
	if (qianwan)
		strcat(result, "仟");
	if (qianwan != 0 && baiwan + shiwan + wan > 0)
		ling = 1;
	daxie(baiwan, ling);
	ling = 0;
	if (baiwan)
		strcat(result, "佰");
	if (baiwan != 0 && shiwan + wan > 0)
		ling = 1;
	daxie(shiwan, ling);
	ling = 0;
	if (shiwan)
		strcat(result, "拾");
	daxie(wan, ling);
	if (qianwan + baiwan + shiwan + wan > 0)
		strcat(result, "万");
	if (shiyi + yi + qianwan + baiwan + shiwan + wan > 0 && qian + bai + shi + ge > 0)
		ling = 1;
	daxie(qian, ling);
	ling = 0;
	if (qian)
		strcat(result, "仟");
	if (qian != 0 && bai + shi + ge > 0)
		ling = 1;
	daxie(bai, ling);
	ling = 0;
	if (bai)
		strcat(result, "佰");
	if (bai != 0 && shi + ge > 0)
		ling = 1;
	daxie(shi, ling);
	ling = 0;
	if (shi)
		strcat(result, "拾");
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian
		+ bai + shi > 0)
	{
		ling = 0;
		daxie(ge, ling);
		strcat(result, "圆");
	}
	else if (jiao + fen == 0)
	{
		ling = 1;
		daxie(ge, ling);
		strcat(result, "圆");
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
		strcat(result, "角");
	}
	if (fen)
	{
		daxie(fen, ling);
		strcat(result, "分");
	}
	else
		strcat(result, "整");

	printf("%s\n", result);

	return 0;
}


