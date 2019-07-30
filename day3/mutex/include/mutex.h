#include <pthread.h>

#include <iostream>

class MutexLock
{
public:
    //...
    void lock();
    void unlock();
    pthread_mutex_t* getLock();
    MutexLock();
    ~MutexLock();
private:
    //...
    pthread_mutex_t _lock;
};

class Condition
{
public:
    //...
    void wait();
    void notify();
    void notifyall();
    Condition(MutexLock&);
    ~Condition();
private:
    //...
    MutexLock &_condLock;
    pthread_cond_t _cond;
};