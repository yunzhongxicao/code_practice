/*
@File  :offer_2_089.cpp
@Author:dfc
@Date  :2023/5/15  10:27
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int rob(vector<int>& nums)
{
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    if (nums.size()==1) return dp[0];
    dp[1] = max(nums[0],nums[1]);
    for (int i = 2; i <nums.size()   ; ++i) {
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp.back();
}

