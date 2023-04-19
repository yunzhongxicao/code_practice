/*
@File  :offer_2_038.cpp
@Author:dfc
@Date  :2023/4/19  10:13
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"

using namespace  std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> result(temperatures.size(),0);
    stack<int> my_stack;
    for (int i = 0; i < temperatures.size(); ++i) {
        int  cur = temperatures[i];
        while (!my_stack.empty() and  cur > temperatures[my_stack.top()] )
        {
            result[my_stack.top()] = i - my_stack.top();
            my_stack.pop();
        }
        my_stack.push(i);
    }
    return result;
}
