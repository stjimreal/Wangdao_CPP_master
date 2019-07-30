#include "../include/mutex.h"
#define N 40000000
#include <unistd.h>
MutexLock mutex;
Condition cond(mutex);

void *threadFunc(void *p)
{
    int &sum = *(int *)p;
    int x = 0;
    while(N > sum)
    {
        mutex.lock();
        ++sum;
        mutex.unlock();
        ++x;
    }
    printf("subThread got %d calculated into sum.\n", x);
    pthread_exit(NULL);
}

void clean(void *p)
{
    MutexLock &mutex = *(MutexLock *)p;
    mutex.unlock();
}

void *threadEat(void *p)
{
    int &apple = *(int *)p;
    while(1)
    {
        sleep(1);
        mutex.lock();
        pthread_cleanup_push(clean, &mutex);
        if(0 == apple)
            cond.wait();
        --apple;
        printf("Ate an apple. Now %d apple left.\n", apple);
        pthread_cleanup_pop(0);
        mutex.unlock();
    }
}

int main()
{
    int sum = 0;
    pthread_t thid, thid2;
    pthread_create(&thid, NULL, threadFunc, (void *)&sum);
    int x = 0;
    while(N > sum)
    {
        mutex.lock();
        ++sum;
        mutex.unlock();
        ++x;
    }
    printf("mainThread got %d calculated into sum.\n", x);
    pthread_join(thid, nullptr);

    int apple = 10;
    pthread_create(&thid, NULL, threadEat, (void *)&apple);
    pthread_create(&thid2, NULL, threadEat, (void *)&apple);

    int cnt = 0;
    while(1)
    {
        sleep(3);
        if(0 >= apple)
        {
            apple += 10;
            cond.notify();
        }
        ++cnt;
        if(cnt >=2)
        {
            cond.notifyall();
        }
    }

    return 0;
}