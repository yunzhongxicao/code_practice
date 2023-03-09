/*
@File  :188_second.cpp
@Author:dfc
@Date  :2023/3/9  13:43
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int maxProfit(int k, vector<int>& prices)
{
    vector<vector<int>>dp(prices.size(),vector<int>(2*k));
    for (int i = 0; i <k ; ++i) {
        dp[0][i *2]=0;
        dp[0][i*2+1] = -prices[0];
    }
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i-1][1]+prices[i] , dp[i-1][0]);
        dp[i][1] = max(dp[i-1][1],-prices[i]);
        for (int j = 1; j < k; ++j) {
            dp[i][2 * j ]=max(dp[i-1][2*j],dp[i-1][2*j+1]+prices[i]);
            dp[i][2*j+1] = max(dp[i-1][2*j+1],dp[i-1][2*j-2]-prices[i]);
        }
    }
    return dp[prices.size()-1][2*k-2];
}

