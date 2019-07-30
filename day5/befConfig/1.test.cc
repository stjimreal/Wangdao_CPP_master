#include "./include/log4cpp_head.hh"
#include <iostream>
#include <queue>

/* 
typedef enum {
    EMERG  = 0, 
    FATAL  = 0,
    ALERT  = 100,
    CRIT   = 200,
    ERROR  = 300, 
    WARN   = 400,
    NOTICE = 500,
    INFO   = 600,
    DEBUG  = 700,
    NOTSET = 800
} PriorityLevel;
*/


using std::cout;
using std::endl;
using std::cin;
using std::queue;
using std::string;

/* 封装设计输出格式 */
#define setLayout(append) {    PatternLayout* pLayout = new PatternLayout(); \
    pLayout->setConversionPattern("\"%m\"  %c [%p] %x %d{%d %m %Y %H:%M:%S}%n");  \
    append->setLayout(pLayout);}

int main()
{
    /* Appender绑定输出途径，常用的有IO流，string队列，log文件 */
    StringQueueAppender* strApp = new StringQueueAppender("strApp");
    OstreamAppender* osAppend = new OstreamAppender("osAppend", &cout);
    RollingFileAppender* rfApp = new RollingFileAppender("rfApp", "verbose.log", 1024, 5);

    /* 设置输出格式 */
    setLayout(strApp);
    setLayout(osAppend);
    setLayout(rfApp);

    /* Category设置Category记录的从属，流绑定以及信息分类 */
    Category& rt = Category::getRoot();
    Category& infoCat1 = rt.getInstance("infoCat1");
    
    infoCat1.addAppender(osAppend);
    infoCat1.addAppender(rfApp);
    infoCat1.setPriority(Priority::DEBUG);

    rt.addAppender(strApp);
    rt.setPriority(Priority::EMERG);

    infoCat1.info("Minimum error! ===%s==%d===", __FUNCTION__, __LINE__);
    infoCat1.debug("No gateway");
    rt.warn("SYSTEM FATAL ERROR!");
    rt.emerg("No way!");
    // infoCat1.removeAppender(osAppend);

    /* 获取信息队列，防止在多线程中多次中断开启I/O系统调用 */
    cout<<"Get msg from Memory Queue!"<<endl;
    cout<<"````````````````````````````"<<endl;
    queue<string>& Str = strApp->getQueue();
    while(!Str.empty())
    {
        cout<<Str.front();
        Str.pop();
    }
    cout<<"````````````````````````````"<<endl;
    /* 输出滚动日志 */
    for (int i = 0; i < 10; i++)
    {
        infoCat1.info("Something error ===%s===%s===%d===", __FUNCTION__, __FILE__, __LINE__);
    }

    Category::shutdown();
    return 0;
}