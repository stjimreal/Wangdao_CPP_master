class Point
{
public:
    Point(double x, double y)
    : _ix(x), _iy(y)
    {}
    Point()
    : _ix(0), _iy(0)
    {}
    
private:
    double _ix, _iy;
};