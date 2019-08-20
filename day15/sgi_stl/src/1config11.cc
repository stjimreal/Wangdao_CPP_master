#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

class alloc{

};

inline size_t __deque_buf_size(size_t n, size_t sz)
{
    return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}

template <class T, class Ref, class Ptr, size_t BufSiz>
struct __deque_iterator {
    typedef __deque_iterator<T, T&, T*, BufSiz> iterator;
    typedef __deque_iterator<T, const T&, const T*, BufSiz> const_iterator;

    static size_t buffer_size(){
        return __deque_buf_size(BufSiz, sizeof(T));
    }
};

template <class T, class Alloc = alloc, size_t BufSiz = 0>
class deque{
public:
    typedef __deque_iterator<T, T&, T*, BufSiz> iterator;
};

int main()
{
    cout<< deque<string >::iterator::buffer_size()<<endl;
    cout<< deque<long int, alloc, 0>::iterator::buffer_size()<<endl;
    return 0;
}