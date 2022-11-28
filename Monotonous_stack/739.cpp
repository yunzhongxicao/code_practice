/*
@File  :739.cpp
@Author:dfc
@Date  :2022/11/28  10:00
@Desc  : √ø»’Œ¬∂»
*/
#include "iostream"
#include "stack"
#include "vector"
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> result(temperatures.size(),0);
    stack<int> my_stack;
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!my_stack.empty() and temperatures[i]>temperatures[my_stack.top()])
        {
            result[my_stack.top()] = i - my_stack.top();
            my_stack.pop();
        }
        my_stack.push(i);
    }
    return result;
}

int main()
{
    vector<int> tem = {73,74,75,71,69,72,76,73};
    vector<int> result = dailyTemperatures(tem);
    for (int i = 0; i < result.size(); ++i) {
        cout<< result[i]<<" ";
    }
}