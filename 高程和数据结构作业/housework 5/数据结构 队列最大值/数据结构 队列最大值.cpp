#define stackinitsize 100
#define stackaddsize 10

#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	int *base;
	int front;
	int rear;
}squeue;

int initsqueue(squeue& s, int n)
{
	s.base = (int*)malloc((n+1) * sizeof(int));
	if (!s.base)
		return -1;
	s.front = s.rear=0;
	return 0;
}

int enqueue(squeue& s,int c,int n)
{
	if ((s.rear + 1) % (n + 1) == s.front)
	{
		cout << "Queue is Full" << endl;
		return -1;
	}
	s.base[s.rear] = c;
	s.rear = (s.rear + 1) % (n + 1);
	return 0;
}

int dequeue(squeue& s,int e,int n)
{
	if (s.front == s.rear)
	{
		cout << "Queue is Empty" << endl;
		return -1;
	}
	e = s.base[s.front];
	s.front = (s.front + 1) % (n + 1);
	cout << e << endl;
	return 0;
}

int main()
{
	int n=0,c=0,e=0,m=0;
	int  position=-1, cposition=-1;
	int max = -2000000000, cmax = -2000000000;
	cin >> n;
	squeue(s);
	initsqueue(s,n);
	char do1[10];
	cin >> do1;
	while (do1[0] != 'q')
	{
		if (do1[0] == 'e')
		{
			cin >> c;
			if (c > max && (s.rear + 1) % (n + 1) != s.front)           /*c比我的最大值大，同时队列未满*/
			{
				max = c;
				position = (s.rear+n) % (n + 1);
				cmax = -2000000000;
				cposition = -1;
			}
			else if (c > cmax && (s.rear + 1) % (n + 1) != s.front)    /*c比我的次大值大，同时队列未满*/
			{
				cmax =c;
				cposition = (s.rear +n) % (n + 1);
			}
			enqueue(s, c, n);
		}
		if (do1[0] == 'd')
		{
			if (s.front== position)
			{
				max = cmax;
				position = cposition;
				if(s.rear == (position + 1) % (n + 1))
				{
					cmax = -2000000000;
					cposition = -1;
				}
				else
				{
					cmax = -2000000000;
					cposition = -1;
					for (int k = 1; (k +position) % (n + 1) != s.rear; ++k)
					{
						m = s.base[(k + position) % (n + 1)];
						if (cmax < m)
						{
							cmax = m;
							cposition =(k + position) % (n + 1);
						}
					}
				}
			}
			dequeue(s, e, n);
		}
		if (do1[0] == 'm')
		{
			if (s.front == s.rear)
				cout << "Queue is Empty" << endl;
			else
			    cout << max << endl;
		}
		cin >> do1;
	}
	if (do1[0] == 'q')
	{
		for (int i = 0; (i + s.front) % (n + 1) != s.rear; ++i)
			cout << s.base[(i + s.front) % (n + 1)] << " ";
		cout << endl;
	}
	return 0;
}