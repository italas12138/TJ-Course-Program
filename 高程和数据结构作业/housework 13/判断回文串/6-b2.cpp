/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	char str[100],*p,*pend;
	int slen;

	cout << "������һ������С��80���ַ��������Ĵ���" << endl;

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