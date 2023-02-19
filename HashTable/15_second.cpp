/*
@File  :15_second.cpp
@Author:dfc
@Date  :2023/2/19  16:40
@Desc  : 三数之和
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    if (nums.size()<3) return result;
    for (int i = 0; i <= nums.size()-3 ; ++i) {
        if (nums[i]>0) break; // 这里可以减少一些判断
        if (i>0 and nums[i]==nums[i-1])continue;
        int left = i+1,right = nums.size()-1;
        while (left<right)
        {
            if (left>i+1 and nums[left]==nums[left-1])
            {
                left++;
                continue;
            }
            if (right<nums.size()-1 and nums[right]==nums[right+1])
            {
                right--;
                continue;;
            }
            if (nums[i] + nums[left] + nums[right]<0)
                left++;
            else if (nums[i]+ nums[left] + nums[right]>0    )
                right--;
            else
            {
                result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                left++;
                right--;
            }
        }
    }
    return result;
}

