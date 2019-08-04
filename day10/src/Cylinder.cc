#include "../include/Circle.hh"

class Cylinder: protected Circle
{
public:
    Cylinder (double r, double  h) //创建Circle对象时将半径初始化为r
    : Circle(r), _height(h){}
    double getVolume() //获取圆柱体的体积
    {
        return getArea() * _height;
    }
    void  showVolume() //将圆柱体的体积输出到屏幕
    {
        Circle::show();
        cout<<' '<<getVolume();
    }
private:
    double _height;
};
 
        
int main()
{
    Cylinder cc(4.1, 3.7);
    cc.showVolume();
    cout<<endl;
    return 0;
}