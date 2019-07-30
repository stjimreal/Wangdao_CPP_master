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

