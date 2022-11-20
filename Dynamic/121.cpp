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
    int dp_i_0=-prices[0];
    int dp_i_1 = 0;

    for (int i = 1; i < prices.size() ; ++i) {
        dp_i_1 = max(dp_i_1,dp_i_0+ prices[i]);// 顺序不能反 否则dp_i_0就更新了 不是上一步的了
        dp_i_0 = max(dp_i_0,-prices[i]);
    }
    return dp_i_1;
}

int main()
{
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
}

