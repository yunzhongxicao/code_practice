/*
@File  :offer_48.cpp
@Author:dfc
@Date  :2023/1/2  10:44
@Desc  : 最长不含重复字符的子字符串
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size()==0) return 0;
    vector<int>dp(s.size());  // dp[i]表示以s[i]结尾的最长字串长度
    dp[0] = 1;
    int result = 1;
    for (int i = 1; i < s.size(); ++i) {
        int j = i-1;
        for (; j >= i-1-dp[i-1]+1; --j) {
            if (s[j]==s[i])
                break;
        }
        dp[i] = i-j;
        result = max(result,dp[i]);
    }
    return result;
}

int main()
{
    string  s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s);
}

