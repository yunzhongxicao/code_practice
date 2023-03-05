/*
@File  :1047_second.cpp
@Author:dfc
@Date  :2023/2/27  13:33
@Desc  : 删除字符串中的所有相邻重复项
*/
#include "iostream"
#include "stack"
#include "string"

using namespace std;

string removeDuplicates(string s)
{
    stack<char> my_stack;
    for (int i = 0; i <s.length(); ++i) {
        if (!my_stack.empty() and s[i] == my_stack.top())
            my_stack.pop();
        else
        {
            my_stack.push(s[i]);
        }
    }
    string result(my_stack.size(),' ');
    int i =result.size()-1;
    while (!my_stack.empty())
    {
        result[i] = my_stack.top();
        my_stack.pop();
        i--;
    }
    return result;
}

int main()
{
    cout<<removeDuplicates("abbaca");
}

