/*
@File  :252.cpp
@Author:dfc
@Date  :2022/9/4  14:59
@Desc  :
*/


#include "queue"

using namespace std;

class MyStack {
public:
    queue<int> queue_1;
    MyStack() {

    }

    void push(int x) {
        queue_1.push(x);
    }

    int pop() {
        int queue_1_size = queue_1.size();
        for (int i = 1; i < queue_1_size; ++i) {
            queue_1.push(queue_1.front());
            queue_1.pop();
        }
        int tmp = queue_1.front();
        queue_1.pop();
        return tmp;
    }

    int top() {
        int tmp =  this->pop();
        queue_1.push(tmp);
        return tmp;
    }

    bool empty() {
        return queue_1.empty();
    }
};