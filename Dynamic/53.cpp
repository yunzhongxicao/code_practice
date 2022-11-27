/*
@File  :53.cpp
@Author:dfc
@Date  :2022/11/22  11:59
@Desc  : 最大子序和
*/
#include "vector"
#include "iostream"
using namespace std;
/*
int maxSubArray(vector<int>& nums) // 先用贪心的方法做一下
{
    int result = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (sum <=0)
        {
            sum = nums[i];
            result = sum;
            continue;
        }
        sum  += nums[i];
        result = max(result,sum);
    }
    return result;
}*/

int maxSubArray(vector<int>& nums)  // 动态规划
{
    vector<int> dp(nums.size()); // 以nums[i]结尾的最大值
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); ++i) { // 其实只关心前缀的正负  当前nums[i]的正负不关系
        dp[i] = max(dp[i-1]+nums[i],nums[i]);  // 要么 接在后面；要么不接在后面，那就是重新开始
        result = max(result,dp[i]);
    }
    return result;
}

