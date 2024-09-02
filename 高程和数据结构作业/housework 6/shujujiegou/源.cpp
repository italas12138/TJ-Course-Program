#include <iostream>
using namespace std;
int main()
{
    float f = -5/2.0;
    unsigned char* p = (unsigned char*)&f;
    cout << hex << (int)(*p) << endl;
    cout << hex << (int)(*(p + 1)) << endl;
    cout << hex << (int)(*(p + 2)) << endl;
    cout << hex << (int)(*(p + 3)) << endl;
    return 0;
}
