/*
@File  :offer_59_2.cpp
@Author:dfc
@Date  :2023/1/25  21:37
@Desc  : 队列的最大值
*/
#include "queue"
#include "iostream"
using namespace std;

class MaxQueue {
public:
    queue<int> my_queue;
    deque<int> my_deque;
    MaxQueue() {

    }

    int max_value() {
        if (my_deque.empty()) return -1;
        return my_deque.front();
    }

    void push_back(int value) {
        my_queue.push(value);
        while (!my_deque.empty() and my_deque.back()<value)
            my_deque.pop_back();
        my_deque.push_back(value);
    }

    int pop_front() {
        if (my_queue.empty()) return -1;
        int temp = my_queue.front();
        my_queue.pop();
        if (temp == my_deque.front())
            my_deque.pop_front();
        return temp;
    }
};

