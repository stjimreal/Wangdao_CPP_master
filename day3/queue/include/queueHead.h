#ifndef _QUEUE_HEAD_H
#define _QUEUE_HEAD_H
#include <iostream>
struct linkNode
{
    int value;
    linkNode* next;
    linkNode(int x = 0):value(x), next(nullptr){}
};

class queue
{
    linkNode* _head, *_tail;
    
public:
    queue(){_tail = _head = new linkNode;}
    queue(const queue &x):_head(x._head), _tail(x._tail){}

    /* 元素入队  */
    void push(int);
    /* 元素出队 */
    void pop();
    /* 读取队头元素 */
    int front();
    /* 读取队尾元素 */
    int back();
    /* 判断队列是否为空 */
    bool empty();
    /* 判断队列是否已满 */
    bool full();
    
    ~queue();
};

#endif