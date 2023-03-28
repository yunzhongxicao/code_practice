/*
@File  :647_second.cpp
@Author:dfc
@Date  :2023/3/28  18:05
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

int countSubstrings(string s)
{
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    dp.back().back()=1;
    dp[0][0] =1;
    for (int i = s.size()-2; i >=0 ; --i) {
        for (int j = i; j <s.size() ; ++j) {
            if (j==i) dp[i][j] =1;
            else
            {
                if (s[i] != s[j]) dp[i][j] =0;
                else
                {
                    if ((j-i)==1)dp[i][j]=1;
                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }
    }
    int result=0;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            result += dp[i][j];
        }
    }
    return result;
}

