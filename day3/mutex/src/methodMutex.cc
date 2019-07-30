#include "../include/mutex.h"

MutexLock::MutexLock()
{
    pthread_mutex_init(&_lock, NULL);
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&_lock);
}

void MutexLock::lock()
{
    pthread_mutex_lock(&_lock);
}

void MutexLock::unlock()
{
    pthread_mutex_unlock(&_lock);
}

pthread_mutex_t* MutexLock::getLock()
{
    return &_lock;
}