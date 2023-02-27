/*
@File  :150_second.cpp
@Author:dfc
@Date  :2023/2/27  13:43
@Desc  : 逆波兰表达式求值
*/
#include "iostream"
#include "vector"
#include "string"
#include "stack"
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> my_stack;
    for (int i = 0; i < tokens.size(); ++i) {
        string temp = tokens[i];
        if (temp == "+" or temp=="-" or temp=="*" or temp=="/")
        {
            int a = my_stack.top();
            my_stack.pop();
            int b = my_stack.top();
            my_stack.pop();
            int c;
            if (temp=="+")
                c = b+a;
            if (temp=="-")
                c = b-a;
            if (temp=="*")
                c = b *a;
            if (temp=="/")
                c = b / a;
            my_stack.push(c);
        }
        else
            my_stack.push(stoi(temp));
    }
    return my_stack.top();
}


