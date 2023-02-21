/*
@File  :offer_2_012.cpp
@Author:dfc
@Date  :2023/2/21  18:14
@Desc  : 左右两边子数组的和相等
*/
#include "iostream"
#include "vector"

using namespace std;

int pivotIndex(vector<int>& nums)
{
    int nums_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        nums_sum += nums[i];
    }
    int left_sum = 0;
    int right_sum = nums_sum;
    for (int i = 0; i < nums.size(); ++i) {
        right_sum = right_sum-nums[i];
        left_sum = nums_sum - right_sum-nums[i];
        if (right_sum==left_sum)
            return i;
    }
    return -1;
}

