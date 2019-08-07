#ifndef _LOG4CPP_HEAD_HH
#define _LOG4CPP_HEAD_HH

#include <pthread.h>

#include <string>
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/StringQueueAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

using namespace log4cpp;

#define log4cpp_prt(func, string) func("%s --%s--%s--%d--", x.c_str(), __FILE__, __FUNCTION__, __LINE__)
using std::cout;
using std::endl;

class Log
{
public:
    template <typename ...T> static void LogInfo(const char *str, const T&...args)
    {
        _restore->debug.info(str, args...);
    }
    static Log* genObj();
    static void destroy();

    log4cpp::Category& fatal;
    log4cpp::Category& warn;
    log4cpp::Category& debug;

private:
    static void init();
    Log();
    ~Log();
    log4cpp::Category& _root;
    static Log* _restore;
    static pthread_once_t _auto;
};

Log* Log::_restore = nullptr;
pthread_once_t Log::_auto = PTHREAD_ONCE_INIT;

Log::Log():
    fatal(log4cpp::Category::getInstance(std::string("fatal"))),
    warn(log4cpp::Category::getInstance(std::string("warn"))),
    debug(log4cpp::Category::getInstance(std::string("debug"))),
    _root(log4cpp::Category::getRoot())
    {}

Log::~Log(){}

Log* Log::genObj()
{
    if(_restore)
        return _restore;
    pthread_once(&_auto, init);
    return _restore;
}

void Log::init()
{
    try
    {
        PropertyConfigurator::configure("./config/log4cpp.conf");
    }
    catch(ConfigureFailure& f)
    {
        std::cerr << f.what() << '\n';
        exit(-1);
    }
    _restore = new Log;
    ::atexit(destroy);
}

void Log::destroy()
{
    if(_restore ==nullptr) 
        return;
    Category::shutdown();
    delete _restore;
}
#endif