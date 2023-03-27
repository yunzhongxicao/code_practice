/*
@File  :392_second.cpp
@Author:dfc
@Date  :2023/3/27  10:39
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

bool isSubsequence(string s, string t)
{
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0)  ); // s t都在前面添加一个空格符
    dp[0] = vector<int>(t.size()+1,1);
    for (int i = 1; i < s.size()+1; ++i) {
        for (int j = 1; j < t.size()+1; ++j) {
            if (s[i-1]== t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j]  = dp[i][j-1];
        }
    }
    return dp.back().back();
}

