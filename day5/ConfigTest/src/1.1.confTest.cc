#include "../include/log4cpp_head.hh"
#include <iostream>
#include <queue>

using std::string;
using std::cout;
using std::queue;
using std::endl;

int main()
{
    try
    {
        PropertyConfigurator::configure("./config/test.conf");
    }
    catch(ConfigureFailure& f)
    {
        std::cerr << f.what() << '\n';
        return -1;
    }

    log4cpp::Category& root = log4cpp::Category::getRoot();
    log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
    log4cpp::Category& sub2 = log4cpp::Category::getInstance(std::string("sub2"));
    log4cpp::Category& sub3 = log4cpp::Category::getInstance(std::string("sub3"));
    // log4cpp::Category& sub4 = log4cpp::Category::getInstance(std::string("sub4"));

     //    正常使用这些category对象进行日志处理。
    root.fatal("root's log");

    //    sub1 has appender A1 and rootappender. since the additivity property is set true by default
    sub1.info("sub1's log");

    //    sub2 has appender A2 appender. since the additivity property is set to false
    sub2.alert("sub2's log");

    //    sub3 only has A3 appender. since the additivity property is set to false
    sub3.debug("sub3's log");
    sub3.alert("sub3's log");

    // //    sub4 can not be found in the config file, so the root category's appender and layout are used
    // sub4.warn("sub4's log");
    return 0;
}