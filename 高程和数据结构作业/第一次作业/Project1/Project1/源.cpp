/* 2152118 �ƿ� ʷ���� */

#define Pi 3.14159
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double r, h;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed);
	cout << "Բ�ܳ�     " << ": " 
		 << setprecision(2) << 2 * r * Pi << endl;
	cout << "Բ���     " << ": " 
		 << setprecision(2) << Pi * r * r << endl;
	cout << "Բ������ " << ": " 
		 << setprecision(2) << 4 * Pi * r * r << endl;
	cout << "Բ�����   " << ": " 
		 << setprecision(2) << 4 / 3.0 * Pi * r * r * r << endl;
	cout << "Բ�����   " << ": " 
		 << setprecision(2) << Pi * r * r * h << endl;

	return 0;
}