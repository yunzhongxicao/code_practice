/*
@File  :1143.cpp
@Author:dfc
@Date  :2022/11/21  22:41
@Desc  : 最长公共子序列
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;


/*
int longestCommonSubsequence(string text1, string text2)  //超时了，主要是里面那两个for循环太难搞了
{
    vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),0));
    int result=0;
    for (int i = 0; i < text1.size(); ++i) {
        if (text1[i]==text2[0])
            dp[i][0]=1;
        result = max(result,dp[i][0]);
    }
    for (int j = 0; j < text2.size(); ++j) {
        if (text2[j]==text1[0])
            dp[0][j] = 1;
        result = max(result,dp[0][j]);
    }

    for (int i = 1; i < text1.size(); ++i) {
        for (int j = 1; j < text2.size(); ++j) {
            if (text1[i]!=text2[j]) dp[i][j] =0;
            else
            {
                for (int k = 0; k < i; ++k) {
                    for (int l = 0; l < j; ++l) {
                        dp[i][j] = max(dp[i][j],dp[k][l]+1);
                    }
                }
            }
            result = max(result,dp[i][j]);
        }
    }
    return result;
}
*/


// 这里的dp[i][j]表示长度为 0-->i 和 0 --> j的最长子序列长度，不用加末尾元素限制
int longestCommonSubsequence(string text1, string text2)  //超时了
{
    vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),1));
    int result=0;
    int tmp= 0;
    while (tmp<text1.size() and text1[tmp]!=text2[0])
    {
        dp[tmp][0] =0;
        tmp++;
    }
    tmp=0;
    while (tmp<text2.size() and  text2[tmp] != text1[0])
    {
        dp[0][tmp] = 0;
        tmp++;
    }


    for (int i = 1; i < text1.size(); ++i) {
        for (int j = 1; j < text2.size(); ++j) {
            if (text1[i]==text2[j]) dp[i][j] =dp[i-1][j-1]+1;
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[text1.size()-1][text2.size()-1];
}


int main()
{
    string text1 = "abcde", text2 = "ace";
    cout<<longestCommonSubsequence(text1,text2);
}
