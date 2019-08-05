#include <iostream>

template <typename T, class T3>
T add(T a, T3 b)
{
    return a + b;
}

void display()
{
    std::cout<<std::endl;
}
template <typename T, typename... args>
void display(T b, args... a)
{
    std::cout<<b<<' ';
    display(a...);
}



int main()
{
    std::cout<< add(4.3, 2)<<std::endl;
    display("adf", 1, 3.45, 23, 5);
    return 0;
}