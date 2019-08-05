#include "../include/queueHead.hh"

int main()
{
    queue<std::string> sq2;
    std::string a;
    a = "10";sq2.push(a);
    a = "12";sq2.push(a);
    a = "14";sq2.push(a);
    std::string front = sq2.front();
    std::cout<<"front = "<<front<<std::endl;
    sq2.pop();
    front = sq2.front();
    std::cout<<"front2 = "<<front<<std::endl;
    a = "15";sq2.push(a);
    a = "16";sq2.push(a);
    std::string tail = sq2.back();
    std::cout<<"back = "<<tail<<std::endl;

    return 0;
}