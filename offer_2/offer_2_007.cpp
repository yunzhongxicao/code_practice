/*
@File  :offer_2_007.cpp
@Author:dfc
@Date  :2023/2/11  15:53
@Desc  : 数组中和为0的三个数
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int>path;



vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    if (nums.size()<3) return result;

    for (int i = 0; i <= nums.size()-3; ++i) {
        if (nums[i]>0) break;
        if (i>0 and nums[i]==nums[i-1]) continue;
        int left = i+1, right= nums.size()-1;
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
                continue;
            }
            if (nums[i]+nums[left]+nums[right]>0)
                right--;
            else if (nums[i]+nums[left]+nums[right]<0)
                left++;
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

int main()
{
    vector<int> nums = {0,0,0};
    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

