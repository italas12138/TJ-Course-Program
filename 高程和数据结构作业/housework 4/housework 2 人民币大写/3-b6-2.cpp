/* 2152118 �ƿ� ʷ���� */

#include <iostream>
using namespace std;

int main()
{
	cout << "������[0-100��)֮�������:" << endl;
	double m;
	cin >> m;
	cout << "��д�����:"<<endl;
	int a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, b, c;
	a10 = m / 1e9;
	m -= a10 * 1e9;
	a9 = m / 1e8;
	m -= a9 * 1e8;
	a8 = m / 1e7;
	m -= a8 * 1e7;
	a7 = m / 1e6;
	m -= a7 * 1e6;
	a6 = m / 1e5;
	m -= a6 * 1e5;
	a5 = m / 1e4;
	m -= a5 * 1e4;
	a4 = m / 1e3;
	m -= a4 * 1e3;
	a3 = m / 1e2;
	m -= a3 * 1e2;
	a2 = m / 10;
	m -= a2 * 10;
	a1 = int(m);
	m -= a1;
	b = int(m / 0.1 + 0.05);
	m -= b * 0.1;
	c = int(m / 0.01 + 0.005);
	switch (a10) 
	{
	    case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	switch (a9) 
	{
	    case 0:
			if(a10!=0)
			    cout << "��";
			break;
	    case 1:
		    cout << "Ҽ��";
		    break;
	    case 2:
		    cout << "����";
		    break;
	    case 3:
		    cout << "����";
		    break;
	    case 4:
		    cout << "����";
		    break;
	    case 5:
		    cout << "����";
		    break;
	    case 6:
		    cout << "½��";
		    break;
	    case 7:
		    cout << "����";
		    break;
	    case 8:
		    cout << "����";
		    break;
	    case 9:
		    cout << "����";
		    break;
	}
	switch (a8)
	{
	    case 0:
		    if ((a10||a9) && a8 + a7 + a6 + a5 > 0)
			    cout << "��";
		    break;
	    case 1:
		    cout << "ҼǪ";
		    break;
	    case 2:
		    cout << "��Ǫ";
		    break;
	    case 3:
		    cout << "��Ǫ";
		    break;
	    case 4:
		    cout << "��Ǫ";
		    break;
	    case 5:
		    cout << "��Ǫ";
		    break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
	}
	switch (a7) 
	{
	    case 0:
		    if (a8 != 0&&a7+a6+a5>0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
	}
	switch (a6) 
	{
	    case 0:
			if (a7 != 0&&a6+a5>0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	switch (a5) 
	{
	    case 0:
			if (a8 + a7 + a6 + a5 > 0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
	}
	switch (a4) 
	{
	    case 0:
			if (a10 + a9 + a8 + a7 + a6 + a5 > 0 && a4 + a3 + a2 + a1 > 0)
				cout << "��";
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
	}
	switch (a3)
	{
	    case 0:
			if (a4 != 0&&a3+a2+a1>0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
	}
	switch (a2) 
	{
	    case 0:
			if (a3 != 0&&a2+a1>0)
				cout << "��";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	switch (a1) 
	{
	    case 0:
			if(a10+a9+a8+a7+a6+a5+a4+a3+a2>0)
			    cout << "Բ";
			else if(b+c==0)
				cout << "��Բ";
			break;
		case 1:
			cout << "ҼԲ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 9:
			cout << "��Բ";
			break;
	}
	switch (b) 
	{
	    case 0:
			if (c != 0)
				if (a10 + a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 > 0)
					cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 9:
			cout << "����";
			break;
	}
	switch (c)
	{
	    case 0:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 9:
			cout << "����";
			break;
	}
	cout << endl;

	return 0;
}