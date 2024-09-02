#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
const int N = 100005;
int trie[N][26];//��ά������Ϊ�ֵ��������ṹ
int count[N]; //�Ե��ʽ�β���м���
int id; //��¼ÿһ�����ı��

typedef struct
{
	string string_str;
	int number;
}word;

priority_queue<word, vector<word>, greater<word> >que;//���ֵ�������ȶ���


/**
* @brief ��>�������������
* @param const word a,b Ҫ���бȽϵ����� word ������
* @return a>b ���� true a<b ���� false
*/
bool operator >(const word a, const word b)
{
	int i = 0, j = 0;
	for (; i < (int)a.s.length() && j < (int)b.s.length(); i++, j++)
	{
		if (a.s[i] < b.s[i])
			return 0;
		if (a.s[i] > b.s[i])
			return 1;
	}
	/*���Ȳ�ͬ����ǰ�����Ľ�С*/
	if (i != a.s.length())
		return 1;
	if (j != b.s.length())
		return 0;
	return 0;
}

/**
* @brief ���ֵ����в����ַ���
* @param string s Ҫ������ַ���
* @return ��
*/
void insert_tree(string s)
{
	int p = 0;//�Ӹ��ڵ���� 0 ����
	for (�����ַ���)
	{
		int x = s[i] - 'a';//�õ����ַ������
		if (trie[p][x] == 0) //�����ַ���㲻�ǽ���������½�һ����Ž��
			trie[p][x] = ++id;
		p = trie[p][x]; //����һ�����
	}
	count[p]++; //���յ��������㣬��Ӧ�ַ�������+1
}
/**
* @brief ���ֵ�������������ȱ������õ���Ӧ�ļ�ֵ�ԣ��������ȶ���
* @param int p ��ǰ�ڵ����
* @param string s ��ǰ�Ѿ��γɵ��ַ���
* @return ��
*/
void dfs(int p, string s)
{
	if (count[p] != 0)
	{
		word w = { s,count[p] };
		q.push(w);
	}
	for (int i = 0; i < 26; i++)
	{
		if (trie[p][i] != 0)//���������
		{
			s.push_back('a' + i);
			dfs(trie[p][i], s);//��������
			s.pop_back(); //����
		}
	}
}
/**
* @brief �����������ļ������ļ�����Ԥ���������ֵ��
* @param int argc ������������ַ�����������
* @param char*argv[] �ļ�ָ���ַ���
* @return 0
*/
int main(int argc, char* argv[])
{
	ofstream fileout;
	ifstream filein (argv[1], ios::in);
	if (!filein.is_open()) {
		cout << "�����ļ���ʧ�ܣ�\n";
		return -1;
	}
	if (argc == 3) {
		fileout.open(argv[2], ios::out);
		if (!fileout.is_open()) {
			cout<< "����ļ���ʧ�ܣ�\n";
			return -1;
		}
	}
	/*�ļ���ȡ����*/
	int str;//�洢��ȡ���ַ�
	string s;//�洢��ȡ�ĵ���
	while ((str = filein.get()) != EOF)
	{
		char nextchar = filein.peek();
		if (str >= 'A' && str <= 'Z')
			str += 'a' - 'A';
		if (str >= 'a' && str <= 'z')
		{
			s.push_back(str);//����ȡ���ַ������ַ���
			if (nextchar == EOF)//�����һ���ַ����ļ����������ͽ��ַ����������ṹ���������ڿ����������
				insert_tree(s);
		}
		if (str == '-' && nextchar == '\n') //����'-'�ַ������Ǻ�������ݣ�����Ǽӻ��е������������ȡ
			continue;

		while (filein.peek() != EOF && filein.peek() != '-' && filein.peek() < 'A' || (filein.peek() > 'Z' &&
			filein.peek() < 'a') || filein.peek() > 'z')//���ļ��г��ֵĲ�����ĸ����'-'�ַ�ɾȥ
			filein.get();

		//�������ļ��ǿո��ʱ�򣬽��ַ������뵽�ֵ�����
		if (filein.peek() == ' '&&s.length() != 0)
		{
			insert_tree(s);
			s = "";//�����ַ����ÿգ������´β���
		}
	}

	string s1 = "";
	dfs(0, s1);//ͨ�������������ʸ�ֵ��s1��
	//������еļ�ֵ��
	while (!que.empty())
	{
		word dictionary = que.top();
		que.pop();
		cout << "<" << dictionary.string_str << "," << dictionary.number << ">" << endl;
	}

	/*�ر��ļ�*/
	if (argc == 3)
		fileout.close();
	filein.close();
	return 0;
}