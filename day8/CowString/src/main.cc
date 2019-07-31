#include "../include/FbStrCOW.hxx"

using std::cout;
using std::cin;
using std::endl;
using namespace fbstr;

int main()
{
    const char *p = "Hello";
    String s1 = p, s3;
    String s2 = "World// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const StrddffdsWorld// const Strddffds";
    cout<<s2<<endl;
    // s1 += p;
    // s1 += s2;

    // s1 = s2;
    // s1 = "World// const Strddffds";
    // cout<<s1<<endl;
    // const String s3 = s1 + s2 + p;
    // cout << s1 + p << s3<<endl;
    // cout << p + s2 + s3<<endl;
    // s2 += s3 + s1;
    // cout << (p + s2 + s3).size()<<endl;

    // cout << String(p) + p <<endl;
    // cout << s3[11]<<endl;
    return 0;
}