#include <iostream>

using namespace std;

class A{
    int _ix, _iy;
    public:
    A(int x = 0, int y = 0)
    {
        this->_ix = x + 1;
        this->_iy = y + 2;
    }
    ~A()
    {
        cout<<"destructor called\n";
    }
};

int main()
{
    A a = 2;
    a = 4;
    cout<<"main end"<<endl;
    return 0;
}
