/*
@File  :232_second.cpp
@Author:dfc
@Date  :2023/2/23  10:28
@Desc  : 用 栈实现队列
*/
#include "iostream"
#include "stack"

using namespace std;

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }

    int peek() {
        int temp = pop();
        s2.push(temp);
        return temp;
    }

    bool empty() {
        if (s1.empty() and s2.empty()) return true;
        return false;
    }
};

