#ifndef __SINGLETON_HH
#define __SINGLETON_HH

#include <pthread.h>
#include <iostream>

class Singleton1st
{
    class autoRelease
    {
    public:
        ~autoRelease()
        {
            std::cout<<__FUNCTION__<<std::endl;
            if (Singleton1st::_restore == nullptr)
                return;
            delete _restore;
            std::cout<<"auto released OK"<<std::endl;
        }
    };
public:
    static Singleton1st* genObj();

private:
    Singleton1st();
    ~Singleton1st();
    Singleton1st(const Singleton1st&);
    static Singleton1st* _restore;
    char _exam[24];
    static autoRelease _auto;
};

class Singleton2ed
{
public:
    static Singleton2ed* genObj();
    static void destroy();

private:
    Singleton2ed();
    ~Singleton2ed();
    Singleton2ed(const Singleton2ed&);
    static Singleton2ed* _restore;
    char _exam[24];
};

class Singleton3rd
{
public:
    static Singleton3rd* genObj();
    static void destroy();

private:
    static void init();
    Singleton3rd();
    ~Singleton3rd();
    Singleton3rd(const Singleton3rd&);
    static Singleton3rd* _restore;
    char _exam[24];
    static pthread_once_t _once;
};

#endif