/*
@File  :1049_second.cpp
@Author:dfc
@Date  :2023/3/13  15:36
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int lastStoneWeightII(vector<int>& stones)
{
    int sum = 0;
    for (int i = 0; i < stones.size(); ++i) {
        sum +=  stones[i];
    }
    int bag_size =sum/2;
    vector<vector<int>>dp(stones.size(),vector<int>(bag_size+1,0));
    for (int j = 0; j < bag_size+1; ++j) {
        if (j>=stones[0])
            dp[0][j]= stones[0];
    }
    for (int i = 1; i < stones.size(); ++i) {
        for (int j = 0; j < bag_size+1; ++j) {
            if (j>=stones[i])
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i]]+stones[i] );
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return sum-dp[stones.size()-1][bag_size]-dp[stones.size()-1][bag_size];
}


