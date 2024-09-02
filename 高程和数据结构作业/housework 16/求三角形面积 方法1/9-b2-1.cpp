/* 2152118 ʷ���� �ƿ� */
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	int getx() const
	{
		return x;
	}
	int gety() const
	{
		return y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	void set(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

};

class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		//��ø��������
		int x1, x2, x3, y1, y2, y3;
		x1 = p1.getx();
		x2 = p2.getx();
		x3 = p3.getx();
		y1 = p1.gety();
		y2 = p2.gety();
		y3 = p3.gety();

		//�ж������Ƿ���
		if ((x1-x2)*(y2-y3)==(x2-x3)*(y1-y2))
			return -1;

		//��������ߵĳ���
		double L1, L2, L3;
		double S = 0;
		double sin, cos;
		L1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		L2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		L3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

		//�������ֵ
		cos = (L1 * L1 + L2 * L2 - L3 * L3) / (2 * L1 * L2);

		//�������ֵ
		sin = sqrt(1 - cos * cos);

		//������������
		S = L1 * L2 * sin / 2;

		return S;
	}

	/* ���캯�� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}
