/*
@File  :746.cpp
@Author:dfc
@Date  :2023/5/23  19:25
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    vector<int>dp(cost.size()+1,0);
    dp[0] =0;
    dp[1] =0;
    for (int i = 2; i <=cost.size() ; ++i) {
        dp[i] = min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
    }
    return dp.back();
}
