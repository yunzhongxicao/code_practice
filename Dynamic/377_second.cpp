/*
@File  :377_second.cpp
@Author:dfc
@Date  :2023/3/14  11:29
@Desc  :
*/
#include "iostream"
#include "bits/stdc++.h"
using namespace std;

int combinationSum4(vector<int>& nums, int target)
{
    vector<vector<long long >>dp(nums.size(),vector<long long >(target+1,0)); // 以nums[i]结尾 目标为j的
    for (int j = 1; j <target+1 ; ++j) {
        for (int i = 0; i <nums.size() ; ++i) {
            if (j==nums[i]) dp[i][j]=1;
            else if (j<nums[i]) dp[i][j] =0;
            else
            {
                for (int k = 0; k <=nums.size()-1; ++k) {
                    dp[i][j] += dp[k][j-nums[i]];
                }
            }
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int result=0;
    for (int i = 0; i < nums.size(); ++i) {
        result += dp[i][target];
    }
    return result;
}

int main()
{
    vector<int>nums = {1,2,3};
    int target =4;
    combinationSum4(nums,target);
}

