/*
@File  :518_second.cpp
@Author:dfc
@Date  :2023/3/14  10:48
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;

int change(int amount, vector<int>& coins)
{
    vector<vector<int>>dp(coins.size(),vector<int>(amount+1,1)); // dp[i][j]表示 面额为j的方案数量
    for (int j = 1; j < amount+1; ++j) {
        if (j%coins[0]==0)
            dp[0][j] = 1;
        else
            dp[0][j] = 0;
    }
    for (int i = 1; i < coins.size(); ++i) {
        for (int j = 1; j < amount+1; ++j) {
            if (j>=coins[i])
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
            else
                dp[i][j]  =dp[i-1][j];
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[coins.size()-1][amount];
}

int main()
{
    vector<int> coins={1,2,5};
    cout<<change(5,coins);
}

