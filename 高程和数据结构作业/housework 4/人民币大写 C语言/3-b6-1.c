/* 2152118 �ƿ� ʷ���� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������[0-100��)֮�������:\n");
	double m;
	scanf("%lf",&m);
	printf("��д�����:\n");
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
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
	}
	switch (a9) 
	{
	    case 0:
			if (a10 != 0)
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
	}
	switch (a8) 
	{
	    case 0:
			if ((a10 || a9) && a8 + a7 + a6 + a5 > 0)
				printf("��");
			break;
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
	}
	switch (a7) 
	{
	    case 0:
			if (a8 != 0 && a7 + a6 + a5 > 0)
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
	    case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
	}
	switch (a6) 
	{
		case 0:
			if (a7 != 0 && a6 + a5 > 0)
				printf("��");
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
	}
	switch (a5) 
	{
		case 0:
			if (a8 + a7 + a6 + a5 > 0)
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
	}
	switch (a4) 
	{
		case 0:
			if (a10 + a9 + a8 + a7 + a6 + a5 > 0 && a4 + a3 + a2 + a1 > 0)
				printf("��");
			break;
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
	}
	switch (a3) 
	{
		case 0:
			if (a4 != 0 && a3 + a2 + a1 > 0)
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
	}
	switch (a2) 
	{
		case 0:
			if (a3 != 0 && a2 + a1 > 0)
				printf("��");
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
	}
	switch (a1) 
	{
		case 0:
			if (a10 + a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 > 0)
				printf("Բ");
			else if (b + c == 0)
				printf("��Բ");
			break;
		case 1:
			printf("ҼԲ");
			break;
		case 2:
			printf("��Բ");
			break;
		case 3:
			printf("��Բ");
			break;
		case 4:
			printf("��Բ");
			break;
		case 5:
			printf("��Բ");
			break;
		case 6:
			printf("½Բ");
			break;
		case 7:
			printf("��Բ");
			break;
		case 8:
			printf("��Բ");
			break;
		case 9:
			printf("��Բ");
			break;
	}
	switch (b) 
	{
		case 0:
			if (c != 0)
				if (a10 + a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 > 0)
					printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;
	}
	switch (c) 
	{
		case 0:
			printf("��\n");
			break;
		case 1:
			printf("Ҽ��\n");
			break;
		case 2:
			printf("����\n");
			break;
		case 3:
			printf("����\n");
			break;
		case 4:
			printf("����\n");
			break;
		case 5:
			printf("���\n");
			break;
		case 6:
			printf("½��\n");
			break;
		case 7:
			printf("���\n");
			break;
		case 8:
			printf("�Ʒ�\n");
			break;
		case 9:
			printf("����\n");
			break;
	}

	return 0;
}