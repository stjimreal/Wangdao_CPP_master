// #include <iostream>
#include "../include/queueHead.h"
#include <bits/stdc++.h>
int main()
{
    queue sq2;
    int a;
    a = 10;sq2.push(a);
    a = 12;sq2.push(a);
    a = 14;sq2.push(a);
    int front = sq2.front();
    std::cout<<"front = "<<front<<std::endl;
    sq2.pop();
    front = sq2.front();
    std::cout<<"front2 = "<<front<<std::endl;
    int tail = sq2.back();
    std::cout<<"back = "<<tail<<std::endl;

    return 0;
}