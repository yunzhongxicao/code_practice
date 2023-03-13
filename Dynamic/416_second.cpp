/*
@File  :416_second.cpp
@Author:dfc
@Date  :2023/3/13  15:12
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;

bool canPartition(vector<int>& nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum%2 !=0) return false;
    int bag_size = sum/2;
    vector<vector<int>>dp(nums.size(),vector<int>(bag_size+1,0));
    for (int j = 0; j < bag_size+1; ++j) {
        if (j>=nums[0])
            dp[0][j] = nums[0];
    }
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j <dp[i].size() ; ++j) {
            if (j>=nums[i])
                dp[i][j]  = max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp.back().back()==sum/2;
}

