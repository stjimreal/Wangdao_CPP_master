#include <iostream>

// > 元素入栈     `void push(int);`
// > 元素出栈     `void pop();`
// > 读出栈顶元素 `int top();`
// > 判断栈空     `bool emty();`
// > 判断栈满    `bool full();`

// 如果栈溢出，程序终止。栈的数据成员由存放10个整型数据的数组构成。先后做如下操作：

// > 创建栈
// > 将10入栈
// > 将12入栈
// > 将14入栈
// > 读出并输出栈顶元素
// > 出栈
// > 读出并输出栈顶元素
struct linkNode
{
    int value;
    linkNode* next;
    linkNode(int x = 0):value(x), next(nullptr){}
};

class stack
{
    linkNode* _top;
    public:
    stack(){_top = new linkNode();}
    stack(const stack &x):_top(x._top){}
    void push(int a)
    {
        auto tmp = new linkNode(a);
        tmp->next = _top->next;
        _top->next = tmp;
        printf("value %d pushed\n", tmp->value);
        ++_top->value;
        print();
    }
    int pop()
    {
        if(0 >= _top->value || nullptr == _top->next)
        {
            printf("pop failure\n");
            return -1;
        }
        --_top->value;
        auto tmp = _top->next;
        int x = -1;
        if(_top->next)
        {
            x = tmp->value;
            _top->next = _top->next->next;
            delete tmp;
            printf("value %d popped\n", x);
        }
        print();
        return x;
    }
    int top()
    {
        if(0 < _top->value && _top->next)
        {
            return _top->next->value;
        } else {
            printf("top failure\n");
            return -1;
        }
    }
    void print()
    {
        linkNode *ptr = _top;
        printf("%d: ", ptr->value);
        ptr = ptr->next;
        while(ptr)
        {
            printf("%d ", ptr->value);
            if(ptr -> next)
                printf("-> ");
            ptr = ptr->next;
        }
        printf("\n");
    }
    ~stack()
    {
        printf("%s function called\n", __FUNCTION__);
        while(_top->next)
            pop();
        delete _top;
    }
};

int main()
{
    stack ss1;
    int a;
    a = 10;ss1.push(a);
    a = 12;ss1.push(a);
    a = 14;ss1.push(a);
    int top = ss1.top();
    std::cout<<"top = "<<top<<std::endl;
    ss1.pop();
    top = ss1.top();
    std::cout<<"top2 = "<<top<<std::endl;
    return 0;
}