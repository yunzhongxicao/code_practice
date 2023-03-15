/*
@File  :279_second.cpp
@Author:dfc
@Date  :2023/3/14  19:04
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int numSquares(int n)
{
    vector<int>nums;
    for (int i = 1; i <= n; ++i) {
        if (i *i <=n)
            nums.push_back(i*i);
        else
            break;
    }
    vector<vector<int>>dp(nums.size(),vector<int>(n+1,0));
    for (int j = 0; j <=n; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (j>=nums[i])
                dp[i][j] = min(dp[i-1][j],dp[i][j-nums[i]]+1);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp.back().back();
}

