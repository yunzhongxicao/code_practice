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

    // ��ʼ��
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

    // ��ʼ��
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

int main()
{
    test_1_wei_bag_problem();
}

