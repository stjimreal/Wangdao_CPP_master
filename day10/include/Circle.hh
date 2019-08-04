#ifndef __UNIV_HEAD_HH
#define __UNIV_HEAD_HH
#include <iostream>

using std::endl;
using std::cin;
using std::cout;
#endif

#ifndef __CIRCLE_HH
#define __CIRCLE_HH

#define PI 3.141592654

class Circle
{
public:
    Circle()
    : _radius(0)
    {}
    Circle(double r)
    : _radius(r)
    {}

    double getArea()
    {
        return _radius * _radius * PI;
    }
    double getPerimeter()
    {
        return 2 * PI * _radius;
    }

    void show()
    {
        cout<<_radius<<' '<<getPerimeter()<<' '<<getArea();
    }

private:
    double _radius;
};
#endif