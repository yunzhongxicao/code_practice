/*
@File  :122_second.cpp
@Author:dfc
@Date  :2023/3/9  11:33
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

/*int maxProfit(vector<int>& prices) //
{
    vector<vector<int>>dp(prices.size(),vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
    }
    return dp[prices.size()-1][0];
}*/

int maxProfit(vector<int>& prices) // 空间优化的版本
{
    int dp_i_0   = 0;
    int dp_i_1 = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_1+prices[i],temp);
        dp_i_1 = max(temp-prices[i],dp_i_1);
    }
    return dp_i_0;
}
