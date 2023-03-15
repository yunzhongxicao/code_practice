/*
@File  :139_second.cpp
@Author:dfc
@Date  :2023/3/15  10:29
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    vector<unsigned long long >dp(s.size()+1); // dp[j]表示组成长度为j的方案数量
    dp[0] = 1;
    for (int j = 1; j < s.size()+1; ++j) {
        for (int i = 0; i < wordDict.size(); ++i) {
            if (wordDict[i].size()>j)
                dp[j] +=0;
            else
            {
                if (s.substr(j-wordDict[i].size(),wordDict[i].size()) != wordDict[i])
                    dp[j] +=0;
                else
                    dp[j] += dp[j-wordDict[i].size()];
            }
        }
    }
    return dp[s.size()] !=0;
}

