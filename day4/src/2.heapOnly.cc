#include <iostream>
class on_stack
{
    void * operator new(size_t);
    void operator delete(void *);
    int _value;
public:
    on_stack(): _value(-1){}
    on_stack(int x): _value(x){}
    ~on_stack(){}
    friend std::ostream & operator<<(std::ostream &out, const on_stack& x)
    {
        out<<x._value;
        return out;
    }
};
class on_heap
{
    static on_heap* _restore;
    int _value;

   
public:
    void* operator new(size_t x)
    {
        if(_restore)
            return _restore;
        _restore = (on_heap *)malloc(x);
        return _restore;
    }
    // friend on_heap* genObj(int x = -1)
    // {
    //     if(on_heap::_restore)
    //         return on_heap::_restore;
    //     return new on_heap(x);
    // }
    // void destroy()
    // {
    //     std::cout<<"destructor called"<<std::endl;
    //     if(_restore)
    //     {
    //         _restore = nullptr;
    //         delete this;
    //     }
    // }
    void operator delete(void *p)
    {
        std::cout<<"destructor called"<<std::endl;
        if(_restore == nullptr) return;
        _restore = nullptr;
        free(p);
    }
    ~on_heap(){}
    on_heap(){}
    on_heap(int x):_value(x){}
    friend std::ostream & operator<<(std::ostream &out, const on_heap& x)
    {
        out<<x._value;
        return out;
    }
};

on_heap* on_heap::_restore = nullptr;

// int main()
// {
//     on_heap *c = new on_heap(7);
//     std::cout<<*c<<std::endl;
//     on_heap *d = new on_heap;
//     std::cout<<*d<<std::endl;
//     delete d;
//     delete c;
//     return 0;
// }