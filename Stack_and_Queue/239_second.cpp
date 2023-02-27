/*
@File  :239_second.cpp
@Author:dfc
@Date  :2023/2/27  15:16
@Desc  : 滑动窗口最大值
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    deque<int> my_queue;
    for (int i = 0; i < k; ++i) {
        while (!my_queue.empty() and nums[i]>my_queue.back())
        {
            my_queue.pop_back();
        }
        my_queue.push_back(nums[i]);
    }
    vector<int>  result;
    result.push_back(my_queue.front());
    for (int i = k; i <=nums.size()-1 ; ++i) {
        if (nums[i-k]==my_queue.front())
            my_queue.pop_front();
        while (!my_queue.empty() and nums[i]>my_queue.back())
        {
            my_queue.pop_back();
        }
        my_queue.push_back(nums[i]);
        result.push_back(my_queue.front());
    }
    return result;
}

