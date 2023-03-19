/*
@File  :674_second.cpp
@Author:dfc
@Date  :2023/3/19  13:17
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    vector<int>dp(nums.size(),1);// dp[i]��ʾ��i��β���������������г���
    dp[0]=1;
    int result =1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i]>nums[i-1])
            dp[i] = dp[i-1]+1;
        result = max(result,dp[i]);
    }
    return result;
}


