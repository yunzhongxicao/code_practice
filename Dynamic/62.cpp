/*
@File  :62.cpp
@Author:dfc
@Date  :2022/11/4  20:34
@Desc  : 不同路径
*/
#include "iostream"
#include "vector"
using namespace std;
/* 动态规划的解法
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0] = vector<int>(n,1);
    for (int i = 0; i < m; ++i) {
        dp[i][0]=1;
    }

    for (int i = 1; i <=m-1; ++i) {
        for (int j = 1; j <=n-1 ; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}*/

int uniquePaths(int m, int n)
{
    int  fenzi=n;
    int fenmu=1;
    long long result=1; // 乘的时候可能超范围
    for(;fenzi<=m+n-2;++fenzi)
    {
        result = result * fenzi;
        while (fenmu<=m-1 and result % fenmu==0) // 能除就一直除 所以用while
        {
            result = result / fenmu;
            fenmu++;
        }
    }
    return result;

}


int main()
{
    int result = uniquePaths(3,7);
    cout<<result;
}