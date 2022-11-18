/*
@File  :188.cpp
@Author:dfc
@Date  :2022/11/18  22:24
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int maxProfit(int k, vector<int>& prices)
{
    vector<vector<int>>dp(prices.size(),vector<int>(2*k,0));
    int tmp =0;
    while (tmp * 2<2*k)
    {
        dp[0][2*tmp] = -prices[0];
        tmp++;
    }

    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i-1][0],-prices[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+ prices[i]);
        tmp =1;
        while (tmp*2<=2*k-1)
        {
            dp[i][tmp*2] = max(dp[i-1][tmp*2],dp[i-1][tmp*2-1]-prices[i]);
            dp[i][tmp*2+1] = max(dp[i-1][tmp*2+1],dp[i][tmp*2]+prices[i]);
            tmp++;
        }
    }
    return dp[prices.size()-1][2*k-1];
}

int main()
{
    int k = 2;
    vector<int> prices={3,2,6,5,0,3};
    cout<<maxProfit(k,prices);
}