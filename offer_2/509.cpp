/*
@File  :509.cpp
@Author:dfc
@Date  :2023/5/23  18:31
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int fib(int n)
{
    if (n<2) return n;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <=n ; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

