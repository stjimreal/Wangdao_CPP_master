#include <iostream>
#include <cstring>
#include <memory>
#include <algorithm>
using namespace std;

class Array2 {
// 在此处补充你的代码
/* 
0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11, 
*/
    class array
    {
        int * _arr;
    public:
        array(int column)
        : _arr(new int[column])
        {}
        array()
        : _arr(nullptr)
        {}
        ~array()
        {
            if(_arr)
                delete []_arr;
            _arr = nullptr;
        }
        void assign1(int x)
        {
            _arr = new int[x];
        }

        int& operator[](int index)
        {
            return _arr[index];
        }
    };
public:
    Array2()
    : _arr2(nullptr)
    {}
    Array2(int row, int column)
    {
        _arr2 = new array[row + 1] + 1;
        *(long *)(_arr2 - 1) = 1;
        for (int i = 0; i < row; ++i)
        {
            _arr2[i].assign1(column);
        }
    }
    array& operator[](int index)
    {
        return _arr2[index];
    }

    int & operator()(int x, int y)
    {
        return _arr2[x][y];
    }

    Array2& operator=(const Array2& args2)
    {
        if(&args2 == this)
            return *this;
        if(this->_arr2)
            delete []_arr2;
        _arr2 = args2._arr2;
        ++*(long *)(_arr2 - 1);
        return *this;
    }

    ~Array2()
    {
        if(--*(long *)(_arr2 - 1) == 0)
        {
            delete [](_arr2 - 1);
        }
        _arr2 = nullptr;
    }

private:
    array* _arr2;
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
        {
            a[i][j] = i * 4 + j;
        }
            
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}