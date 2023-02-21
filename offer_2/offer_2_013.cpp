/*
@File  :offer_2_013.cpp
@Author:dfc
@Date  :2023/2/21  18:37
@Desc  : 二维子矩阵的和
*/
#include "iostream"
#include "vector"
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> matrix_dp;
    NumMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int sum = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            sum += matrix[i][0];
            dp[i][0]    = sum;
        }
        sum =  0;
        for (int j = 0; j < n; ++j) {
            sum += matrix[0][j];
            dp[0][j] = sum;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <n ; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]+matrix[i] [j];
            }
        }
        matrix_dp = dp;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum = matrix_dp[row2][col2];
        if (row1>=1)
            sum -= matrix_dp[row1-1][col2];
        if (col1>=1)
            sum -= matrix_dp[row2][col1-1];
        if (row1>=1 and col1>=1)
            sum += matrix_dp[row1-1][col1-1];
        return sum;
    }
};

