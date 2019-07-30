#include <string.h>
#include <stdio.h>

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
class String
{
public:
    String();
    String(const char *pstr);
    String(const String & rhs);
    String & operator=(const String & rhs);
    ~String();
    void print();

private:
    char * _pstr;
};

String::String()
{
    _pstr = NULL;
}

String::String(const char *pstr)
{
    _pstr = new char[strlen(pstr) + 1];
    strcpy(_pstr, pstr);
}

String::String(const String & rhs)
{
    this->_pstr = new char[strlen(rhs._pstr) + 1];
    strcpy(this->_pstr, rhs._pstr);
}

String::~String()
{
    if(_pstr)
        delete []_pstr;
    _pstr = NULL;
}

String & String::operator=(const String & rhs)
{
    if(&rhs == this) return *this;
    if(_pstr)
        delete []this->_pstr;
    this->_pstr = new char[strlen(rhs._pstr) + 1];

    return *this;
}

void String::print()
{
    printf("%s", this->_pstr);
}

int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
}