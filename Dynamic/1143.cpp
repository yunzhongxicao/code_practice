/*
@File  :1143.cpp
@Author:dfc
@Date  :2022/11/21  22:41
@Desc  : �����������
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;


/*
int longestCommonSubsequence(string text1, string text2)  //��ʱ��
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


// �����dp[i][j]��ʾ����Ϊ 0-->i �� 0 --> j��������г��ȣ����ü�ĩβԪ������
int longestCommonSubsequence(string text1, string text2)  //��ʱ��
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


int main()
{
    string text1 = "abcde", text2 = "ace";
    cout<<longestCommonSubsequence(text1,text2);
}
