#include <iostream>

template <class T> class vector
{
    T* _beg;
    T* _fin;
    T* _end_of_storage;
public:
    vector(){_beg = _fin = _end_of_storage = nullptr;}
    vector(const size_t n, const T &value)
    : _beg(new T[n])
    {
        printf("===%s===\n", __FUNCTION__);
        _end_of_storage = _fin = _beg + n;
        for(T *iterator = _beg;iterator != _fin; ++iterator)
            *iterator = value;
    }
    void push_back(const T& value)
    {
        if(_fin == _end_of_storage)
        {
            size_t size = _end_of_storage - _beg;
            T *newPtr = new T[size * 2];
            memcpy(newPtr, _beg, size * sizeof(T));
            delete []_beg;
            _beg = newPtr;
            _fin = newPtr + size;
            _end_of_storage = newPtr + size * 2;
        }
        *_fin++ = value;
    }
    T pop()
    {
        if(_beg == _fin)
            return 0;
        return *(--_fin);
    }
    size_t capacity()
    {
        return _end_of_storage - _beg;
    }
    size_t size()
    {
        return _fin - _beg;
    }
    ~vector()
    {
        printf("===%s===\n", __FUNCTION__);
        delete []_beg;
        _beg = _fin = _end_of_storage = nullptr;
    }
    friend std::ostream& operator <<(std::ostream& out, const vector<T> &v) 
    {
        for(T* iterator = v._beg;iterator != v._fin; ++iterator)
        {
            out<<*iterator<<" ";
        }
        return out;
    }
};