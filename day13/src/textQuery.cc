#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <unordered_map>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::map;
using std::vector;
using std::pair;
using std::set;

class TextQuery
{
public:
    void readFile(const string &filename);
    void query(const string & word);
    TextQuery()
    : _lines(), _word2Line(), _dict()
    {}
    ~TextQuery()
    {
        
    }
private:
    vector<string> _lines;
    map<string, set<int>> _word2Line;
    map<string, int> _dict;

};

string getWord(std::istream &file);

void TextQuery::readFile(const string &filename)
{
    std::ifstream file(filename, std::ios_base::in);
    string line, word;
    char ch;
    size_t i = 0;
    while(file.get(ch) && !file.eof())
    {
        if(ch == '\n')
        {
            ++i;
            std::istringstream strStream(line);
            do
            {
                word = ::getWord(strStream);
                ++_dict[word];
                _word2Line[word].insert(i);
            }while(word.empty() == false);
            _lines.push_back(line);
            line.clear();
        } else {
            line.push_back(ch);
        }
    }
    file.close();

}

void TextQuery::query(const string & word)
{
    printf("%s occurs %d times\n", word.c_str(), _dict[word]);
    for(auto it = _word2Line[word].begin(); it != _word2Line[word].end(); ++it)
    {
        printf("\t(line %d) ", *it);
        cout<<_lines[*it - 1]<<endl;
    }
}


//程序测试用例
int main(int argc, char *argv[])
{
    TextQuery tq;
    string route;
    cout<<"route"<<endl;
    std::cin>>route;
    tq.readFile(route);
    while(1)
    {
        string queryWord;
        
        cout<<"word"<<endl;
        std::cin>>queryWord;
        tq.query(queryWord);
    }

    return 0;
}

string getWord(std::istream &file)
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