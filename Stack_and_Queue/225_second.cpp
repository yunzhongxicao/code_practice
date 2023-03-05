/*
@File  :225_second.cpp
@Author:dfc
@Date  :2023/2/23  10:42
@Desc  : 用队列实现栈
*/
#include "iostream"
#include "queue"
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
        // 其实q2只起到暂存的作用
    }

    int pop() {
        int size = q1.size();
        while (size>1)
        {
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
            size--;
        }
        int result = q1.front();
        q1.pop();
        q1 = q2;
        while (!q2.empty())
        {
            q2.pop();
        }
        return result;
    }

    int top() {
        int result = this->pop();
        q1.push(result);
        return result;
    }

    bool empty() {
        return q1.empty();
    }
};

