/*
@File  :63_second.cpp
@Author:dfc
@Date  :2023/3/16  11:25
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
    for (int i = 0; i < dp.size(); ++i) {
        if (obstacleGrid[i][0]==1)
            break;
        else
            dp[i][0]=1;
    }
    for (int j = 0; j < dp[0].size(); ++j) {
        if (obstacleGrid[0][j]==1)
            break;
        else
            dp[0][j]=1;
    }
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            if (obstacleGrid[i][j]==1) dp[i][j]=0;
            else
            {
                dp[i][j] =dp[i-1][j] +dp[i][j-1];
            }
        }
    }
    return dp.back().back();
}

