/*
@File  :704_third.cpp
@Author:dfc
@Date  :2023/7/10  19:05
@Desc  :
*/
#include "vector"
#include "iostream"

using namespace std;

int search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    while (left<=right)
    {
        int middle = (left+right)/2;
        if (nums[middle]==target) return middle;
        if (nums[middle]>target) right = middle-1;
        else if (nums[middle]<target) left = middle+1;
    }
    return -1;
}

