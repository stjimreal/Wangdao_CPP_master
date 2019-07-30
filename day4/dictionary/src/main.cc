#include "../incl/head.h"

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
    ARGS_CHECK(argc, 2);
    map<string, int> dictionary;
    ifstream file(argv[1], std::ios_base::in);
    string word;
    while(!file.eof())
    {
        word = getWord(file);
        ++dictionary[word];
    }
    map<string, int>::iterator it = dictionary.begin();
    if(it->first.empty())
        ++it;
    for(; it != dictionary.end(); ++it)
    {
        printf("%-20s %d\n", it->first.c_str(), it->second);
    }
    file.close();
    return 0;
}