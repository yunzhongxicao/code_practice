/*
@File  :213_second.cpp
@Author:dfc
@Date  :2023/3/15  11:41
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int rob_range(vector<int>& nums, int start, int end)
{
    if (start == end) return nums[start];
    vector<int>dp(end-start+1);// 表示偷到nums[i]获得的钱 , 像这种要初始化两个值的 默认都是长度要从2开始
    dp[0]=nums[start];
    dp[1]=max(nums[start],nums[start+1]);
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i+start]);
    }
    return dp.back();
}
int rob(vector<int>& nums)
{
    if (nums.size()==1) return nums[0];
    if (nums.size()==2) return max(nums[0],nums[1]);
    int result1 = rob_range(nums,0,nums.size()-2);
    int result2 = rob_range(nums,1,nums.size()-1);
    int  result3 = rob_range(nums,1,nums.size()-2);
    return max(result1,max(result2,result3));
}

int main()
{
    vector<int>nums={2,3,2};
    cout<<rob(nums);
}

