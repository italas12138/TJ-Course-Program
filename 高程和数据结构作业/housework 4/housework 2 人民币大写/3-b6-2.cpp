/* 2152118 ¼Æ¿Æ Ê·¾ý±¦ */

#include <iostream>
using namespace std;

int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;
	double m;
	cin >> m;
	cout << "´óÐ´½á¹ûÊÇ:"<<endl;
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
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
	}
	switch (a9) 
	{
	    case 0:
			if(a10!=0)
			    cout << "ÒÚ";
			break;
	    case 1:
		    cout << "Ò¼ÒÚ";
		    break;
	    case 2:
		    cout << "·¡ÒÚ";
		    break;
	    case 3:
		    cout << "ÈþÒÚ";
		    break;
	    case 4:
		    cout << "ËÁÒÚ";
		    break;
	    case 5:
		    cout << "ÎéÒÚ";
		    break;
	    case 6:
		    cout << "Â½ÒÚ";
		    break;
	    case 7:
		    cout << "ÆâÒÚ";
		    break;
	    case 8:
		    cout << "°ÆÒÚ";
		    break;
	    case 9:
		    cout << "¾ÁÒÚ";
		    break;
	}
	switch (a8)
	{
	    case 0:
		    if ((a10||a9) && a8 + a7 + a6 + a5 > 0)
			    cout << "Áã";
		    break;
	    case 1:
		    cout << "Ò¼Çª";
		    break;
	    case 2:
		    cout << "·¡Çª";
		    break;
	    case 3:
		    cout << "ÈþÇª";
		    break;
	    case 4:
		    cout << "ËÁÇª";
		    break;
	    case 5:
		    cout << "ÎéÇª";
		    break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
	}
	switch (a7) 
	{
	    case 0:
		    if (a8 != 0&&a7+a6+a5>0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
	}
	switch (a6) 
	{
	    case 0:
			if (a7 != 0&&a6+a5>0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
	}
	switch (a5) 
	{
	    case 0:
			if (a8 + a7 + a6 + a5 > 0)
				cout << "Íò";
			break;
		case 1:
			cout << "Ò¼Íò";
			break;
		case 2:
			cout << "·¡Íò";
			break;
		case 3:
			cout << "ÈþÍò";
			break;
		case 4:
			cout << "ËÁÍò";
			break;
		case 5:
			cout << "ÎéÍò";
			break;
		case 6:
			cout << "Â½Íò";
			break;
		case 7:
			cout << "ÆâÍò";
			break;
		case 8:
			cout << "°ÆÍò";
			break;
		case 9:
			cout << "¾ÁÍò";
			break;
	}
	switch (a4) 
	{
	    case 0:
			if (a10 + a9 + a8 + a7 + a6 + a5 > 0 && a4 + a3 + a2 + a1 > 0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
	}
	switch (a3)
	{
	    case 0:
			if (a4 != 0&&a3+a2+a1>0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
	}
	switch (a2) 
	{
	    case 0:
			if (a3 != 0&&a2+a1>0)
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
	}
	switch (a1) 
	{
	    case 0:
			if(a10+a9+a8+a7+a6+a5+a4+a3+a2>0)
			    cout << "Ô²";
			else if(b+c==0)
				cout << "ÁãÔ²";
			break;
		case 1:
			cout << "Ò¼Ô²";
			break;
		case 2:
			cout << "·¡Ô²";
			break;
		case 3:
			cout << "ÈþÔ²";
			break;
		case 4:
			cout << "ËÁÔ²";
			break;
		case 5:
			cout << "ÎéÔ²";
			break;
		case 6:
			cout << "Â½Ô²";
			break;
		case 7:
			cout << "ÆâÔ²";
			break;
		case 8:
			cout << "°ÆÔ²";
			break;
		case 9:
			cout << "¾ÁÔ²";
			break;
	}
	switch (b) 
	{
	    case 0:
			if (c != 0)
				if (a10 + a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 > 0)
					cout << "Áã";
			break;
		case 1:
			cout << "Ò¼½Ç";
			break;
		case 2:
			cout << "·¡½Ç";
			break;
		case 3:
			cout << "Èþ½Ç";
			break;
		case 4:
			cout << "ËÁ½Ç";
			break;
		case 5:
			cout << "Îé½Ç";
			break;
		case 6:
			cout << "Â½½Ç";
			break;
		case 7:
			cout << "Æâ½Ç";
			break;
		case 8:
			cout << "°Æ½Ç";
			break;
		case 9:
			cout << "¾Á½Ç";
			break;
	}
	switch (c)
	{
	    case 0:
			cout << "Õû";
			break;
		case 1:
			cout << "Ò¼·Ö";
			break;
		case 2:
			cout << "·¡·Ö";
			break;
		case 3:
			cout << "Èþ·Ö";
			break;
		case 4:
			cout << "ËÁ·Ö";
			break;
		case 5:
			cout << "Îé·Ö";
			break;
		case 6:
			cout << "Â½·Ö";
			break;
		case 7:
			cout << "Æâ·Ö";
			break;
		case 8:
			cout << "°Æ·Ö";
			break;
		case 9:
			cout << "¾Á·Ö";
			break;
	}
	cout << endl;

	return 0;
}