#include <iostream>
using namespace std;

#define maxsize 20005

int keynum[maxsize]={0};

struct haxi
{
	char name[105];
	int key;
}person[maxsize];

void findP(int &p)
{
	bool find = 0;
	while (++p)
	{
		find = 0;
		for(int i=2;i<=p-1;++i)
			if (p % i == 0)
			{
				find = 1;
				break;
			}
		if (find)
			continue;
		else
			break;
	}
	return;
}

void sushu(int &p)
{
	bool findsushu = 1;
	for (int i = 2; i <= p - 1; ++i)
		if (p % i == 0)
		{
			findsushu = 0;
			break;
		}
	
	if(!findsushu)
		findP(p);
	if (p == 1)
		++p;
	return;
}

int findhaxi(int number,int P,int z)
{
	bool findnum = 0;
	int yinyong=number;
	for (int i = 1; i <= P; ++i)
	{
		yinyong = number;
		yinyong += i * i;
		yinyong=(yinyong+P)%P;
		if (keynum[yinyong] == 0)
		{
			keynum[yinyong] = z + 1;
			person[z].key = yinyong;
			findnum = 1;
			break;
		}
		if (findnum)
			break;

		yinyong = number;
		yinyong -= i * i;
		yinyong = (yinyong + P) % P;
		if (keynum[yinyong] == 0)
		{
			keynum[yinyong] = z + 1;
			person[z].key = yinyong;
			findnum = 1;
			break;
		}
		if (findnum)
			break;
	}
	return findnum;
}

void count_key(haxi person[maxsize],int N,int P)
{
	int number;
	for (int i = 0; i < N; ++i)
	{
		int j = 0;
		number = 0;
		while (person[i].name[j] != '\0')
		{
			number = number * 37 + person[i].name[j];
			number %= P;
			++j;
		}
		if (keynum[number] == 0)
		{
			keynum[number] = i + 1;
			person[i].key = number;
		}
		else if (!findhaxi(number, P,i))
			person[i].key = -1;
	}
	return;
}

int main()
{
	int N, P;
	cin >> N >> P;

	sushu(P);

	for (int i = 0; i < N; ++i)
		cin >> person[i].name;

	count_key(person,N,P);

	for (int i = 0; i < N; ++i)
	{
		if (person[i].key < 0)
			cout << "- ";
		else
			cout << person[i].key << " ";
	}

	cout << endl;
	return 0;
}