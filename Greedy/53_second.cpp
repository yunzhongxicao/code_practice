/*
@File  :53_second.cpp
@Author:dfc
@Date  :2023/3/9  10:39
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;

/*int maxSubArray(vector<int>& nums) // 贪心的方法
{
    int sum= nums[0];
    int result = sum;
    for (int i = 1; i < nums.size(); ++i) {
        if (sum<0)
        {
            sum = nums[i];
        }
        else
        {
            sum += nums[i];
        }
        result = max(result,sum);
    }
    return result;
}*/

int maxSubArray(vector<int>& nums)
{
    vector<int>dp(nums.size()); // dp[i]表示以nums[i]结尾的最大和
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (dp[i-1]<0)
            dp[i] =  nums[i];
        else
            dp[i] = dp[i-1] + nums[i];
        result = max(result,dp[i]);
    }
    return result;
}

