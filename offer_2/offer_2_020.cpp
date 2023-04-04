/*
@File  :offer_2_020.cpp
@Author:dfc
@Date  :2023/4/4  18:18
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int countSubstrings(string s)
{
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    dp[0][0]=1;
    dp[s.size()-1][s.size()-1] =1;
    for (int i = s.size()-2; i >=0 ; --i) {
        for (int j = i; j <s.size() ; ++j) {
            if (s[i]==s[j])
            {
                if (j-i<=1) dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j-1];
            }
            else
                dp[i][j] = 0;
        }
    }
    int result  = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            result += dp[i][j];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return result;
}
int main()
{
    string s = "aaa";
    cout<<countSubstrings(s);
}

