/*
@File  :309_second.cpp
@Author:dfc
@Date  :2023/3/9  14:10
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int maxProfit(vector<int>& prices)
{
    if (prices.size()==1) return 0;
    vector<vector<int>>dp(prices.size(),vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(0,prices[1]-prices[0]);
    dp[1][1] = max(dp[0][1],-prices[1]);
    for (int i = 2; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i]);
    }
    return dp[prices.size()-1][0];
}

