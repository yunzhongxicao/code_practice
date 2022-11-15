/*
@File  :213.cpp
@Author:dfc
@Date  :2022/11/15  10:57
@Desc  : ´ò¼Ò½ÙÉá2
*/
#include "vector"
#include "iostream"
using namespace std;
int rob_range(vector<int>& nums,int start,int end);
int rob(vector<int>& nums)
{
    int n = nums.size();
    if (nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0],nums[1]);
    int tmp1 = rob_range(nums,0,n-2);
    int tmp2 = rob_range(nums,1,n-1);
    return max(tmp1,tmp2);
}

int rob_range(vector<int>& nums,int start,int end)
{
    vector<int>dp(end-start+1,0);
    if (start==end) return nums[start];
    dp[0]=nums[start];
    dp[1] = max(nums[start],nums[start+1]);
    for (int i = start+2; i <=end ; ++i) {
        dp[i-start] = max(dp[i-start-1],dp[i-start-2]+nums[i]);
    }
    return dp[end-start];
}

int main()
{
    vector<int> nums = {2,3,2};
    cout<<rob(nums);
}