/*
@File  :26_second.cpp
@Author:dfc
@Date  :2023/2/4  10:56
@Desc  : 删除有序数组中的重复项
*/
#include "iostream"
#include "vector"

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int slow = 1, fast = 1;
    while (fast<=nums.size()-1)
    {
        if (nums[fast]==nums[fast-1])
        {
            fast++;
        }
        else
        {
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
    }
    return slow;
}

