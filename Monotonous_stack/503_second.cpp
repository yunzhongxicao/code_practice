/*
@File  :503_second.cpp
@Author:dfc
@Date  :2023/4/24  11:21
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    vector<int> new_nums(nums.size()*2);
    for (int i = 0; i < nums.size(); ++i) {
        new_nums[i] = nums[i];
        new_nums[i+nums.size()] = nums[i];
    }
    vector<int> result(nums.size()*2,-1);
    stack<int> my_stack;
    for (int i = 0; i < new_nums.size(); ++i) {
        while (!my_stack.empty() and new_nums[i]>new_nums[my_stack.top()])
        {
            result[my_stack.top()] = new_nums[i];
            my_stack.pop();
        }
        my_stack.push(i);
    }
    result.resize(nums.size());
    return result;
}