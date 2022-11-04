/*
@File  :746.cpp
@Author:dfc
@Date  :2022/11/4  11:02
@Desc  : ʹ����С������¥
*/
#include "iostream"
#include "vector"

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    vector<int> dp(cost.size()+1); // �����ǲ����������return ��Ϊcost����>=2
    dp[0]= 0; // Ĭ�ϵ�һ���ǲ���Ǯ��
    dp[1] = 0;
    for (int i = 2; i <=cost.size() ; ++i) {
        dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    return dp[cost.size()];
}
