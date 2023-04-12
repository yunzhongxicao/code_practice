/*
@File  :offer_2_090.cpp
@Author:dfc
@Date  :2023/4/12  11:31
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int rob_range(vector<int>&nums, int start, int end)
{
    vector<int>dp(nums.size(),0);
    dp[start] = nums[start];
    dp[start+1] = max(nums[start],nums[start+1]);
    for (int i = start+2; i <=end ; ++i) {
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[end];
}

int rob(vector<int>& nums)
{
    if (nums.size()==1) return nums[0];
    if (nums.size()==2) return max(nums[0],nums[1]);
    int money_1 = rob_range(nums,0,nums.size()-2);
    int money_2 = rob_range(nums,1,nums.size()-1);
    return max(money_1,money_2);
}