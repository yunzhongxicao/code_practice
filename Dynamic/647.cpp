/*
@File  :647.cpp
@Author:dfc
@Date  :2022/11/27  14:33
@Desc  : »ØÎÄ×Ö´®
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;
int countSubstrings(string s)
{
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    int result = 0;
    for (int i = s.size()-1; i >=0 ; --i) {
        for (int j = i; j < s.size(); ++j) {
            if (s[i] != s[j]) dp[i][j] = 0;
            else
            {
                if (j-i <=1) dp[i][j] =1;
                else dp[i][j] = dp[i+1][j-1];
            }
            if (dp[i][j]==1) result++;
        }
    }
    return result;
}


