/*
@File  :416.cpp
@Author:dfc
@Date  :2022/11/7  19:52
@Desc  : 分割等和子集
*/
#include "iostream"
#include "vector"
#include "numeric"
using namespace std;

bool canPartition(vector<int>& nums)
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (sum % 2!=0) return false;
    int bag_size = sum/2;

    vector<int> dp(bag_size+1,0);
    for (int i = 0; i <nums.size() ; ++i) {
        for (int j = bag_size; j >=nums[i] ; --j) {
            dp[j] = max(dp[j],nums[i]+dp[j-nums[i]]);
        }
    }
    if (dp[bag_size]==bag_size) return true;
    return false;

}
