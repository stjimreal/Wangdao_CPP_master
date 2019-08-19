#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>  
class myclass {
// 在此处补充你的代码
private:
    T* p;
    size_t size;
public:
    myclass(const T* buf, const size_t sz)
    : p(new T[sz]), size(sz)
    {
        memcpy(p, buf, size * sizeof(T));
    }
~myclass( ) {
		delete [] p;
	}
	void Show()
	{
		for( int i = 0;i < size;i ++ ) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100];
int main() {
	char line[100];
	while( cin >> line ) {
		myclass<char> obj(line,strlen(line));;
		obj.Show();
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		myclass<int> obj2(a,n);
		obj2.Show();
	}
	return 0;
}