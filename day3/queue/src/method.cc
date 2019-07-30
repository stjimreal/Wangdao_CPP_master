#include "../include/queueHead.h"

void queue::push(int x)
{
    linkNode* tmp = new linkNode(x);
    _tail->next = tmp;
    _tail = _tail->next;
    printf("value %d is pushed. Now you have %d members\n", _tail->value, ++_head->value);
}

void queue::pop()
{
    linkNode* tmp = _head -> next;
    if(empty()) return;
    
    printf("value %d is popped. Now you have %d members\n", tmp->value, --_head->value);
    _head -> next = _head -> next -> next;
    delete tmp;
}

int queue::front()
{
    int ret = -1;
    if(empty())
    {
        printf("get value failed\n");
        return ret;
    }
    ret = _head -> next -> value;
    return ret;
}

int queue::back()
{
    int ret = -1;
    if(empty())
    {
        printf("get value failed\n");
        return ret;
    }
    ret = _tail -> value;
    return ret;
}

bool queue::empty()
{
    return _head->value == 0 || _head == _tail;
}

bool queue::full()
{
    return false;
}

queue::~queue()
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