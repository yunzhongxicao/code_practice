/*
@File  :62_second.cpp
@Author:dfc
@Date  :2023/3/16  11:13
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>>dp(m,vector<int>(n,1));
    // 第一行第一列 不用初始化了
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <n ; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

