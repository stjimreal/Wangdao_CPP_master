#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <algorithm>
#include <map>

using std::cout;
using std::vector;
using std::cin;
using std::list;
using std::unordered_map;
using std::queue;
using std::unordered_set;
using std::endl;
using std::string;

class Solution {
public:
    Solution()
    : _wordList(), _targetList()
    {}
    int ladderLength(const string& begWord, const string& endWord, const vector<string> &set)
    {
        if(std::find(set.begin(), set.end(), endWord) == set.end())
            return 0;
        _wordList.clear();
        for(auto &mem: set)
        {
            string word;
            auto len = mem.size();
            for(int i = 0; i < len; ++i)
            {
                word = mem;
                word[i] = '*';
                _wordList[word].push_back(mem);
            }
        }
#ifndef NDEBUG
        cout<<"_wordHashList:"<<endl;
        for(auto &mem: _wordList)
        {
            cout<<mem.first<<' ';
            for(auto &word: mem.second)
            {
                cout<<word<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
#endif

        /* 先把word化为通用的替换word */
        int depth = 0;
        _targetList.emplace(begWord, 1);
        string target, copy;
        while(!_targetList.empty())
        {
            depth = _targetList.front().second + 1;
            // cout<<"depth = "<<depth<<endl;
            target = _targetList.front().first;
            _targetList.pop();
            for(int i = 0; i < target.size(); ++i)
            {
                copy = target;
                copy[i] = '*';
                if(_wordList.find(copy) == _wordList.end())
                    continue;
                for(auto iter = _wordList[copy].begin(); iter != _wordList[copy].end();)
                {
                    auto &mem = *iter;
                    // cout<<mem<<' ';
                    if(mem == endWord)
                        return depth;
                    _targetList.push(make_pair(mem, depth));
                    iter = _wordList[copy].erase(iter);
                }
                // cout<<endl;
            }
            // cout<<endl;
        }
        return 0;
    }

private:
    unordered_map<string, list<string> > _wordList;
    queue<std::pair<string, int> > _targetList;
};

int main()
{
    Solution a;
    vector<string> x = {"hot","dot","dog","lot","log", "cog"};
    cout<<a.ladderLength("hit", "cog", x)<<endl;
    return 0;
}