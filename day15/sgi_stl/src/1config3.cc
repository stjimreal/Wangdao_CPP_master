#include <iostream>

using namespace std;

template <typename T>
class testClass{
public:
    static int _data;
};

template<class T> 
int testClass<T>::_data = 1;

int main()
{
    cout<< testClass<int>::_data<<endl;
    testClass<int> obji1, obji2;
    testClass<char> objj1;
    cout<<obji1._data++<<endl;
    cout<<obji2._data++<<endl;
    cout<<objj1._data++<<endl;

    return 0;
}