/*
@File  :494_second.cpp
@Author:dfc
@Date  :2023/3/13  15:57
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int findTargetSumWays(vector<int>& nums, int target)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum<target) return 0;
    if ((sum-target)%2 !=0) return 0;
    int bag_size = (sum - target)/2;
    vector<vector<int>>dp(nums.size(),vector<int>(bag_size+1,0) ); // dp[i][j]表示0-i中取和为j的方案数量
    if (nums[0] !=0)
    {
        dp[0][0] = 1;
        if (nums[0]<=bag_size)
            dp[0][nums[0]] =1;
    }
    else dp[0][0] =2;
    for (int i = 1; i < nums.size() ; ++i) {
        for (int j = 0; j <= bag_size; ++j) {
            if (j-nums[i]>=0)
            {
                dp[i][j] = dp[i-1][j]+ dp[i-1][j-nums[i]];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp.back().back();

    
}

