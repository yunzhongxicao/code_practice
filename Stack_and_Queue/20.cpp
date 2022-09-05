/*
@File  :20.cpp
@Author:dfc
@Date  :2022/9/4  15:22
@Desc  :ÓÐÐ§µÄÀ¨ºÅ
*/

#include "stack"
#include "string"
#include "iostream"

using namespace std;

bool isValid(string s);

int main()
{
    string s = "([}}])";
    cout<<isValid(s);
}

bool isValid(string s)
{
    if (s.size() % 2!=0) return false;
    stack<char> my_stack;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='(') my_stack.push(')');
        else if (s[i] == '[') my_stack.push(']');
        else if (s[i] == '{') my_stack.push('}');
        else
        {
            if(!my_stack.empty())
            {
                if (s[i] ==my_stack.top())
                {
                    my_stack.pop();
                } else
                {
                    return false;
                }
            } else
            {
                return false;
            }

        }


    }
    return my_stack.empty();
}