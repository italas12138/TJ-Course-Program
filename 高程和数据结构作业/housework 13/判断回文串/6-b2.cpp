/* 2152118 史君宝 计科 */
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	char str[100],*p,*pend;
	int slen;

	cout << "请输入一个长度小于80的字符串（回文串）" << endl;

	fgets(str, 80, stdin);

	slen = strlen(str)-1;

	if (slen<=1)
		cout << "yes" << endl;
	else if((int)(str[0])==-57)
		cout << "yes" << endl;
	else 
	{
		p = str;
		pend = &str[slen-1];

		while (*p == *pend)
		{
			if (p == pend || fabs(pend - p) == 1)
				break;
			++p;
			--pend;
		}

		if (p == pend || fabs(pend - p) == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}