#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int maxchar = 127;//����ַ���

//���������Ķ���
typedef struct node {
	int weight = 0;     
	//��ĸ�����Һ��ӳ�ʼ����Ϊ-1��������Ϊ�������������������Ƿ������Һ��Ӻ͸�ĸ��
	int parent = -1;
	int leftchild = -1, rightchild = -1;
	char chucun;
}huffmantree[2 * maxchar+1];

typedef char** HuffmanCode;

//ѹ���ļ���صĺ���
//ȫ�ı�����������Ȩֵ
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

//Ѱ��Ȩֵ��С�������ַ�
void searchmin(huffmantree T, int n, int& min1, int& min2)
{
	int min1weight = T[0].weight > T[1].weight ? T[1].weight : T[0].weight;
	int min2weight = T[0].weight > T[1].weight ? T[0].weight : T[1].weight;
	//��ʼ��Ϊǰ������Ȩֵ
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

//������������
void Createhuffmantree(FILE* yuanshi, huffmantree& T)
{
	//ǰ128�����ΪҶ�ӽ�㣬����128�����������̵�����
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
	for (int i = 1; i <= maxchar; i++) //����ÿ��Ҫ������ַ�
	{
		int start = maxchar - 1;//�ӵ����ڶ�λ��ʼ����
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
	fwrite(&onebit, 1, 1, yasuo);//�����û����д��ȥ
}

//��ѹ�ļ���صĺ���

void reCreatehuffmantree(FILE* yasuo, FILE* jieya, huffmantree T, long long n)
{
	int root = 2 * maxchar - 1;//root ��Ϊ���һ�����
	int jishu = 8;
	char onebit = 0;
	int tr = root;//tr �൱�ڹ���ָ��
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
			if (T[tr].leftchild == -1 && T[tr].rightchild == -1)//�����ַ��ڵ�
			{
				fputc(T[tr].chucun, jieya);
				tr = root; //����ָ�븴λ
				n--;
				if (n == 0)
					break;
			}
		}
	}
}

int main()
{
	//�ļ�ѹ������

	//�ļ��Ĵ�
	FILE* yuanshi, * yasuo, * jieya;       //�ļ�ָ��Ķ���

	//ֻ����ʽ��ԭʼ�ļ�
	if ((yuanshi = fopen("yuanshi.text", "r")) == NULL) 
	{
		cerr << "���ܴ�ԭʼ�ļ� \n";
		return -1;
	}

	//������ֻд�ķ�ʽ��ѹ���ļ�
	if ((yasuo = fopen("yasuo.text", "wb")) == NULL) 
	{
		cerr << "���ܴ�ѹ���ļ� \n";
		return -1;
	}
	char HC[maxchar + 1];//code ָ�����飬�洢 huffman ����
	huffmantree tree;
    long n = entirebianli(yuanshi, tree); //��¼ÿ���ַ���Ƶ�������ַ���
	Createhuffmantree(yuanshi, tree);//����
	writeyasuo(yuanshi, yasuo,HC);//�� huffman ����д�� fzip
    //�ر��ļ�
	fclose(yuanshi);
	fclose(yasuo);
	
	//�ļ���ѹ����

	//�ļ��Ĵ�

	//�Զ�����ֻ����ʽѹ���ļ�
	if ((yasuo = fopen("yasuo.text", "rb")) == NULL)
	{
		cerr << "���ܴ�ѹ���ļ� \n";
		return -1;
	}

	//��ֻд��ʽ�򿪽�ѹ�ļ�
	if ((jieya = fopen("jieya.text", "w")) == NULL)
	{
		cerr << "���ܴ򿪽�ѹ�ļ� \n";
		return -1;
	}
	reCreatehuffmantree(yasuo, jieya, tree, n);
	//�ر��ļ�
	fclose(yasuo);
	fclose(jieya);
	return 0;
}