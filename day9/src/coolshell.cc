#include <tinyxml2.h>

#include <string>
#include <iostream>

inline void ERROR_CHECK(const int rtn, const int value, const char * funcName) 
{
    if(rtn != value) {perror(funcName);exit(-1);}
}

using namespace tinyxml2;
using std::cin;
using std::cout;
using std::end;
using std::string;

int main()
{
    XMLDocument doc;
	doc.LoadFile( "resources/coolshell.xml" );
    ERROR_CHECK(doc.ErrorID(), XML_SUCCESS, "LoadFile");
    
    return 0;
}