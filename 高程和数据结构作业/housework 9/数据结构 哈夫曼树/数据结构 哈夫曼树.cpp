#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int maxchar = 127;//最大字符数

//哈夫曼树的定义
typedef struct node {
	int weight = 0;     
	//父母，左右孩子初始化都为-1，后面会变为正整数，方便后面查找是否有左右孩子和父母。
	int parent = -1;
	int leftchild = -1, rightchild = -1;
	char chucun;
}huffmantree[2 * maxchar+1];

typedef char** HuffmanCode;

//压缩文件相关的函数
//全文遍历，并计算权值
long entirebianli(FILE* yuanshi, huffmantree& T)
{
	long n=0;
	char ch;
	while (!((ch = fgetc(yuanshi))==EOF))
	{
		T[ch].weight++;
		T[ch].chucun = ch;
		++n;
	}
	return n;
}

//寻找权值最小的两个字符
void searchmin(huffmantree T, int n, int& min1, int& min2)
{
	int min1weight = T[0].weight > T[1].weight ? T[1].weight : T[0].weight;
	int min2weight = T[0].weight > T[1].weight ? T[0].weight : T[1].weight;
	//初始化为前两个的权值
	for (int i = 1; i <= 127; i++)
	{
		if (T[i].parent == -1) {
			if (T[i].weight < min1weight)
			{
				min2 = min1;
				min1 = i;
				min2weight = min1weight;
				min1weight = T[i].weight;
			}
			else if (T[i].weight >= min1weight && T[i].weight < min2weight)
			{
				min2 = i;
				min2weight = T[i].weight;
			}
		}
	}
}

//建立哈夫曼树
void Createhuffmantree(FILE* yuanshi, huffmantree& T)
{
	//前128个结点为叶子结点，后面128用于整个过程的连接
	for (int i = 128; i <= 2 * maxchar - 1; i++)
	{
		int min1 = 0, min2 = 0;
		searchmin(T, i - 1, min1, min2);
		T[min1].parent = i;
		T[min2].parent = i;
		T[i].leftchild = min1;
		T[i].rightchild = min2;
		T[i].weight = T[min1].weight + T[min2].weight;
	}
	char* cd;
	HuffmanCode HC;
	HC = (HuffmanCode)malloc((maxchar+1) * sizeof(char));
	cd = (char*)malloc((maxchar + 1) * sizeof(char));
	cd[maxchar - 1] = '\0';
	for (int i = 1; i <= maxchar; i++) //遍历每个要编码的字符
	{
		int start = maxchar - 1;//从倒数第二位开始读入
		for (int c = i, f = T[i].parent; f != -1; c = f, f = T[f].parent)
		{
			if (T[f].leftchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char*)malloc((maxchar - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
		cout << HC[i] << endl;
	}
}

void writeyasuo(FILE* yuanshi, FILE* yasuo, char* HC)
{
	char onebit = 0;
	int jishu = 0;
	int ch;
	rewind(yuanshi);
	while (!(ch = fgetc(yuanshi)== EOF))
	{
		for (int i = 0; i < strlen(HC); i++)
		{
			if (HC[i] == '1')
				onebit = (onebit << 1) + 1;
			else
				onebit = (onebit << 1) + 0;
			++jishu;
			if (jishu == 8)
			{
				fwrite(&onebit, 1, 1, yasuo);
				jishu = 0;
				onebit = 0;
			}
		}
	}
	onebit = onebit << (8 - jishu);
	fwrite(&onebit, 1, 1, yasuo);//把最后没满的写进去
}

//解压文件相关的函数

void reCreatehuffmantree(FILE* yasuo, FILE* jieya, huffmantree T, long long n)
{
	int root = 2 * maxchar - 1;//root 必为最后一个结点
	int jishu = 8;
	char onebit = 0;
	int tr = root;//tr 相当于工作指针
	while (n) {
		fread(&onebit, 1, 1, yasuo);
		while (1)
		{
			while (T[tr].leftchild != -1 && T[tr].rightchild != -1)
			{
				if (jishu == 1 && onebit)
					tr = T[tr].rightchild;
				else
					tr = T[tr].leftchild;
				--jishu;
				if (jishu == 0)
				{
					jishu = 8;
					if (T[tr].leftchild == -1 && T[tr].rightchild == -1)
					{
						fputc(T[tr].chucun, jieya);
						tr = root;
						n--;
						if (n == 0)
							return;
					}
					return;
				}
			}
			if (T[tr].leftchild == -1 && T[tr].rightchild == -1)//读到字符节点
			{
				fputc(T[tr].chucun, jieya);
				tr = root; //工作指针复位
				n--;
				if (n == 0)
					break;
			}
		}
	}
}

int main()
{
	//文件压缩过程

	//文件的打开
	FILE* yuanshi, * yasuo, * jieya;       //文件指针的定义

	//只读方式打开原始文件
	if ((yuanshi = fopen("yuanshi.text", "r")) == NULL) 
	{
		cerr << "不能打开原始文件 \n";
		return -1;
	}

	//二进制只写的方式打开压缩文件
	if ((yasuo = fopen("yasuo.text", "wb")) == NULL) 
	{
		cerr << "不能打开压缩文件 \n";
		return -1;
	}
	char HC[maxchar + 1];//code 指针数组，存储 huffman 编码
	huffmantree tree;
    long n = entirebianli(yuanshi, tree); //记录每个字符的频率与总字符数
	Createhuffmantree(yuanshi, tree);//建树
	writeyasuo(yuanshi, yasuo,HC);//将 huffman 编码写入 fzip
    //关闭文件
	fclose(yuanshi);
	fclose(yasuo);
	
	//文件解压过程

	//文件的打开

	//以二进制只读形式压缩文件
	if ((yasuo = fopen("yasuo.text", "rb")) == NULL)
	{
		cerr << "不能打开压缩文件 \n";
		return -1;
	}

	//以只写方式打开解压文件
	if ((jieya = fopen("jieya.text", "w")) == NULL)
	{
		cerr << "不能打开解压文件 \n";
		return -1;
	}
	reCreatehuffmantree(yasuo, jieya, tree, n);
	//关闭文件
	fclose(yasuo);
	fclose(jieya);
	return 0;
}