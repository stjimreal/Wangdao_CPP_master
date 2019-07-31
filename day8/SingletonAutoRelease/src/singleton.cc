#include <cstring>
#include "../include/singleton.hh"

/* first implementation of autorelease */
Singleton1st::Singleton1st()
:_exam("")
{}

Singleton1st::~Singleton1st()
{}

Singleton1st* Singleton1st::genObj()
{
    if(_restore)
        return _restore;
    _restore = new Singleton1st;
    return _restore;
}

Singleton1st* Singleton1st::_restore = nullptr; //懒汉模式
Singleton1st::autoRelease Singleton1st::_auto;

/* second implementation of autorelease */
Singleton2ed::Singleton2ed()
:_exam("")
{}

Singleton2ed::~Singleton2ed()
{}

Singleton2ed* Singleton2ed::genObj()
{
    if(_restore)
        return _restore;
    _restore = new Singleton2ed;
    ::atexit(Singleton2ed::destroy);
    return _restore;
}

void Singleton2ed::destroy()
{
    if(_restore == nullptr) return;
    std::cout<<"auto released 1 OK"<<std::endl;
    delete _restore;
}

Singleton2ed* Singleton2ed::_restore = Singleton2ed::genObj(); //饿汉模式

/* third implementation of autorelease */
Singleton3rd::Singleton3rd()
:_exam("")
{}

Singleton3rd::~Singleton3rd()
{}

Singleton3rd* Singleton3rd::genObj()
{
    if(_restore)
        return _restore;
    pthread_once(&_once, init);
    return _restore;
}

void Singleton3rd::init()
{
    _restore = new Singleton3rd;
    ::atexit(Singleton3rd::destroy);
}


void Singleton3rd::destroy()
{
    if(_restore == nullptr) return;
    std::cout<<"auto released 2 OK"<<std::endl;
    delete _restore;
}

Singleton3rd* Singleton3rd::_restore = nullptr; //懒汉模式
pthread_once_t Singleton3rd::_once = PTHREAD_ONCE_INIT;