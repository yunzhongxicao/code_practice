/*
@File  :offer_47.cpp
@Author:dfc
@Date  :2023/1/1  23:44
@Desc  : 礼物的最大价值
*/
#include "vector"
#include "iostream"
using namespace std;

int maxValue(vector<vector<int>>& grid)
{
    int m = grid.size();
    if (m==0) return 0  ;
    int n = grid[0].size();
    if (n==0) return 0;
    vector<vector<int>>dp(m,vector<int>(n,grid[0][0]));
    for (int i = 1; i <n ; ++i) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for(int j=1; j<m;++j)
    {
        dp[j][0] = dp[j-1][0]  + grid[j][0];
    }
    for (int i = 1; i < m   ; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid = {{1,2,5},{3,2,1}};
    cout<<maxValue(grid);
}


