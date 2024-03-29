/*
@File  :offer_63.cpp
@Author:dfc
@Date  :2023/1/16  20:45
@Desc  : 股票的最大利润
*/

#include "iostream"
#include "vector"
using namespace std;

int maxProfit(vector<int>& prices)
{
    if(prices.size()==0 ) return 0;
    vector<vector<int>>dp(prices.size(),vector<int>(2,0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i <=prices.size()-1 ; ++i) {
        dp[i][0]     = max(dp[i-1][0],-prices[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
    }
    return dp[prices.size()-1][1];
}

