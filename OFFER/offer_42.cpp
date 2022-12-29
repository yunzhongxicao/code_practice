/*
@File  :offer_42.cpp
@Author:dfc
@Date  :2022/12/29  11:40
@Desc  : 连续子数组的最大和
*/
#include "iostream"
#include "vector"
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int sum = nums[0];
    int max_value = sum;
    for (int i = 1; i < nums.size(); ++i) {
        if (sum<0)
        {
            sum = nums[i];
        }
        else sum += nums[i];
        max_value = max(max_value,sum);
    }
    return max_value;
}

