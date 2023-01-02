/*
@File  :offer_51.cpp
@Author:dfc
@Date  :2023/1/2  15:28
@Desc  :数组中的逆序对
*/
#include "iostream"
#include "vector"
using namespace std;

int reversePairs(vector<int>& nums)
{
    if (nums.size()<2) return 0;
    vector<int>dp(nums.size(),0); // dp[i]表示0-> nums[i]的对数
    dp[0] = 0;
    for (int i = 1; i < nums.size(); ++i) {
        int count =0;
        for (int j = 0; j <=i-1 ; ++j) {
            if (nums[j]>nums[i]) count++;
        }
        dp[i] = dp[i-1]+count;
    }
    return dp[nums.size()-1];
}

int main()
{
    vector<int> nums={7,5,6,4};
    cout<<reversePairs(nums);
}

