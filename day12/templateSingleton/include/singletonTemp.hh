#ifndef __SINGLETON_TEMPLATE_HH
#define __SINGLETON_TEMPLATE_HH

#include <pthread.h>
#include <iostream>

template <class T>
class Singleton
{
public:
    template <typename ...Args> static T* getInstance(const Args&... args);

private:
    static void destroy();
    static void init();
    Singleton(): _value(T()){printf("%s\n", __FUNCTION__);}
    Singleton(const Singleton&){}
    ~Singleton(){printf("%s\n", __FUNCTION__);}

    T _value;
    static Singleton* _ptr;
    static pthread_once_t _auto;
};

#endif

#ifndef __SINGLETON_METHOD_CC
#define __SINGLETON_METHOD_CC
#include "singletonMethod.tcc"
#endif
