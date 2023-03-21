/*
@File  :72_second.cpp
@Author:dfc
@Date  :2023/3/20  11:30
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int minDistance(string word1, string word2)
{
    vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
    for (int j = 1; j <=word2.size() ; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <=word1.size() ; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <=word1.size() ; ++i) {
        for (int j = 1; j <=word2.size() ; ++j) {
            if (word1[i-1]== word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1],dp[i][j-1])) +1;
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

int main()
{
    string word1 = "horse", word2 = "ros";
    cout<<minDistance(word1,word2);
}