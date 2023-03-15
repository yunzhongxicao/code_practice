/*
@File  :70_second.cpp
@Author:dfc
@Date  :2023/3/9  0:48
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int climbStairs(int n)
{
    if (n<3) return n;
    vector<int>dp(n+1);
    // dp[0]=1;
    dp[1] =1;
    dp[2] = 2;
    for (int i = 3; i <=n ; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int climbStairs(int n,int m) // n级楼梯 一次最多m级
{
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j <=m ; ++j) {
            if (i-j>=0)
                dp[i] += dp[i-j];
        }
    }
    return dp[n];
}
