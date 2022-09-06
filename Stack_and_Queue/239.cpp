/*
@File  :239.cpp
@Author:dfc
@Date  :2022/9/5  11:44
@Desc  :滑动窗口最大值
*/

#include "iostream"
#include "deque"
#include "vector"

using namespace std;

class MyQueue
{
public:
    deque<int> my_que;
    void pop(int val)
    {
        if (!my_que.empty())
        {
            if (val!=my_que.front())
            {
                ;
            } else
            {
                my_que.pop_front();
            }
        }
    }
    void push(int val)
    {
        while (!my_que.empty() and my_que.back()< val) // 注意 这里只能把比它小的弹走，等于的情况如果也弹走，相当于在真正执行pop()的时候就少了一个可选的最大值了
        {
            my_que.pop_back();
        }
        my_que.push_back(val);
    }
    int front()
    {
        return my_que.front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k);

int main()
{
    vector<int> b = {1};
    int k = 1;
    vector<int> a = maxSlidingWindow(b,k);
    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<" ";
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    MyQueue my_que;
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        my_que.push(nums[i]);
    }
    result.push_back(my_que.front());
    for (int i = k; i < nums.size(); ++i) {
        my_que.push(nums[i]);
        my_que.pop(nums[i-k]);
        result.push_back(my_que.front());
    }
    return result;
}


