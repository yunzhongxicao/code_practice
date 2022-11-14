/*
@File  :322.cpp
@Author:dfc
@Date  :2022/11/12  23:47
@Desc  :零钱兑换
*/
#include "iostream"
#include "vector"

using namespace std;

/*int coinChange(vector<int>& coins, int amount) // 先用二维的来写，然后这里直接赋值-1是比较冗余的写法
{
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
    if (amount==0) return 0;
    dp[0][0] = 0;
    int tmp=1;
    while (tmp*coins[0]<=amount)
    {
        dp[0][tmp*coins[0]] = tmp;
        tmp++;
    }
    for (int i = 1; i <coins.size()  ; ++i) {
        for (int j = 0; j <=amount ; ++j) {
            if (coins[i]>j)
                dp[i][j] = dp[i-1][j];
            else
            {
                if (dp[i-1][j]==-1 and dp[i][j-coins[i]]!=-1)
                    dp[i][j] = dp[i][j-coins[i]]+1;
                else if (dp[i-1][j]!=-1 and dp[i][j-coins[i]]==-1)
                    dp[i][j] = dp[i-1][j];
                else if (dp[i-1][j]==-1 and dp[i][j-coins[i]]==-1)
                    dp[i][j] =-1;
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i]]+1);
            }
        }
    }
    return dp[coins.size()-1][amount];
}*/

/*
int coinChange(vector<int>& coins, int amount) // 先用二维的来写，然后这里赋值INT_MAX，保证不会被min函数覆盖
{
    vector<vector<int>> dp(coins.size(),vector<int>(amount+1,INT32_MAX));
    if (amount==0) return 0;
    dp[0][0] = 0;
    int tmp=1;
    while (tmp*coins[0]<=amount)
    {
        dp[0][tmp*coins[0]] = tmp;
        tmp++;
    }
    for (int i = 1; i <coins.size()  ; ++i) {
        for (int j = 0; j <=amount ; ++j) {
            if (coins[i]>j)
                dp[i][j] = dp[i-1][j];
            else
            {
                if (dp[i][j-coins[i]]==INT32_MAX)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i]]+1);
            }
        }
    }
    if (dp[coins.size()-1][amount]==INT32_MAX) return -1;
    return dp[coins.size()-1][amount];
}*/

int coinChange(vector<int>& coins, int amount) // 一维的写法
{
    vector<int>dp(amount+1,INT32_MAX);
    if (amount==0) return 0;
    dp[0]=0;
    int tmp=1;
    while (tmp*coins[0]<=amount)
    {
        dp[tmp*coins[0]]= tmp;
        tmp++;
    }
    for (int i = 1; i < coins.size(); ++i) {
        for (int j =coins[i] ; j <=amount ; ++j) {
            if (dp[j-coins[i]]!=INT32_MAX)
                dp[j] = min(dp[j],dp[j-coins[i]]+1);
        }
    }
    if (dp[amount]==INT32_MAX) return -1;
    return dp[amount];
}


int main()
{
    vector<int> coins={1,2,5};
    int amount = 11;
    cout<<coinChange(coins,amount);
}


