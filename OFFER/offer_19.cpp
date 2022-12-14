/*
@File  :offer_19.cpp
@Author:dfc
@Date  :2022/12/14  13:47
@Desc  : 正则表达式匹配
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(p.size()+1,vector<bool>(s.size()+1, false) );
    dp[0][0] = true;
    for (int i = 2; i <=p.size() ; i+=2) { // 对于奇数位来说 肯定是消不完的 必然会剩一个
        if (p[i-1]=='*') dp[i][0] = dp[i-2][0];
    }
    for (int i = 1; i <=p.size() ; ++i) {
        for (int j = 1; j <=s.size() ; ++j) {
            if (p[i-1]==s[j-1] or p[i-1] == '.') dp[i][j] = dp[i-1][j-1];
            else if(p[i-1]=='*')
            {
                if (p[i-2] !='.' and  s[j-1] != p[i-2])
                    dp[i][j] = dp[i-2][j];
                else
                {
                    dp[i][j] = dp[i-2][j];
                    dp[i][j] = (dp[i][j] or dp[i][j-1]);
                }
            }
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[p.size()][s.size()];
}

int main()
{
    string s = "aaa";
    string p = "ab*a*c*a";
    isMatch(s,p);
}