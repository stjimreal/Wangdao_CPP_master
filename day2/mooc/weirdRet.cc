#include <iostream>
using namespace std;
// 在此处补充你的代码
int &
getElement(int * a, int i)
{
	return a[i];
}
int main()
{
	int a[] = {1,2,3};
	getElement(a,1) = 10;
	cout << a[1] ;
	return 0;
}