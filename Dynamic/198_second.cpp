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
    vector<int>dp(nums.size());// ��ʾ͵��nums[i]��õ�Ǯ , ������Ҫ��ʼ������ֵ�� Ĭ�϶��ǳ���Ҫ��2��ʼ
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[nums.size()-1];
}

