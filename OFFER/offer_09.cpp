/*
@File  :offer_09.cpp
@Author:dfc
@Date  :2022/12/5  11:17
@Desc  : 用两个栈实现队列
*/
#include "stack"
using namespace std;

class CQueue {
public:
    stack<int> my_stack_1, my_stack_2;
    CQueue() {

    }

    void appendTail(int value) {
        my_stack_2.push(value);
    }

    int deleteHead() {
        if (my_stack_1.empty() and my_stack_2.empty()) return -1;
        if (!my_stack_1.empty())
        {
            int tmp = my_stack_1.top();
            my_stack_1.pop();
            return tmp;
        }
        else
        {
            while (!my_stack_2.empty())
            {
                int tmp = my_stack_2.top();
                my_stack_2.pop();
                my_stack_1.push(tmp);
            }
            int tmp = my_stack_1.top();
            my_stack_1.pop();
            return tmp;
        }
    }
};