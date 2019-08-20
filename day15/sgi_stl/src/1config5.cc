#include <iostream>

using namespace std;

template<class I, class O>
struct testCls
{
    testCls()
    {
        cout<<"I, O"<<endl;
    }
};

template<class T>
struct testCls<T*, T*>
{
    testCls()
    {
        cout<<"T*, T*"<<endl;
    }
};

template<class T>
struct testCls<const T*, T*>
{
    testCls()
    {
        cout<<"const T*, T*"<<endl;
    }
};

int main()
{
    testCls<int, int> obj1;
    testCls<int *, int *> obj2;
    testCls<const int *, int *> obj3;
    return 0;
}