#include "../include/mutex.h"

Condition::Condition(MutexLock &x):_condLock(x)
{
    
    pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
    pthread_cond_destroy(&_cond);
}

void Condition::notify()
{
    pthread_cond_signal(&_cond);
}

void Condition::notifyall()
{
    pthread_cond_broadcast(&_cond);
}

void Condition::wait()
{
    pthread_cond_wait(&_cond, _condLock.getLock());
}

