/*
@File  :70.cpp
@Author:dfc
@Date  :2023/5/23  18:46
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int climbStairs(int n)
{
    if (n<2) return n;
    vector<int>dp(n);
    dp[0] = 0; // 没有意义
    dp[1] = 1;
    for (int i = 2; i <=n ; ++i) {
        dp[i] = dp[i-1]  + dp[i-2];
    }
    return dp[n];
}
