/*
@File  :72.cpp
@Author:dfc
@Date  :2022/11/27  10:49
@Desc  : ±‡º≠æ‡¿Î
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int minDistance(string word1, string word2)
{
    word1 = " "+ word1;
    word2 = " "+word2;
    vector<vector<int>>dp(word1.size(),vector<int>(word2.size()));
    for(int i = 0; i<word1.size();i++) dp[i][0] = i;
    for(int j=0; j<word2.size();++j) dp[0][j] = j;

    for (int i = 1; i < word1.size(); ++i) {
        for (int j = 1; j < word2.size(); ++j) {
            if (word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) +1;
        }
    }
    return dp[word1.size()-1][word2.size()-1];
}

 int  main()
 {
    string word1 = "intention", word2 = "execution";
    cout<<minDistance(word1,word2);
 }




