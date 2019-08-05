#include "../include/singletonTemp.hh"
#include "../include/Computer.hh"
#include "../include/Point.hh"

Point pt(1, 2);
Point pt2(3, 4);

Computer com("Mac", 8888);

int main(void)
{
Computer * p1 = Singleton<Computer>::getInstance("Xiaomi", 6666);
Computer * p2 = Singleton<Computer>::getInstance("Xiaomi", 6666);
printf("p1 address = %p, p2 address = %p\n", p1, p2);

Point　* p3 = Singleton<Point>::getInstance(1, 2);
Point　* p4 = Singleton<Point>::getInstance(1, 2);
printf("p3 address = %p, p4 address = %p\n", p3, p4);

return 0;
}