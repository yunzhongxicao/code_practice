/*
@File  :bag.cpp
@Author:dfc
@Date  :2022/11/7  11:21
@Desc  :背包问题
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
    vector<vector<int>> dp(weight.size(),vector<int>(bagWeight+1,0));

    for (int j = 0; j <=bagWeight ; ++j) {
        if (j>=weight[0]) dp[0][j]=value[0];
    }

    for (int i = 1; i <=weight.size()-1 ; ++i) {
        for (int j = 1; j <=bagWeight ; ++j) {
            if (j<weight[i]) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
            }
        }
    }
    cout << dp[weight.size() - 1][bagWeight] << endl;
}

int main()
{
    test_2_wei_bag_problem();
}

