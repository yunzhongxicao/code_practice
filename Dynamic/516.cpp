/*
@File  :516.cpp
@Author:dfc
@Date  :2022/11/27  15:39
@Desc  : 最长回文子序列
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int longestPalindromeSubseq(string s)
{
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),1));
    int result=1;
    for (int i = s.size()-1; i >=0 ; --i) {
        for (int j = i+1; j < s.size(); ++j) {
            if (j-i==1)
            {
                if (s[i]==s[j])
                    dp[i][j] =2;
            }
            else
            {
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    return dp[0][s.size()-1];
}