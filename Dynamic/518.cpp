/*
@File  :518.cpp
@Author:dfc
@Date  :2022/11/11  21:39
@Desc  : ¡„«Æ∂“ªª
*/
#include "vector"
#include "iostream"
using namespace std;

/*
int change(int amount, vector<int>& coins) // ∂˛Œ¨–¥∑®
{
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
    dp[0][0] =1;
    int tmp=1;
    while (tmp*coins[0] <= amount)
    {
        dp[0][tmp*coins[0]] = 1;
        tmp++;
    }
    for (int i = 1; i <coins.size() ; ++i) {
        for (int j = 0; j <=amount ; ++j) {
            if (j<coins[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
        }
    }
    return dp[coins.size()-1][amount];
}*/


int change(int amount, vector<int>& coins) // “ªŒ¨–¥∑®
{
    vector<int> dp(amount+1,0);
    dp[0] =1;
    int tmp=1;
    while (tmp*coins[0]<=amount)
    {
        dp[tmp*coins[0]] = 1;
        tmp++;
    }
    for (int i = 1; i <coins.size()  ; ++i) {
        for (int j = coins[i]; j <=amount ; ++j) {
            dp[j] = dp[j]+dp[j-coins[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int amount = 5;
    vector<int> coins={1,2,5};

    cout<<change(amount,coins);
}

