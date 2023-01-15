/*
@File  :offer_59_1 .cpp
@Author:dfc
@Date  :2023/1/15  13:38
@Desc  : 滑动窗口的最大值
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    if (nums.empty())  return result;
    deque<int> my_queue;
    for (int i = 0; i <=k-1 ; ++i) {
        while (!my_queue.empty() and my_queue.back()<nums[i])
        {
            my_queue.pop_back();
        }
        my_queue.push_back(nums[i]);
    }
    result.push_back(my_queue.front());
    for (int i = k; i < nums.size(); ++i) {
        if (nums[i-k]==my_queue.front())
            my_queue.pop_front();
        while (!my_queue.empty() and my_queue.back()<nums[i])
        {
            my_queue.pop_back();
        }
        my_queue.push_back(nums[i]);
        result.push_back(my_queue.front());
    }
    return result;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k =3;
    vector<int> result = maxSlidingWindow(nums,k);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}

