#ifndef __QUEUE_HEAD_H
#define __QUEUE_HEAD_H
#include <iostream>

template <class T>
class queue
{
    struct linkNode
    {
        T value;
        linkNode* next;
        linkNode():value(T()), next(nullptr){}
        linkNode(T x):value(x), next(nullptr){}
    };
    linkNode* _head, *_tail;
    int _size;
public:
    queue(){_tail = _head = new linkNode;_size = 0;}
    queue(const queue &x):_head(x._head), _tail(x._tail){}

    /* 元素入队  */
    void push(T);
    /* 元素出队 */
    void pop();
    /* 读取队头元素 */
    T front();
    /* 读取队尾元素 */
    T back();
    /* 判断队列是否为空 */
    bool empty();
    /* 判断队列是否已满 */
    bool full();
    
    ~queue();
};
#endif

#ifndef __QUEUE_METHOD_TCC
#define __QUEUE_METHOD_TCC
#include "./method.tcc"
#endif