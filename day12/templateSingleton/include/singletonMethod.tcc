#define __SINGLETON_METHOD_CC

#include "singletonTemp.hh"

template <class T>
template <typename ...Args> T* Singleton<T>::getInstance(const Args&... args)
{
    printf("%s\n", __FUNCTION__);
    if(_ptr)
        return &_ptr->_value;
    ::atexit(Singleton::destroy);
    pthread_once(&_auto, init);
    _ptr->_value = T(args...);
    return &_ptr->_value;
}

template <class T>
void Singleton<T>::init()
{
    printf("%s\n", __FUNCTION__);
    _ptr = new Singleton;
}

template <class T>
void Singleton<T>::destroy()
{
    printf("%s\n", __FUNCTION__);
    if(_ptr)
        delete _ptr;
}

template <class T> Singleton<T>* Singleton<T>::_ptr = nullptr;
template <class T> pthread_once_t Singleton<T>::_auto = PTHREAD_ONCE_INIT;
