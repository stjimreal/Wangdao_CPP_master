#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
public:
    MyCin():
    _badbit(false)
    {}
    operator bool()
    {
        return !_badbit;
    }
    template <typename T>
    friend MyCin& operator>>(MyCin& m, T& n)
    {
        if(m._badbit)
            return m;
        cin>>n;
        if(n == -1)
            m._badbit = true;
        return m;
    }
private:
    bool _badbit;

};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
/* 
12 44
344 555
-1
2 3
 */