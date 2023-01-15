/*
@File  :offer_57.cpp
@Author:dfc
@Date  :2023/1/15  10:38
@Desc  : 和为s的两个数字
*/
#include "iostream"
#include "vector"
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
    int left=0, right = nums.size()-1;
    vector<int> result;
    if (left==right) return result;
    int sum;
    while (left<right)
    {
        sum = nums[left] + nums[right];
        if (sum>target)
            right--;
        else if (sum<target)
            left++;
        else return vector<int>{nums[right],nums[left]};
    }
    return result;
}


