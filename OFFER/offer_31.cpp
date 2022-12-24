/*
@File  :offer_31.cpp
@Author:dfc
@Date  :2022/12/24  20:52
@Desc  :栈的压入、弹出序列
*/
#include "stack"
#include "iostream"
#include "vector"
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    stack<int>my_stack;
    int pop_index =0;
    for (int i = 0; i < pushed.size(); ++i) {
        my_stack.push(pushed[i]);
        while (!my_stack.empty()and  my_stack.top()==popped[pop_index])
        {
            my_stack.pop();
            pop_index++;
        }
    }
    return my_stack.empty();
}

