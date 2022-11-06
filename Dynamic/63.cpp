/*
@File  :63.cpp
@Author:dfc
@Date  :2022/11/6  11:18
@Desc  :²»Í¬Â·¾¶2
*/
#include "vector"
#include "iostream"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = (int)obstacleGrid.size();
    int n = (int)obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));


    dp[0] = vector<int>(n,0);
    for(int i=0;i<m;++i) dp[i][0] = 0;

    for (int i = 0; i < n; ++i) {
        if (obstacleGrid[0][i]==1)
        {
            break;
        }
        dp[0][i]=1;
    }


    for (int i = 0; i < m; ++i) {
        if (obstacleGrid[i][0]==1)
        {
            break;
        }
        dp[i][0]=1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n ; ++j) {
            dp[i][j] = dp[i-1][j] * abs(obstacleGrid[i-1][j]-1) + dp[i][j-1] * abs(obstacleGrid[i][j-1]-1);
            if (obstacleGrid[i][j]==1) dp[i][j]=0;
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> a = {{0,0,0},{0,1,0},{0,0,0}};
    int result = uniquePathsWithObstacles(a);
    cout<<result;
}