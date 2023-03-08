/*
@File  :509_second.cpp
@Author:dfc
@Date  :2023/3/9  0:29
@Desc  :
*/
#include "bits//stdc++.h"

using namespace std;

int fib(int n)
{
    if (n<2 ) return n;
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1]  =1;
    for (int i = 2; i <=n ; ++i) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

