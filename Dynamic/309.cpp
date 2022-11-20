/*
@File  :309.cpp
@Author:dfc
@Date  :2022/11/19  0:30
@Desc  : ��Ʊ���� ���䶳��
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
        dp[i][0] = max(dp[i-1][0],dp[i-2][1]-prices[i]); // sell֮��Ҫ��һ����ܽ��ף�����Ϊɶ����i-1���ǲ�̫���
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
    }
    return dp[prices.size()-1][1];
}

int main()
{
    vector<int> prices = {1};
    cout<<maxProfit(prices);
}
