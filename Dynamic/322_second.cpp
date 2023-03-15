/*
@File  :322_second.cpp
@Author:dfc
@Date  :2023/3/14  13:17
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
    for (int j = 1; j < amount+1; ++j) {
        if (j % coins[0]==0)
            dp[0][j] = j / coins[0];
        else
            dp[0][j] = -1;
    }

    for (int i = 1; i < coins.size(); ++i) {
        for (int j = 1; j < amount+1; ++j) {
            if (j<coins[i])
                dp[i][j] = dp[i-1][j];
            else if (j==coins[i])
                dp[i][j] =1;
            else
            {
                if (dp[i][j-coins[i]]==-1)
                    dp[i][j] = dp[i-1][j];
                else if (dp[i-1][j] ==-1)
                    dp[i][j] = dp[i][j-coins[i]]+1;
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1);
            }
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[coins.size()-1][amount];
}

int main()
{
    vector<int>coins={2,5,10,1};
    cout<< coinChange(coins,12);
}

