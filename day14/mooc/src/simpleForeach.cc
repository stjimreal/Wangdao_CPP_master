#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <typename T>
void MyForeach(T* beg, T* end, void(* func)(T&))
{
    auto iter = beg;
    for(;iter != end; ++iter)
    {
        func(*iter);
    }
}

template <typename T>
void MyForeach(T* beg, T* end, void(* func)(T))
{
    auto iter = beg;
    for(;iter != end; ++iter)
    {
        func(*iter);
    }
}

void Print(string s)
{
	cout << s;
}
void Inc(int & n)
{
	++ n;
}
string arr[100];
int a[100];
int main() {
	int m,n;
	while(cin >> m >> n) {
		for(int i = 0;i < m; ++i)
			cin >> arr[i];
		for(int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(arr,arr+m,Print);		 
		cout << endl;
		MyForeach(a,a+n,Inc);		 
		for(int i = 0;i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}