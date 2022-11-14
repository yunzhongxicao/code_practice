/*
@File  :139.cpp
@Author:dfc
@Date  :2022/11/14  18:32
@Desc  : µ¥´Ê²ð·Ö
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    vector<bool>dp(s.size()+1, false);
    dp[0]= true;
    cout<<(int)dp[0]<<" ";
    for (int i = 1; i <=s.size() ; ++i) {
        for (int j = 0; j < wordDict.size(); ++j) {
            if (i>=wordDict[j].size())
            {
                string tmp1 = s.substr(0,i);
                string tmp2  = tmp1.substr(tmp1.size()-wordDict[j].size(),wordDict[j].size());
                if (tmp2==wordDict[j] and dp[i - wordDict[j].size()])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        cout<<(int)dp[i]<<" ";
    }
    cout<<endl;
    return dp[s.size()];
}

int main()
{
    string s = "applepenapple";
    vector<string> wordlist = {"apple", "pen"};
    cout<<(int)wordBreak(s,wordlist);
}

