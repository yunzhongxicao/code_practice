/*
@File  :674.cpp
@Author:dfc
@Date  :2022/11/21  10:34
@Desc  : 最长连续递增序列
*/
#include "iostream"
#include "vector"
using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    vector<int> dp(nums.size(),1); // 以nums[i]结尾的最长连续递增序列
    dp[0]=1;
    int result =1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i]>nums[i-1])
            dp[i] = dp[i-1]+1;
        result = max(result,dp[i]);
    }
    return result;
}