/* 计科 2152118 史君宝 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	int bai, shi, ge, total = 0,i=0;
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;  /*a b c 分别代表个十百位，依次代表三个数*/
	for (bai = 17; bai <= 18; ++bai)
		for (shi = 6; shi <= 22; ++shi)
		{
			ge = 45 - shi - bai;
			if (bai * 100 + shi * 10 + ge == 1953)
				break;                        
			/*先前的程序设计已经发现三个数只能是18 14 13，所以直接break*/
		}
	--bai;
	for (a1 = 1; a1 <= 9; ++a1)
		for (a2 = a1 + 1; a2 <= 9; ++a2)
		{
			for (a3 = a2 + 1; a3 <= 9; ++a3)
			{
				if (a1 + a2 + a3 == bai)
					for (b1 = 1; b1 <= 9; ++b1)
					{
						if (b1 == a1 || b1 == a2 || b1 == a3)
							continue;
						for (c1 = 1; c1 <= 9; ++c1)
						{
							if (c1 == a1 || c1 == a2 || c1 == a3 || c1 == b1 )
								continue;
							for (b2 = 1; b2 <= 9; ++b2)
							{
								if (b2 == a1 || b2 == a2 || b2 == a3 || b2 == b1||b2==c1)
									continue;
								for (c2 = 1; c2 <= 9; ++c2)
								{
									if (c2 == a1 || c2 == a2 || c2 == a3 
										|| c2 == b1 || c2 == b2 || c2 == c1)
										continue;
									b3 = shi - b2 - b1;
									if (b3>9||b3 == a1 || b3 == a2 || b3 == a3 
									    || b3 == b1 || b3 == b2 || b3 == c1 || b3 == c2)
										continue;
									c3 = ge - c2 - c1;
									if (c3>9 || c3 == a1 || c3 == a2 || c3 == a3
										|| c3 == b1 || c3 == b2 || c3 == b3 || c3 == c1 || c3 == c2)
										continue;
									cout <<"No."<<setw(3) << ++i << " : " 
										<< a1 * 100 + b1 * 10 + c1<< "+" << a2 * 100 + b2 * 10 + c2 
										<< "+" << a3 * 100 + b3 * 10 + c3 << "=1953" << endl;
									++total;
								}
								
							}
						}
					}
			}
		}
	cout << "total="<<total << endl;

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) 
		 <<double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}