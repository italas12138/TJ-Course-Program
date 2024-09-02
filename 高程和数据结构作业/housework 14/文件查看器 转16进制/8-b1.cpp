/*2152118 ʷ���� �ƿ�*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{	
    clog << "�ļ���������ʽ������:" << endl;
    clog << "    a.txt                     : ����·����ʽ" << endl;
    clog << "    ..\\data\\b.dat             : ���·����ʽ" << endl;
    clog << "    C : \\Windows\\System32\\c.dat : �������·����ʽ" << endl;
    clog << "�������ļ��� :";

    ifstream file;
    char filename[200];
    cin.getline(filename,200);
    file.open(filename, ios::in|ios::binary);

    if (file.is_open() == 0)
    {
        clog << "�����ļ�" << filename << "��ʧ��!"<<endl;
        return -1;
    }
    int address = 0;
    int ch;
    int number = 0;
    while ((ch = file.get()) != EOF)
    {
        if (number == 0)
        {
            cout <<hex<< setw(8) << setfill('0') << address<<":  ";
            address += 16;
        }
        //cout << &ch << ":  ";
        cout << hex<<setiosflags(ios::uppercase) <<setw(2) << setfill('0')<<ch << " ";
        ++number;
        if (number == 8)
            cout << "- ";
        if (number == 16)
        {
            number = 0;
            cout << " ";
            file.seekg(-16, ios::cur);
            for (int i = 0; i < 16; ++i)
            {
                ch = file.get();
                if (ch >= 33 && ch <= 126)
                    cout << char(ch);
                else
                    cout << ".";
            }
            cout << endl;
        }     
    }

    file.clear();

    if (number != 0)
    {
        for (int i = 16; i > number; --i)
            cout << "   ";
        if (number <= 8)
            cout << "  ";
        cout << " ";
        file.seekg(-number, ios::cur);
        for (int i = 0; i < number; ++i)
        {
            ch = file.get();
            if (ch >= 33 && ch <= 126)
                cout << char(ch);
            else
                cout << ".";
        }
        cout << endl;
    }

    file.close();

    return 0;
}