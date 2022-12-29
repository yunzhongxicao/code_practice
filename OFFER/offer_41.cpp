/*
@File  :offer_41.cpp
@Author:dfc
@Date  :2022/12/29  10:14
@Desc  :数据流中的中位数
*/
#include "iostream"
#include "queue"
#include "vector"
using namespace std;
class MedianFinder {
    priority_queue<int,vector<int>,greater<>>bigger_que;
    priority_queue<int,vector<int>,less<>>smaller_que;

    int m,n;
    /** initialize your data structure here. */
public:
    MedianFinder() {

    }

    void addNum(int num) {
        m = bigger_que.size();
        n = smaller_que.size();
        if (m==n)
        {
            smaller_que.push(num);
            int tmp = smaller_que.top();
            smaller_que.pop();
            bigger_que.push(tmp);
        }
        else if (m==n+1)
        {
            bigger_que.push(num);
            int tmp = bigger_que.top();
            bigger_que.pop();
            smaller_que.push(tmp);;
        }
    }

    double findMedian() {
        m = bigger_que.size();
        n = smaller_que.size();
        double result;
        if (m==n)
        {
            result = ((double )bigger_que.top() + (double )smaller_que.top())/2;
        }
        else if (m==n+1)
            result = bigger_que.top();
        return result;
    }
};

