/*
@File  :714.cpp
@Author:dfc
@Date  :2022/11/20  12:48
@Desc  : 股票问题 含手续费
*/
#include "vector"
#include "iostream"

using namespace std;

int maxProfit(vector<int>& prices, int fee)
{
    vector<vector<int>>dp(prices.size(),vector<int>(2,0));
    dp[0][0] = -prices[0]-fee;
    dp[0][1] = 0; // 是最大的现金 所以不可能是负的
    for (int i = 1; i <prices.size() ; ++i) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]-fee) ;
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
    }
    return dp[prices.size()-1][1];
}

int main()
{
    vector<int> prices = {1,3,7,5,10,3};
    int fee = 3;
    cout<<maxProfit(prices,fee);
}