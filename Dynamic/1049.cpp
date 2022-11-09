/*
@File  :1046.cpp
@Author:dfc
@Date  :2022/11/7  21:23
@Desc  : 最后一块石头的重量
*/
#include "iostream"
#include "vector"
#include "numeric"
using namespace std;

int lastStoneWeightII(vector<int>& stones)
{
    int sum = accumulate(stones.begin(),stones.end(),0);

    int bag_size = sum/2;
    vector<int> dp(bag_size+1,0);
    for (int i = 0; i < stones.size(); ++i) {
        for (int j = bag_size; j >=stones[i] ; --j) {
            dp[j] = max(dp[j], stones[i] + dp[j-stones[i]]);
        }
    }
    return sum - dp[bag_size] - dp[bag_size];
}