/*
@File  :123.cpp
@Author:dfc
@Date  :2022/11/17  11:28
@Desc  : 股票问题3
*/
#include "iostream"
#include "vector"

using namespace std;

// 理解递归的本质是穷举“状态” 然后“选择”最优解

/*int maxProfit(vector<int>& prices)
{
    vector<vector<int>> dp(prices.size(),vector<int>(4));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = -prices[0];
    dp[0][3] = 0;

    for (int i = 1; i <prices.size() ; ++i) {
        dp[i][0] = max(dp[i-1][0],-prices[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        dp[i][2] = max(dp[i-1][2],dp[i-1][1]- prices[i]);
        dp[i][3] = max(dp[i-1][3],dp[i-1][2]+prices[i]);
    }
    return dp[prices.size()-1][3];
}*/

int maxProfit(vector<int>& prices) // 空间优化版本
{
//    vector<vector<int>> dp(prices.size(),vector<int>(4));

    int dp_i_0 = -prices[0];
    int dp_i_1 = 0;
    int dp_i_2 = -prices[0];
    int dp_i_3 = 0;

    for (int i = 1; i <prices.size() ; ++i) {
        dp_i_3 = max(dp_i_3,dp_i_2+prices[i]);
        dp_i_2 = max(dp_i_2,dp_i_1-prices[i]);
        dp_i_1 = max(dp_i_1,dp_i_0+ prices[i]);
        dp_i_0 = max(dp_i_0,-prices[i]);
    }
    return dp_i_3;
}

int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
}