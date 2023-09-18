/*
@File  :63_third.cpp
@Author:dfc
@Date  :2023/9/17  23:51
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <=m ; ++i) {
        for (int j = 1; j <=n    ; ++j) {
            if (i==1 and j==1) dp[i][j] = 1;
            else
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] =0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp.back().back();
}

