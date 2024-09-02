/* 2152118 ¼Æ¿Æ Ê·¾ý±¦ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	double m;
	scanf("%lf",&m);
	printf("´óÐ´½á¹ûÊÇ:\n");
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
	a1 = (int)(m);
	m -= a1;
	b = (int)(m / 0.1 + 0.05);
	m -= b * 0.1;
	c = (int)(m / 0.01 + 0.005);
	switch (a10) {
	    case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
	}
	switch (a9) 
	{
	    case 0:
			if (a10 != 0)
				printf("ÒÚ");
			break;
		case 1:
			printf("Ò¼ÒÚ");
			break;
		case 2:
			printf("·¡ÒÚ");
			break;
		case 3:
			printf("ÈþÒÚ");
			break;
		case 4:
			printf("ËÁÒÚ");
			break;
		case 5:
			printf("ÎéÒÚ");
			break;
		case 6:
			printf("Â½ÒÚ");
			break;
		case 7:
			printf("ÆâÒÚ");
			break;
		case 8:
			printf("°ÆÒÚ");
			break;
		case 9:
			printf("¾ÁÒÚ");
			break;
	}
	switch (a8) 
	{
	    case 0:
			if ((a10 || a9) && a8 + a7 + a6 + a5 > 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈþÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
	}
	switch (a7) 
	{
	    case 0:
			if (a8 != 0 && a7 + a6 + a5 > 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼°Û");
			break;
	    case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èþ°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
	}
	switch (a6) 
	{
		case 0:
			if (a7 != 0 && a6 + a5 > 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
	}
	switch (a5) 
	{
		case 0:
			if (a8 + a7 + a6 + a5 > 0)
				printf("Íò");
			break;
		case 1:
			printf("Ò¼Íò");
			break;
		case 2:
			printf("·¡Íò");
			break;
		case 3:
			printf("ÈþÍò");
			break;
		case 4:
			printf("ËÁÍò");
			break;
		case 5:
			printf("ÎéÍò");
			break;
		case 6:
			printf("Â½Íò");
			break;
		case 7:
			printf("ÆâÍò");
			break;
		case 8:
			printf("°ÆÍò");
			break;
		case 9:
			printf("¾ÁÍò");
			break;
	}
	switch (a4) 
	{
		case 0:
			if (a10 + a9 + a8 + a7 + a6 + a5 > 0 && a4 + a3 + a2 + a1 > 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈþÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
	}
	switch (a3) 
	{
		case 0:
			if (a4 != 0 && a3 + a2 + a1 > 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èþ°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
	}
	switch (a2) 
	{
		case 0:
			if (a3 != 0 && a2 + a1 > 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈþÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
	}
	switch (a1) 
	{
		case 0:
			if (a10 + a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 > 0)
				printf("Ô²");
			else if (b + c == 0)
				printf("ÁãÔ²");
			break;
		case 1:
			printf("Ò¼Ô²");
			break;
		case 2:
			printf("·¡Ô²");
			break;
		case 3:
			printf("ÈþÔ²");
			break;
		case 4:
			printf("ËÁÔ²");
			break;
		case 5:
			printf("ÎéÔ²");
			break;
		case 6:
			printf("Â½Ô²");
			break;
		case 7:
			printf("ÆâÔ²");
			break;
		case 8:
			printf("°ÆÔ²");
			break;
		case 9:
			printf("¾ÁÔ²");
			break;
	}
	switch (b) 
	{
		case 0:
			if (c != 0)
				if (a10 + a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 > 0)
					printf("Áã");
			break;
		case 1:
			printf("Ò¼½Ç");
			break;
		case 2:
			printf("·¡½Ç");
			break;
		case 3:
			printf("Èþ½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
			break;
	}
	switch (c) 
	{
		case 0:
			printf("Õû\n");
			break;
		case 1:
			printf("Ò¼·Ö\n");
			break;
		case 2:
			printf("·¡·Ö\n");
			break;
		case 3:
			printf("Èþ·Ö\n");
			break;
		case 4:
			printf("ËÁ·Ö\n");
			break;
		case 5:
			printf("Îé·Ö\n");
			break;
		case 6:
			printf("Â½·Ö\n");
			break;
		case 7:
			printf("Æâ·Ö\n");
			break;
		case 8:
			printf("°Æ·Ö\n");
			break;
		case 9:
			printf("¾Á·Ö\n");
			break;
	}

	return 0;
}