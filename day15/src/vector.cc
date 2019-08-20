#include <memory>
#include <iostream>
#include <string>
// #include <algorithm>

using std::allocator;
using std::cout;
using std::endl;
using std::cin;
using std::string;

template <class Tp, class Alloc = allocator<Tp> >
class vector
{
public:

    typedef Tp value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef value_type& reference;
    typedef ptrdiff_t difference_type;
    typedef const value_type* const_iterator;
    typedef const value_type& const_reference;

    const_iterator cbegin() const {   return _first;}
    const_iterator cend() const {   return _last;}
    iterator begin() {   return _first;}
    iterator end() {   return _last;}
    difference_type capacity() {    return _end - _first;}
    difference_type size() {    return _last - _first;}
    reference operator[](size_t index)
    {
        return *(_first + index);
    }
    const_reference operator[](size_t index) const
    {
        return *(_first + index);
    }

    vector()
    : _first(nullptr), _last(nullptr), _end(nullptr)
    {}

    vector(size_t size, value_type val)
    {
        _last =_first = _alloc.allocate(size);
        for(int i = 0; i < size; ++i)
        {
            _alloc.construct(_last++, val);
        }
        _end = _last;
    }

    vector(size_t size)
    {
        _last =_first = _alloc.allocate(size);
        for(int i = 0; i < size; ++i)
        {
            _alloc.construct(_last++);
        }
        _end = _last;
    }

    iterator push_back(const value_type& val)
    {
        auto sz = capacity();
        if(_end == _last){
            reallocate(sz > 0 ? (sz << 1) : 1);
            printf("%s\n", __FUNCTION__);
            for(auto iter = cbegin(); iter != cend(); ++iter)
            {
                std::cout<<*iter<<' ';
            }
            cout<<"capacity = "<<capacity()<<" size = "<<size()<<endl;
            std::cout<<std::endl;
        }
        _alloc.construct(_last++, val);
        return _last;
    }

    void pop_back()
    {
        if(_last == _first)
            return;
        _alloc.destroy(--_last);
    }



    ~vector()
    {
        clear();
        _alloc.deallocate(_first, capacity());
    }

    void clear()
    {
        if(_first == _last)
            return;
        while(--_last >= _first )
            _alloc.destroy(_last);
        _last = _first;
    }

protected:

    void reallocate(size_t newSize)
    {
        iterator tmpPtr = _alloc.allocate(newSize);
        if(_first != _last)
            std::uninitialized_copy(_first, _last, tmpPtr);

        auto sz = capacity();
        clear();
        _alloc.deallocate(_first, sz);

        _end = &tmpPtr[newSize];
        _last = &tmpPtr[sz];
        _first = tmpPtr;
    }

    iterator _first;
    iterator _last;
    iterator _end;
    static Alloc _alloc;

};

template<class Tp, class Alloc> 
Alloc vector<Tp, Alloc>::_alloc;

// template<class Tp>
// std::allocator<Tp> vector<Tp>:: _alloc;

int main()
{
    vector<int> a;
    vector<string> b(5, "hello");
    for(auto iter = a.cbegin(); iter != a.cend(); ++iter)
    {
        std::cout<<*iter<<' ';
    }
    cout<<"capacity = "<<a.capacity()<<" size = "<<a.size()<<endl;
    std::cout<<std::endl;

    for(int i = 1; i <= 5; ++i)
    {
        a.push_back(i);
        cout<<"capacity = "<<a.capacity()<<" size = "<<a.size()<<endl;
    }
    for(auto iter = a.cbegin(); iter != a.cend(); ++iter)
    {
        std::cout<<*iter<<' ';
    }
    std::cout<<std::endl;

    for(auto iter = b.cbegin(); iter != b.cend(); ++iter)
    {
        std::cout<<*iter<<' ';
    }
    std::cout<<std::endl;
    cout<<"capacity = "<<b.capacity()<<" size = "<<b.size()<<endl;
    b.pop_back();
    cout<<"capacity = "<<b.capacity()<<" size = "<<b.size()<<endl;
    b.push_back("world");
    for(auto iter = b.cbegin(); iter != b.cend(); ++iter)
    {
        std::cout<<*iter<<' ';
    }
    std::cout<<std::endl;
    cout<<"capacity = "<<b.capacity()<<" size = "<<b.size()<<endl;
    b.clear();
    cout<<"capacity = "<<b.capacity()<<" size = "<<b.size()<<endl;
    
    return 0;
}