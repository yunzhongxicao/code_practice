/*
@File  :5.cpp
@Author:dfc
@Date  :2023/4/1  22:10
@Desc  : 最长回文子串
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

string longestPalindrome(string s)
{
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0)); // dp[i][j]表示 i-j是否为回文子串
    dp[0][0] = 1;
    dp[s.size()-1][s.size()-1] =1;
    int start = 0,end=0, length =1;
    for (int i = s.size()-2; i >=0 ; --i) {
        for (int j = i; j <s.size() ; ++j) {
            if (s[i]==s[j])
            {
                if (j-i==0) dp[i][j] = 1;
                else if (j-i==1) dp[i][j]=1;
                else
                {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            else
                dp[i][j] =0;
            if (dp[i][j]==1 and j-i+1>length)
            {
                start = i;
                end = j;
                length = j-i+1;
            }
        }
    }
    string result;
    for (int i = start; i <=end ; ++i) {
        result += s[i];
    }
    return result;
}

