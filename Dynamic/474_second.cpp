/*
@File  :474_second.cpp
@Author:dfc
@Date  :2023/3/13  17:02
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;

vector<int> zero_one(string &s)
{
    int zero =0, one=0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='0') zero++;
        else if (s[i]=='1') one++;
    }
    return vector<int>{zero,one};
}

int findMaxForm(vector<string>& strs, int m, int n)
{
    vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,0)));
    vector<int> temp = zero_one(strs[0]);
    int temp0 = temp[0];
    int  temp1 = temp[1];
    for (int j = temp0; j <=m ; ++j) {
        for (int k = temp1; k <=n ; ++k) {
            dp[0][j][k] = 1;
        }
    }
    for (int i = 1; i < strs.size(); ++i) {
        temp = zero_one(strs[i]);
        temp0 = temp[0];
        temp1 = temp[1];
        for (int j = 0; j < m+1; ++j) {
            for (int k = 0; k < n+1; ++k) {
                if (j>=temp0 and k>= temp1)
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-temp0][k-temp1]+1);
                else
                    dp[i][j][k] = dp[i-1][j][k] ;
            }
        }
    }
    cout<<1;
    return dp.back().back().back();
}

int  main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m=5, n=3;
    cout<<findMaxForm(strs,m,n);
}
