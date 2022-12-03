/*
@File  :283.cpp
@Author:dfc
@Date  :2022/12/3  11:16
@Desc  : “∆∂Ø¡„
*/
#include "vector"
#include "iostream"

using namespace std;

void moveZeroes(vector<int>& nums)
{
    int start;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]==0)
        {
            start = i;
            break;
        }
    }
    int end= start+1;
    while (start<nums.size() and end<nums.size())
    {
        if (nums[end]==0)
        {
            end++;
            continue;
        }
        else
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end++;
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout<<nums[i]<<" ";
    }
}

int main()
{
    vector<int> nums = {0};
    moveZeroes(nums);
}

