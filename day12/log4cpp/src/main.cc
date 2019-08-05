#include "../include/log4cpp_head.hh"




void test() {
    int number = 100;
    const char * pstr = "hello, log4cpp";
    Log::LogInfo("this is an info message. number = %d, str = %s\n", number, pstr);
}

int main()
{
    Log::genObj();
    test();
    return 0;
}


