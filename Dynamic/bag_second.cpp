/*
@File  :bag_second.cpp
@Author:dfc
@Date  :2023/3/13  14:39
@Desc  :
*/

#include "vector"
#include "iostream"

using namespace std;

void test_2_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<vector<int>>dp(value.size(),vector<int>(bagWeight+1,0));
    for (int j = 0; j < bagWeight+1; ++j) {
        if (j>=weight[0])
            dp[0][j] = value[0];
    }

    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j <dp[i].size() ; ++j) {
            if (j>=weight[i])
                dp[i][j] = max(dp[i-1][j-weight[i]]+value[i],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp.back().back();
}

void test_1_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int>dp(bagWeight+1,0);
    for (int j = 0; j < bagWeight+1; ++j) {
        if (j>=weight[0])
            dp[j]  = value[0];
    }

    for (int i = 1; i < value.size(); ++i) {
        for (int j = bagWeight; j >=weight[i] ;j--) {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }

    }
    cout<<dp[bagWeight];
}

void test_complete_bag_2_wei()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<vector<int>> dp(weight.size(),vector<int>(bagWeight+1,0));
    for (int j = 0; j < bagWeight+1; ++j) {
        dp[0][j] = (j /weight[0]) * value[0];
    }
    for (int i = 1; i < weight.size(); ++i) {
        for (int j = 1; j < bagWeight+1; ++j) {
            if (j>=weight[i])
                dp[i][j] = max(dp[i-1][j],dp[i][j-weight[i]]+value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[weight.size()-1][bagWeight];
}
void test_complete_bag_1_wei()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int>dp(bagWeight+1,0);
    for (int j = 0; j < bagWeight+1; ++j) {
        dp[j] =( j / weight[0]) * value[0];
    }
    for (int j = 0; j < bagWeight+1; ++j) {
        cout<<dp[j]<<" ";
    }
    cout<<endl;
    for (int i = 1; i < weight.size(); ++i) {
        for (int j = weight[i]; j < bagWeight+1; ++j) {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]) ;
        }
        for (int j = 0; j < bagWeight+1; ++j) {
            cout<<dp[j]<<" ";
        }
        cout<<endl;
    }


    cout<<dp[bagWeight];
}


int main()
{
    test_complete_bag_1_wei();
}

