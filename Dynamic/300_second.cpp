/*
@File  :300_second.cpp
@Author:dfc
@Date  :2023/3/19  12:44
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    vector<int>dp(nums.size(),1); // dp[i]��ʾ��nums[i]��β�ĵ��������еĳ���
    dp[0]=1;
    int result=1;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j <=i-1 ; ++j) {
            if (nums[i]>nums[j])
                dp[i] = max(dp[i],dp[j]+1);
        }
        result = max(result,dp[i]);
    }
    return result;
}