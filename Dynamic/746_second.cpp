/*
@File  :746_second.cpp
@Author:dfc
@Date  :2023/3/9  0:57
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    vector<int>dp(cost.size()+1); // dp[i]表示到达第i层支付的最低花费，要上到顶部 其实一共是n+1层
    dp[0]=0;
    dp[1] =0;
    for (int i = 2; i <= cost.size(); ++i) {
        dp[i]  = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    return dp[cost.size()];
}

