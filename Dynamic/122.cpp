/*
@File  :122.cpp
@Author:dfc
@Date  :2022/11/17  11:13
@Desc  : 股票问题2
*/
#include "vector"
#include "iostream"

using namespace std;
/*
int maxProfit(vector<int>& prices) // 先试下贪心算法
{
    int result = 0;
    for (int i = 1; i <prices.size() ; ++i) {
        if (prices[i] - prices[i-1]>0)
            result += prices[i] - prices[i-1];
    }
    return result;
}
*/

int maxProfit(vector<int>& prices) // 动规的写法
{
    vector<vector<int>>dp(prices.size(),vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1] - prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    }
    return dp[prices.size()-1][1];
}


int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);

}