#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
    friend istream& operator>>(istream& is, Point& p)
    {
        return is>>p.x>>p.y;
    }
    friend ostream& operator<<(ostream& os, const Point& p)
    {
        return os<<p.x<<','<<p.y;
    }
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}