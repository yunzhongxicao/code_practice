/*
@File  :35_second.cpp
@Author:dfc
@Date  :2023/1/28  11:01
@Desc  : ËÑË÷²åÈëÎ»ÖÃ
*/
#include "iostream"
#include "vector"
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int left=0, right = nums.size()-1;
    while (left<=right)
    {
        int middle = left + (right-left)/2;
        if (nums[middle]>target) right = middle-1;
        else if (nums[middle]<target) left = middle+1;
        else if (nums[middle]==target) return middle;
    }
    return left;
}

