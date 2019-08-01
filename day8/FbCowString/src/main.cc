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
    s3 = "World// const Strddffd";
    cout<<"s2 ====== size = "<<s2.size()<<endl;
    cout<<s2<<endl;

    s1 += p;
    cout<<"s1 ====== size = "<<s1.size()<<endl;
    cout<<s1<<endl;
    s1 += s3;
    cout<<"s1 ====== size = "<<s1.size()<<endl;
    cout<<s1<<endl;
    s1 += s2;
    cout<<"s1 ====== size = "<<s1.size()<<endl;
    cout<<s1<<endl;

    cout << p + s2 + s3<<endl;
    s2 += s3 + s1;

    s3 = s2;
    s1 = s2;
    cout << s3[0]<<endl;
    cout<<(s2[0] = 'q')<< endl;
    cout<<(s1[0] = s1[0] + 1) << endl;
    return 0;
}