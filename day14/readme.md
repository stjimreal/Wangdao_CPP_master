# C++ day14

## 问答题

### 1. 迭代器的种类有哪些？他们各自的功能是什么？为什么要定义这么多种类

![picture](1.png)

输入：为程序需要数据源提供接口，数据源可以是容器，数据流等，输入迭代器只能从一个序列读入数据，此类迭代器可以被修改，引用并进行比较。  

输出： 用于输出程序中得到的结果，输出迭代器只能向一个序列输出数据，此类迭代器可以被修改和引用。  

前向：可以随意访问序列中的元素，可以用来读，也可写。并能保存迭代器的值，以便重新从原先位置开始遍历。  

双向： 能够读写，也可被增值和减值，同时进行前向和逆向操作，所有stl都提供双向迭代器；  

随机访问： 可以通过跳跃的方式访问容器中的任意数据，访问数据灵活。具有双向迭代器所有功能，冰球能使用算法和所有迭代器的比较功能。  

### 2. 通过阅读迭代器源码的方式来理解迭代器，如

> ostream_iterator  
> istream_iterator  
> back_insert_iterator

### 3. 什么是适配器模式？STL中有哪些适配器

## 代码题

### 1. Leetcode 20 Valid Parentheses -->stack

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.  
An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.  
Example 1:  
Input: "()"Output: true  
Example 2:  
Input: "()[]{}"Output: true  
Example 3:  
Input: "(]"Output: false  
Example 4:  
Input: "([)]"Output: false  
Example 5:  
Input: "{[]}"Output: true  

```cpp
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    stack<char, std::vector<char> > stack;
    char ch, check;
    while(!cin.eof())
    {
        cin.get(ch);
        if(ch == ']' || ch == '}' || ch == ')')
        {
            check = stack.top();
            if(stack.empty()||(ch == ']' && check != '[')|| (ch == '}' && check != '{') || (ch == ')' && check != '('))
            {
                cout<<"false"<<endl;
                return 0;
            }
            stack.pop();
        }
        if(ch == '{' || ch == '(' || ch == '[')
        {
            stack.push(ch);
        }
    }
    cout<<"true"<<endl;
    return 0;
}
```

### 2. Leetcode 127 Word Ladder ❌

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

```cpp
class Solution {
    public:
    int ladderLength(string beginWord,
        string endWord,
        const vector<string>& wordList) {
    }
};
```

### 3. 完成C++ primer(第5版)中的15.9节的文本查询程序扩展,即使不自己实现, 最好也要照着书敲一遍代码,在机器上让程序跑起来, 也会让你对面向对象设计有新的理解.[慢慢做]
