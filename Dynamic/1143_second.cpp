/*
@File  :1143_second.cpp
@Author:dfc
@Date  :2023/3/19  13:38
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),1));
    // dp[i][j]表示以 s1 0-i  s2 0-j 的最长公共字串
    for (int j = 0; j < text2.size(); ++j) {
        if (text2[j]==text1[0])
            break;
        dp[0][j] = 0;
    }
    for (int i = 0; i < text1.size(); ++i) {
        if (text1[i] == text2[0])
            break;
        dp[i][0] = 0;
    }
    for (int i = 1; i < text1.size(); ++i) {
        for (int j = 1; j < text2.size(); ++j) {
            if (text1[i] == text2[j])
                dp[i][j] = dp[i-1][j-1] +1;
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp.back().back();
}

