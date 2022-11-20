/*
@File  :309.cpp
@Author:dfc
@Date  :2022/11/19  0:30
@Desc  : 股票问题 含冷冻期
*/
#include "iostream"
#include "vector"
using namespace std;

int maxProfit(vector<int>& prices)
{
    if (prices.size()==1) return 0;
    vector<vector<int>>dp(prices.size(),vector<int>(2,0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[1][0] = max(dp[0][0],-prices[1]);
    dp[1][1] = max(0,dp[0][0]+prices[1]);
    for (int i = 2; i < prices.size()  ; ++i) {
        dp[i][0] = max(dp[i-1][0],dp[i-2][1]-prices[i]); // sell之后要等一天才能交易，但是为啥不是i-1还是不太清楚
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
    }
    return dp[prices.size()-1][1];
}

int main()
{
    vector<int> prices = {1};
    cout<<maxProfit(prices);
}
