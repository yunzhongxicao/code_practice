/*
@File  :offer_2_088.cpp
@Author:dfc
@Date  :2023/4/19  10:51
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    int  n = cost.size();
    if (n==2) return min(cost[0],cost[1]);
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1] =0;
    dp[2] = min(cost[0],cost[1]);
    for (int i = 3; i <=n ; ++i) {
        dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    return dp.back();
}
