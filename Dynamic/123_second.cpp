/*
@File  :123_second.cpp
@Author:dfc
@Date  :2023/3/9  11:57
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;

int maxProfit(vector<int>& prices)
{
    vector<vector<int>>dp(prices.size(),vector<int>(4));
    dp[0][0] =0;  // 第一次不持有
    dp[0][1] = -prices[0]; // 第一次持有
    dp[0][2] = 0; // 第二次不持有
    dp[0][3] = -prices[0];  // 第二次持有
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1],-prices[i]);
        dp[i][2] = max(dp[i-1][2],dp[i-1][3]+prices[i]);
        dp[i][3] = max(dp[i-1][3],dp[i-1][0]-prices[i]);
    }
    return dp[prices.size()-1][2];
}

