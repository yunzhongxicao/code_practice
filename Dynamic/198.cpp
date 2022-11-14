/*
@File  :198.cpp
@Author:dfc
@Date  :2022/11/14  20:07
@Desc  : ¥Úº“ΩŸ…·
*/
#include "vector"
#include "iostream"
using namespace std;

int rob(vector<int>& nums)
{
    vector<int>dp(nums.size(),0);
    if (nums.size()==1) return nums[0];
    dp[0]=nums[0];
    dp[1] = max(nums[0],nums[1]);
    for (int i = 2; i <nums.size() ; ++i) {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[nums.size()-1];
}

int main()
{
    vector<int> nums={2,7,9,3,1};
    cout<<rob(nums);
}

