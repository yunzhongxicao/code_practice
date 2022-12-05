/*
@File  :offer_10_2.cpp
@Author:dfc
@Date  :2022/12/5  14:51
@Desc  : 青蛙跳台阶问题
*/
#include "iostream"
#include "vector"
using namespace std;

int numWays(int n)
{
    if (n<2) return 1;
    vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] =1;
    for (int i = 2; i <=n ; ++i) {
        dp[n] = (dp[n-1]+dp[n-2]) % (1000000007);
    }
    return dp[n];
}

