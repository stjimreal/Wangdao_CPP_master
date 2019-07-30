#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex(){r = 0; i = 0;}
    Complex(const char* s)
    {
        string str = s;
        auto pos1 = str.find('+');
        auto pos2 = str.find_last_not_of('i');
        r = atof(str.c_str());
        i = atof(str.substr(pos1 + 1, pos2 - pos1).c_str());
    }
};
int main() {
    Complex a;
    a = "3.67245+4.45i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}