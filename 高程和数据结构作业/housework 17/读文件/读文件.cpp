#include <iostream>
#include <string> 
#include <fstream> 
#include <io.h>
using namespace std;

void GetLineAndPrint(string in_name)
{
	cout << in_name << endl;
	ifstream fin(in_name);
	if (!fin)
	{
		cerr << "open file error" << endl;
		exit(-1);
	}
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
}

int main()
{
	struct _finddata_t fileinfo;
	string in_path = "D:/桌面资料/f/stage";
	string in_name;
	string curr = in_path + "\\*.txt";
	long handle;
	if ((handle = _findfirst(curr.c_str(), &fileinfo)) == -1L)
	{
		cout << "没有找到匹配文件!" << endl;
		return 0;
	}
	else
	{
		in_name = in_path + "\\" + fileinfo.name;
		GetLineAndPrint(in_name);
		
		while(!_findnext(handle, &fileinfo))
		{
			in_name = in_path + "\\" + fileinfo.name;
			GetLineAndPrint(in_name);
		}
		_findclose(handle);
	}
}
