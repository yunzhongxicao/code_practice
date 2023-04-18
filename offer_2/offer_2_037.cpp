/*
@File  :offer_2_037.cpp
@Author:dfc
@Date  :2023/4/18  10:37
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    stack<int>  my_stack;
    my_stack.push(asteroids[0]);
    for (int i = 1; i < asteroids.size(); ++i) {
        bool flag = true;
        while (!my_stack.empty() and my_stack.top()>0 and asteroids[i]<0)
        {
            if (abs(asteroids[i])>my_stack.top())
            {
                my_stack.pop();
            }
            else if (abs(asteroids[i])==my_stack.top())
            {
                my_stack.pop();
                flag = false;
                break;
            }
            else if (abs(asteroids[i])<my_stack.top())
            {
                flag = false;
                break;
            }
        }
        if (flag) my_stack.push(asteroids[i]);
    }
    vector<int>result;
    if (my_stack.empty()) return result;
    result.resize(my_stack.size());
    for (int i = result.size()-1; i >=0; --i) {
        result[i] = my_stack.top();
        my_stack.pop();
    }
    return result;
}

