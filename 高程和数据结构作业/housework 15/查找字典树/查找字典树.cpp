#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
const int N = 100005;
int trie[N][26];//二维数组作为字典树基本结构
int count[N]; //对单词结尾进行计数
int id; //记录每一个结点的编号

typedef struct
{
	string string_str;
	int number;
}word;

priority_queue<word, vector<word>, greater<word> >que;//按字典序的优先队列


/**
* @brief 对>进行运算符重载
* @param const word a,b 要进行比较的两个 word 型数据
* @return a>b 返回 true a<b 返回 false
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
	/*长度不同，提前结束的较小*/
	if (i != a.s.length())
		return 1;
	if (j != b.s.length())
		return 0;
	return 0;
}

/**
* @brief 在字典树中插入字符串
* @param string s 要插入的字符串
* @return 无
*/
void insert_tree(string s)
{
	int p = 0;//从根节点序号 0 进入
	for (遍历字符串)
	{
		int x = s[i] - 'a';//得到该字符的序号
		if (trie[p][x] == 0) //若该字符结点不是结束结点则新建一个序号结点
			trie[p][x] = ++id;
		p = trie[p][x]; //到下一个结点
	}
	count[p]++; //最终到达结束结点，对应字符串计数+1
}
/**
* @brief 对字典树进行深度优先遍历，得到相应的键值对，存入优先队列
* @param int p 当前节点序号
* @param string s 当前已经形成的字符串
* @return 无
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
		if (trie[p][i] != 0)//存在这个点
		{
			s.push_back('a' + i);
			dfs(trie[p][i], s);//继续深搜
			s.pop_back(); //回溯
		}
	}
}
/**
* @brief 命令行输入文件，对文件进行预处理并输出键值对
* @param int argc 命令行输入的字符串参数个数
* @param char*argv[] 文件指令字符串
* @return 0
*/
int main(int argc, char* argv[])
{
	ofstream fileout;
	ifstream filein (argv[1], ios::in);
	if (!filein.is_open()) {
		cout << "输入文件打开失败！\n";
		return -1;
	}
	if (argc == 3) {
		fileout.open(argv[2], ios::out);
		if (!fileout.is_open()) {
			cout<< "输出文件打开失败！\n";
			return -1;
		}
	}
	/*文件读取程序*/
	int str;//存储读取的字符
	string s;//存储读取的单词
	while ((str = filein.get()) != EOF)
	{
		char nextchar = filein.peek();
		if (str >= 'A' && str <= 'Z')
			str += 'a' - 'A';
		if (str >= 'a' && str <= 'z')
		{
			s.push_back(str);//将读取的字符加入字符串
			if (nextchar == EOF)//如果下一个字符是文件结束符，就将字符串加入树结构，这里属于考虑特殊情况
				insert_tree(s);
		}
		if (str == '-' && nextchar == '\n') //对于'-'字符，考虑后面的内容，如果是加换行的情况，继续读取
			continue;

		while (filein.peek() != EOF && filein.peek() != '-' && filein.peek() < 'A' || (filein.peek() > 'Z' &&
			filein.peek() < 'a') || filein.peek() > 'z')//将文件中出现的不是字母或者'-'字符删去
			filein.get();

		//当读到文件是空格的时候，将字符串插入到字典树中
		if (filein.peek() == ' '&&s.length() != 0)
		{
			insert_tree(s);
			s = "";//并将字符串置空，方便下次操作
		}
	}

	string s1 = "";
	dfs(0, s1);//通过搜索将但单词赋值到s1中
	//输出队列的键值对
	while (!que.empty())
	{
		word dictionary = que.top();
		que.pop();
		cout << "<" << dictionary.string_str << "," << dictionary.number << ">" << endl;
	}

	/*关闭文件*/
	if (argc == 3)
		fileout.close();
	filein.close();
	return 0;
}