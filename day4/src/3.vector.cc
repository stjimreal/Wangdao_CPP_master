#include "../include/vector.h"

int main()
{
    vector<int> v(5, 1);
    std::cout<<"value: "<<v<<std::endl;
    std::cout<<"capacity: "<<v.capacity()<<std::endl;
    std::cout<<"size: "<<v.size()<<std::endl;
    v.push_back(53);
    std::cout<<"value: "<<v<<std::endl;
    std::cout<<v.pop()<<" "<<v.pop()<<" "<<v.pop()<<std::endl;
    v.push_back(52);
    std::cout<<"value: "<<v<<std::endl;
    std::cout<<"capacity: "<<v.capacity()<<std::endl;
    std::cout<<"size: "<<v.size()<<std::endl;
    return 0;
}