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