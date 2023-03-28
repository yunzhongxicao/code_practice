/*
@File  :115_second.cpp
@Author:dfc
@Date  :2023/3/27  10:53
@Desc  :
*/

#include "iostream"
#include "string"
#include "vector"
using namespace std;

int numDistinct(string s, string t)
{
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,1));
    dp[0] = vector<int>(t.size()+1,0);
    dp[0][0] = 1;
    for (int i = 1; i < s.size() + 1; ++i) {
        for (int j = 1; j < t.size()+1; ++j) {
            if (s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp.back().back();
}


