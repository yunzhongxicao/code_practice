/*
@File  :115.cpp
@Author:dfc
@Date  :2022/11/26  10:16
@Desc  : 不同的子序列
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

int numDistinct(string s, string t)
{
    if (s.size()<t.size()) return 0;
    if (t.size()==0) return 1;
    // dp[i][j] 表示 从0 -->i 的s 去匹配 0-->j 的t 的匹配个数
    vector<vector<unsigned long long >> dp(s.size(),vector<unsigned long long >(t.size(),0));
    int tmp =0;
    int count = 0;
    while (tmp<s.size())
    {
        if (s[tmp] == t[0])
        {
            count++;
        }
        dp[tmp][0] =count;
        tmp++;
    }
    if (s[0]== t[0]) dp[0][0] = 1;

    for (int i = 1; i < s.size(); ++i) {
        for (int j = 1; j < t.size(); ++j) {
            if (s[i]== t[j])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            else
                dp[i][j] =dp[i-1][j];
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return (int)dp[s.size()-1][t.size()-1];
}

int main()
{
    string s = "babgbag", t = "bag";
    cout<<numDistinct(s,t);
}

