//  编写一个圆类Circle，该类拥有： 
// 		① 1个成员变量，存放圆的半径；
// 		② 两个构造方法
// 	 			Circle( )              // 将半径设为0           
// 	 			Circle(double  r )     //创建Circle对象时将半径初始化为r      
// 		③ 三个成员方法              
// 				double getArea( )      //获取圆的面积            
// 				double getPerimeter( ) //获取圆的周长              
// 				void  show( )          //将圆的半径、周长、面积输出到屏幕

#include <iostream>

#define PI 3.141592654
using std::endl;
using std::cin;
using std::cout;

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

private:
    double _radius;

};

// int main()
// {

//     return 0;
// }