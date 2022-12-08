/*
@File  :153.cpp
@Author:dfc
@Date  :2022/12/6  11:58
@Desc  :寻找旋转排序数组中的最小值
*/
#include "vector"
#include "iostream"
using namespace std;
int findMin(vector<int>& nums)
{
    int left=0, right = nums.size()-1;
    while (left<right)
    {
        int mid = left + (right-left)/2;
        if (nums[mid]>nums[right])
            left = mid+1;
        else if (nums[mid]<nums[right])
            right = mid;
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {3,4,5,1,2};
    cout<<findMin(nums);
}

