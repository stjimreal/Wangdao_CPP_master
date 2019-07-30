#include "../include/log4cpp_head.hh"

using std::cout;
using std::endl;

class Log
{
public:

    static Log* genObj();
    static void destroy();
    log4cpp::Category& _root;
    log4cpp::Category& fatal;
    log4cpp::Category& warn;
    log4cpp::Category& debug;
    friend inline void prt(void(*f)(const char* Format, ...), const char * str);

private:
    Log();
    ~Log();

    static Log* _restore;
};

Log* Log::_restore = nullptr;

Log::Log():
    _root(log4cpp::Category::getRoot()),
    fatal(log4cpp::Category::getInstance(std::string("fatal"))),
    warn(log4cpp::Category::getInstance(std::string("warn"))),
    debug(log4cpp::Category::getInstance(std::string("debug")))
    {}

Log::~Log(){}

Log* Log::genObj()
{
    if(_restore)
        return _restore;
    try
    {
        PropertyConfigurator::configure("./config/log4cpp.conf");
    }
    catch(ConfigureFailure& f)
    {
        std::cerr << f.what() << '\n';
        return (Log *)-1;
    }
    _restore = new Log;
    return _restore;
}

void Log::destroy()
{
    if(_restore ==nullptr) return;
    delete _restore;
    Category::shutdown();
    _restore = nullptr;
}

inline void prt(void(*f)(const char* Format, ...), const char * str)
{
    f("%s --%s--%s--%d--", str, __FILE__, __FUNCTION__, __LINE__);
}

#define prt(func, string) func("%s --%s--%s--%d--", x.c_str(), __FILE__, __FUNCTION__, __LINE__)

int main()
{
    Log* pLog = Log::genObj();
    std::string x = "Hello";
    x += " No Way";
    prt(pLog->debug.info, x.c_str());
    prt(pLog->debug.debug, x.c_str());
    prt(pLog->debug.emerg, x.c_str());
    prt(pLog->fatal.error, x.c_str());
    prt(pLog->fatal.fatal, x.c_str());
    Log::destroy();
    return 0;
}