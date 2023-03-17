/*
@File  :343_second.cpp
@Author:dfc
@Date  :2023/3/17  15:02
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int integerBreak(int n)
{
    vector<int>dp(n+1);
    dp[1] = 1;
    dp[2] =1;
    for (int i = 3; i < n+1; ++i) {
        for (int j = 1; j <=i-1 ; ++j) {
            dp[i] = max(dp[i],max(j * dp[i-j], j*(i-j)));
        }
    }
    return dp[n];
}

int main()
{
    cout<<integerBreak(6);
}

