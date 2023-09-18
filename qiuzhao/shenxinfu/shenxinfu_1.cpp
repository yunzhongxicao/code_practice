/*
@File  :shenxinfu_1.cpp
@Author:dfc
@Date  :2023/9/6  19:26
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;

int main()
{
    string s;
    cin>>s;
    unordered_set<char> my_set;
    for (int i = 0; i < s.size(); ++i) {
        my_set.insert(s[i]);
    }
    vector<int> dp(my_set.size(),0);
    dp[0] =1;
    for (int i = 1; i <dp.size()     ; ++i) {
        dp[i] = 2*dp[i-1] +1;
    }
    cout<<dp.back();
}