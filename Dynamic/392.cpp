/*
@File  :392.cpp
@Author:dfc
@Date  :2022/11/24  10:07
@Desc  : еп╤овспРап
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;
bool isSubsequence(string s, string t)
{
    if (s.size()==0 ) return true;
    if (s.size()!=0 and t.size()==0) return false;
    vector<vector<int>>dp(s.size(),vector<int>(t.size(),1));
    int tmp = 0;
    while (tmp<t.size() and t[tmp]!=s[0])
    {
        dp[0][tmp] = 0;
        tmp++;
    }
    tmp=0;
    while (tmp<s.size() and  s[tmp]!=t[0])
    {
        dp[tmp][0] = 0;
        tmp++;
    }
    for (int i = 1; i < s.size(); ++i) {
        for (int j = 1; j < t.size(); ++j) {
            if (s[i]==t[j]) dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[s.size()-1][t.size()-1]==s.size();
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";
    cout<<isSubsequence(s,t);
}