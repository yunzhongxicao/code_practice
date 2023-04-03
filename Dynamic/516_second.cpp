/*
@File  :516_second.cpp
@Author:dfc
@Date  :2023/3/28  19:05
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

int longestPalindromeSubseq(string s)
{
    
    int result  =1;
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    dp[0][0] = 1;
    dp[s.size()-1][s.size()-1] =1;
    for (int i = s.size()-2; i >=0 ; --i) {
        for (int j = i; j <=s.size()-1; ++j) {
            if (s[i]==s[j])
            {
                if (j-i==0) dp[i][j] = 1;
                else if (j-i==1) dp[i][j] =2;
                else
                {
                    dp[i][j] = dp[i+1][j-1] +2;
                }
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][s.size()-1];
}

int main()
{

}