#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>

using std::string;
using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::stack;
using std::set;

/* 
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:  

1. Only one letter can be changed at a time.  
2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.  
Note:  
• Return 0 if there is no such transformation sequence.  
• All words have the same length.  
• All words contain only lowercase alphabetic characters.  
• You may assume no duplicates in the word list.  
• You may assume beginWord and endWord are non-empty and are not the same.  
Example 1:  
Input:  
beginWord = "hit",  
endWord = "cog",  
wordList = ["hot","dot","dog","lot","log","cog"]  
Output: 5  
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",  
return its length 5.  
Example 2:  
Input:  
beginWord = "hit"  
endWord = "cog"  
wordList = ["hot","dot","dog","lot","log"]  
Output: 0  
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
    public:
    int ladderLength(string beginWord, string endWord, const vector<string>& wordList) 
    {
        vector<string>::const_iterator it;
        for(it = wordList.begin(); it != wordList.end(); ++it)
        {
            if(*it == endWord)
                break;
        }
        if(it == wordList.end())
            return 0;

        set<string> foundset;
        vector<string> stack;
        stack.push_back(beginWord);
        int cnt, dist = 1, shortest = 0;
        int size;
        string word;

        while(!stack.empty())
        {
            word = stack.back();
            stack.pop_back();
            /* 找只有一个不同字母的单词 */
            for(it = wordList.begin(); it != wordList.end(); ++it)
            {
                cnt = 0;
                size = it->size();
                if(foundset.find(*it) != foundset.end())
                    continue;
                for (int i = 0; i < size; ++i)
                {
                    if((*it)[i] != word[i])
                        ++cnt;
                }
                if(cnt == 1)
                    stack.push_back(*it);
            }
            printf("%s\n", word.c_str());

            /* 判断是否找不到了 */
            foundset.insert(*it);
            word = *it;
            ++dist;
            if(*it == endWord)
                break;
        }
        return shortest;
    }
};

int main()
{
    Solution a;
    vector<string> x = {"hot","dot","dog","lot","log","cog"};
    cout<<a.ladderLength("hit", "cog", x)<<endl;
    return 0;
}