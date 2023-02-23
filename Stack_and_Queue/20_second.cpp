/*
@File  :20_second.cpp
@Author:dfc
@Date  :2023/2/23  11:07
@Desc  : 有效的括号
*/
#include "iostream"
#include "string"
#include "stack"
using namespace std;

bool isValid(string s)
{
    stack<char> my_stack;
    for (int i = 0; i < s.size(); ++i) {
        // 首先明确 左括号入栈 右括号只负责出栈 不进入栈里面
        if (s[i] == '(') my_stack.push(')');
        else if (s[i] == '{') my_stack.push('}');
        else if (s[i] == '[') my_stack.push(']');

        else if (my_stack.empty() or my_stack.top() != s[i])
            return false;
        else my_stack.pop(); // 相等抵消
    }
    return my_stack.empty();
}


