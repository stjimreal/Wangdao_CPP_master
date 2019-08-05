#define __QUEUE_METHOD_TCC
#include "queueHead.hh"

template <class T> void queue<T>::push(T x)
{
    linkNode* tmp = new linkNode(x);
    _tail->next = tmp;
    _tail = _tail->next;
    printf("value ");
    std::cout<<_tail->value;
    printf(" is pushed. Now you have %d members\n", ++_size);
}

template <class T> void queue<T>::pop()
{
    if(empty()) return;
    linkNode* tmp = _head -> next;
    
    printf("value ");
    std::cout<<tmp->value;
    printf(" is poped. Now you have %d members\n", --_size);
    _head -> next = _head -> next -> next;
    delete tmp;
}

template <class T> T queue<T>::front()
{
    T ret;
    if(empty())
    {
        printf("get value failed\n");
        return T();
    }
    ret = _head -> next -> value;
    return ret;
}

template <class T> T queue<T>::back()
{
    T ret;
    if(empty())
    {
        printf("get value failed\n");
        return T();
    }
    ret = _tail -> value;
    return ret;
}

template <class T> bool queue<T>::empty()
{
    return _size == 0;
}

template <class T> bool queue<T>::full()
{
    return false;
}

template <class T> queue<T>::~queue()
{
    printf("%s function called\n", __FUNCTION__);
    while(1)
    {
        if(empty())
        {
            delete _head;
            break;
        }
        pop();
    }
}