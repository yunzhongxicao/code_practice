/*
@File  :150.cpp
@Author:dfc
@Date  :2022/9/5  10:59
@Desc  : 逆波兰表达式求值
*/
#include "string"
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

int evalRPN(vector<string>& tokens);


int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int  a = evalRPN(tokens);
    cout<<a;
}

int evalRPN(vector<string>& tokens)
{
    stack<int> my_stack;
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/")
        {
            int first = my_stack.top();
            my_stack.pop();
            int second = my_stack.top();
            my_stack.pop();

            int tmp;
            if (tokens[i]=="+")
                tmp = first+second;
            if(tokens[i]=="-")
                tmp = second-first;
            if(tokens[i]=="*")
                tmp = second*first;
            if(tokens[i]=="/")
                tmp = second/first;
            my_stack.push(tmp);
        } else
        {
            int tmp = stoi(tokens[i]);
            my_stack.push(tmp);
        }
    }
    return my_stack.top();
}


