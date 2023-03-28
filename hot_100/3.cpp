/*
@File  :3.cpp
@Author:dfc
@Date  :2023/3/28  14:18
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty()) return 0;
    vector<int>dp(s.size(),1);
    int result=1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i]== s[i-1]) dp[i]=1;
        else
        {
            int j = i-1;
            for (; j >=i-dp[i-1] ; --j) {
                if (s[j]==s[i])
                    break;
            }
            dp[i] = i-j;
        }
        result = max(result,dp[i]);
    }
    return result;
}