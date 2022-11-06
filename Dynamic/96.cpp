/*
@File  :96.cpp
@Author:dfc
@Date  :2022/11/6  21:49
@Desc  : 不同的二叉搜索树
*/
#include "iostream"
#include "vector"

using namespace std;

int numTrees(int n)
{
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1] = 1;
    for (int i = 2; i <=n ; ++i) {
        for (int j = 0; j <=i-1 ; ++j) {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }
    return dp[n];
}

int main()
{
    cout<<numTrees(4);
}