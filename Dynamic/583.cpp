/*
@File  :583.cpp
@Author:dfc
@Date  :2022/11/27  9:56
@Desc  : �����ַ�����ɾ������
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int minDistance(string word1, string word2)
{
    word1 = " "+word1; // ����ͷ�������ڵ��ַ� �����ʼ��
    word2 = " "+word2;
    vector<vector<int>>dp(word1.size(),vector<int>(word2.size()));
    int tmp=0;
    for (int i = 0; i < word1.size(); ++i) {
        dp[i][0]=i;
    }
    for (int j = 0; j < word2.size(); ++j) {
        dp[0][j] =j;
    }
    for (int i = 1; i < word1.size(); ++i) {
        for (int j = 1 ; j < word2.size(); ++j) {
            if (word1[i] == word2[j])
            {
                dp[i][j] = dp[i-1][j-1];
            } else
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    return dp[word1.size()-1][word2.size()-1];
}

int main()
{
    string word1 = "sea", word2 = "eat";
    cout<< minDistance(word1,word2);
}