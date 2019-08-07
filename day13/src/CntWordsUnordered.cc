#include <sys/time.h>
#include <time.h>
#include "../include/log4cpp_head.hh"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

string getWord(ifstream &file)
{
    string str;
    char ch;
    do
    {
        file.get(ch);
    }while(isalpha(ch) == 0 && !file.eof());
    while(isalpha(ch) && !file.eof())
    {
        str.push_back(ch);
        file.get(ch);
    }
    return str;
}

int main(int argc, const char * argv[])
{
    unordered_map<string, int> dictionary;
    ifstream file(argv[1], ios_base::in);
    string word;
    timeval begin, end;
    gettimeofday(&begin, NULL);
    while(!file.eof())
    {
        word = getWord(file);
        ++dictionary[word];
    }
    unordered_map<string, int>::iterator it = dictionary.begin();
    if(it->first.empty())
        ++it;
    gettimeofday(&end, NULL);
    Log::genObj();
    Log::LogInfo("used time = %ld ---%s\n", (end.tv_sec - begin.tv_sec) * 1000000 + end.tv_usec - begin.tv_usec, __FILE__);
    for(; it != dictionary.end(); ++it)
    {
        printf("%-20s %d\n", it->first.c_str(), it->second);
    }
    file.close();
    return 0;
}