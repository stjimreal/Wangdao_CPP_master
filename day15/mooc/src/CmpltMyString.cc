#include <cstdlib>
#include <iostream>
using namespace std;
// int strlen(const char * s) 
// {	int i = 0;
// 	for(; s[i]; ++i);
// 	return i;
// }
// void strcpy(char * d,const char * s)
// {
// 	int i = 0;
// 	for( i = 0; s[i]; ++i)
// 		d[i] = s[i];
// 	d[i] = 0;
		
// }
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
// void strcat(char * d,const char * s)
// {
// 	int len = strlen(d);
// 	strcpy(d+len,s);
// }
class MyString
{
// 在此处补充你的代码
public:
	MyString(const void * s)
	{
		if(s) {
			_size = strlen((const char*) s);
			_str = new char[_size + 1];
			strcpy(_str,(const char *)s);
		}
		else{
			_str = nullptr;
			_size = 0;
		}
	}

	MyString()
	: _str(nullptr), _size(0)
	{}

	MyString(const MyString& str)
	{
		_str = new char[str._size + 1];
		strcpy(_str, str._str);
		_size = str._size;
	}

	~MyString()
	{
		if(_str)
			delete []_str;
		_str = nullptr;
	}

	bool operator<(const MyString& args)const
	{
		return strcmp(_str, args._str)<0;
	}
	bool operator==(const MyString& args)const
	{
		return strcmp(_str, args._str) == 0;
	}
	bool operator>(const MyString& args)const
	{
		return strcmp(_str, args._str)>0;
	}

	friend ostream& operator<<(ostream& os, const MyString& str)
	{
		if(str._str)
			os<<str._str;
		return os;
	}

	void reserve(int capacity)
	{
		_str = new char[capacity];
		_size = capacity - 1;
	}

	friend MyString operator+(const MyString& str1, const MyString& str2)
	{
		MyString rtn;
		rtn.reserve(str1._size + str2._size + 1);
		strcpy(rtn._str, str1._str);
		strcat(rtn._str, str2._str);
		return rtn;
	}

	char& operator[](int index)
	{
		return _str[index];
	}

	MyString& operator=(const MyString& str)
	{
		if(_str)
			delete []_str;
		_size = str._size;
		_str = new char[_size + 1];
		strcpy(_str, str._str);
		return *this;
	}

	friend MyString& operator+=(MyString& str1, const char * str2)
	{
		char * tmp = str1._str;
		str1._str = new char[strlen(str2) + str1._size + 1];
		str1._size += strlen(str2);
		if(tmp)
		{
			strcpy(str1._str, tmp);
			strcat(str1._str, str2);
			delete []tmp;
		}
		return str1;	
	}

	MyString operator()(int pos, int len)
	{
		MyString rtn(_str + pos);
		rtn._str[len] = '\0';
		_size = len;
		return rtn;
	}
private:
	char * _str;
	int _size;
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-");
	MyString s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}