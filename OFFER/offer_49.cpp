/*
@File  :offer_49.cpp
@Author:dfc
@Date  :2023/1/2  14:15
@Desc  :����
*/
#include "vector"
#include "iostream"
using namespace std;

int nthUglyNumber(int n)
{
    vector<int>dp(n); // ��i������
    dp[0] =1;
    int a = 0,b=0,c=0;
    for (int i = 1; i <n ; ++i) {
        dp[i] = min(min(dp[a]*2,dp[b]*3),dp[c]*5)   ;
        if (dp[i] == dp[a] *2) a++;
        if (dp[i] ==  dp[b] *3) b++;
        if (dp[i] == dp[c] *5) c++;
    }
    return dp[n-1];
}

