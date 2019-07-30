#include <iostream>

using std::cout;
using std::cin;
using std::endl;
#define DEM "ax"
const int AX = 10;
int AY;
int main(const int argc, const char **argv)
{
    const int x = 5;
    int y = 10;
    int * p = (int *)&x;
    *p = 11;
    cout<<"address:"<<&x<<" value = "<<x<<endl;
    cout<<"address of global const = "<<&AX<<" address of function const = "<<&x<<endl;
    cout<<"address of global variable = "<<&AY<<" address of function variable = "<<&y<<endl;
    cout<<"address of literal = "<<&DEM<<endl;
    return 0;
}