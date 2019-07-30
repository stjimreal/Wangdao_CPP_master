#include <iostream>
using namespace std;
class A {
	public:
		int i;
		A(int x) { i = x; }
        ~A(){printf("%d\n", i);}
};
int main()
{
	A a(1);
	A * pa = new A(2);
	delete pa;
	return 0;
}