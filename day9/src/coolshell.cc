#include <tinyxml2.h>
#include <string>
#include <iostream>
#include <vector>
#include <boost/regex.hpp>

inline void ERROR_CHECK(const int rtn, const int value, const char * funcName) 
{
    if(rtn != value) {perror(funcName);exit(-1);}
}

inline void ARGS_CHECK(const int rtn, const int value) 
{
    if(rtn != value) {printf("Wrong Args!\n");exit(-1);}
}

using namespace tinyxml2;
using std::cin;
using std::cout;
using std::end;
using std::string;
using std::vector;
using boost::regex;

struct RssItem
{
    string title;
    string link;
    string description;
    string content;
};

class RssReader
{
public:
    RssReader();

    void parseRss();//解析
    void dump(const string & filename);//输出
private:
    vector<RssItem> _rss;
};


int main(const int argc, const char ** argv)
{
    ARGS_CHECK(argc, 2);
    XMLDocument doc;
	doc.LoadFile( argv[1] );
    ERROR_CHECK(doc.ErrorID(), XML_SUCCESS, "LoadFile");
    printf("title = %s\n", doc.RootElement()->FirstChildElement("channel")->FirstChildElement("title")->GetText());

    XMLElement* item = nullptr;
    item = doc.RootElement()->FirstChildElement("channel")->FirstChildElement("item");
    int cnt = 0;
    while(item)
    {
        printf("NO = %d\n", ++cnt);
        XMLElement* titleEle = item->FirstChildElement("title");
        printf("title = %s\n", titleEle->GetText());
        XMLElement* linkEle =  item->FirstChildElement("link");
        printf("link = %s\n", linkEle->GetText());
        XMLElement* descriEle = item -> FirstChildElement("description");
        printf("description =%s\n", descriEle->GetText());
        // XMLElement* contentEle = item -> FirstChildElement("content:encoded");
        // printf("content =%s\n", contentEle->GetText()); //用boost库匹配正则表达式得到干净的纯文本
        item = item->NextSiblingElement();
    }

    return 0;
}