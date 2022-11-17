/*
@File  :121.cpp
@Author:dfc
@Date  :2022/11/15  18:57
@Desc  :买卖股票的最佳时机
*/
#include "vector"
#include "iostream"
using namespace std;

/*int maxProfit(vector<int>& prices)
{
    vector<int>dp(prices.size()); // 0-->i的最低点
    dp[0] = prices[0];
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
        dp[i] = min(dp[i-1],prices[i]);
        result = max(result,prices[i]-dp[i]);
    }
    return result;
}*/

/*int maxProfit(vector<int>& prices) // 只能买一次
{
    int buy_in = INT32_MAX;
    int result = 0;
    for (int i = 0; i < prices.size(); ++i) { // 假如在i天卖出股票 那么一定是在0-->i天找最小值然后买入 计算一个最大值利润
        buy_in=min(buy_in,prices[i]);
        result  = max(result,prices[i]-buy_in);
    }
    return result;
}*/


/*int maxProfit(vector<int>& prices) // Z真正的动态规划
{
    vector<vector<int>>dp(prices.size(),vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size() ; ++i) {
        dp[i][0] = max(dp[i-1][0],-prices[i]); // 注意 这里只允许买一次  所以这里不是dp[i-1][1]-prices[i]
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+ prices[i]);
    }
    return dp[prices.size()-1][1];

}*/

int maxProfit(vector<int>& prices) // 动态规划优化版本
{
    vector<vector<int>>dp(2,vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size() ; ++i) {
        dp[i%2][0] = max(dp[(i-1)%2][0],-prices[i]); // 注意 这里只允许买一次  所以这里不是dp[i-1][1]-prices[i]
        dp[i%2][1] = max(dp[(i-1)%2][1],dp[(i-1)%2][0]+ prices[i]);
    }
    return dp[(prices.size()+1)%2][1];

}

int main()
{
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
}

