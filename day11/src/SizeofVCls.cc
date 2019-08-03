#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class vbase
{
public:
    virtual void display()
    {
        cout<<"I am virtual base\n";
    }
    long int _vvb = 8;
};

class base
{
public:
    base() = default;
    virtual void display()
    {
        cout<<"I am base\n";
    }
private:
    int _bv = 16;
};

class child:virtual public vbase, public base
{
public:
    virtual void display()
    {
        cout<<"I am child\n";
    }
    virtual void show(){}
private:
    int _cv = 32;
};

int main()
{
    int j = 0, k = 0;
    child me;
    base& h1 = me;
    vbase& h2 = me;
    int i = 6;
    me.display();
    h1.display();
    h2.display();
    printf("Sizeof me = %ld\n", sizeof(me));
}