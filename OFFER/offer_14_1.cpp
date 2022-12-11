/*
@File  :offer_14_1.cpp
@Author:dfc
@Date  :2022/12/11  14:29
@Desc  : ������
*/
#include "iostream"
#include "vector"
using namespace std;

int cuttingRope(int n)
{
    vector<int> dp(n+1,0);
    dp[1]=1;
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] = max(dp[i], max(dp[i-j] * j,(i-j) * j));
        }
    }
    return dp[n];
}

