/*
@File  :taobao_3.cpp
@Author:dfc
@Date  :2023/9/2  14:56
@Desc  :
*/

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    for (int i = s.size()-1; i >=0 ; --i) {
        dp[i][i] =1;
        for (int j = i+1; j <=s.size()-1 ; ++j) {
            if (s[i]==s[j])
            {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] +1;
            }
            else
            {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
        }
    }
    cout<<dp[0][s.size()-1];
}