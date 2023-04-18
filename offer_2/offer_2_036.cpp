/*
@File  :offer_2_036.cpp
@Author:dfc
@Date  :2023/4/18  10:26
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "stack"
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> my_stack;
    int result = stoi(tokens[0]);
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "+" or tokens[i]=="-" or  tokens[i]=="*" or tokens[i]=="/")
        {
            int a  = my_stack.top();
            my_stack.pop();
            int b = my_stack.top();
            my_stack.pop();
            if (tokens[i]=="+")
                my_stack.push(a+b);
            else if (tokens[i] == "-")
                my_stack.push(b-a);
            else if (tokens[i]=="*")
                my_stack.push(a * b);
            else if (tokens[i]=="/")
                my_stack.push(b/a);
            result = my_stack.top();
        }
        else
        {
            my_stack.push(stoi(tokens[i]));
        }
    }
    return result;
}

