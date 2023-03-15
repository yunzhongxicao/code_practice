/*
@File  :198_second.cpp
@Author:dfc
@Date  :2023/3/15  11:13
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int rob(vector<int>& nums)
{
    if (nums.size()==1) return nums[0];
    vector<int>dp(nums.size());// 表示偷到nums[i]获得的钱 , 像这种要初始化两个值的 默认都是长度要从2开始
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[nums.size()-1];
}

