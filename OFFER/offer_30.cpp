/*
@File  :offer_30.cpp
@Author:dfc
@Date  :2022/12/24  15:20
@Desc  : °üº¬minº¯ÊýµÄÕ»
*/
#include "iostream"
#include "stack"
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>my_stack;
    stack<int> min_stack;
    MinStack() = default;

    void push(int x) {
        my_stack.push(x);
        if (min_stack.empty()) min_stack.push(x);
        else
        {
            if (x<=min_stack.top())
                min_stack.push(x);
        }
    }

    void pop() {
        int tmp =my_stack.top();
        my_stack.pop();
        if (tmp==min_stack.top())
            min_stack.pop();
    }

    int top() {
        return my_stack.top();
    }

    int min() {
        return min_stack.top();
    }
};

