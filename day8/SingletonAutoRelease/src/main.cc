#include <unistd.h>
#include <sys/wait.h>
#include "../include/singleton.hh"

void *threadFunc(void *num)
{
    Singleton3rd* p = Singleton3rd::genObj();
    std::cout<<p<<' ';
    return nullptr;
}

int main()
{
    Singleton1st* p1 = Singleton1st::genObj();
    Singleton1st* p2 = Singleton1st::genObj();
    Singleton1st* p3 = Singleton1st::genObj();

    std::cout<<p1<<' '<<p2<<' '<<p3<<' '<<std::endl;

    Singleton2ed* p11 = Singleton2ed::genObj();
    Singleton2ed* p12 = Singleton2ed::genObj();
    Singleton2ed* p13 = Singleton2ed::genObj();

    std::cout<<p11<<' '<<p12<<' '<<p13<<' '<<std::endl;

    pthread_t thid[5];
    for (long int i = 0; i < 5; ++i)
    {
        pthread_create(&thid[i], NULL, threadFunc, (void *)i);
    }
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(thid[i], NULL);
    }
    
    std::cout<<std::endl;

    return 0;
}