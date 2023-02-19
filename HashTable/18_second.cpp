/*
@File  :18_second.cpp
@Author:dfc
@Date  :2023/2/19  16:57
@Desc  : 四数之和
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    if (nums.size()<4) return result;
    for (int i = 0; i <=nums.size()-4   ; ++i) {
        if (i>0 and nums[i]== nums[i-1]) continue;
        if (nums[i]>target and (nums[i]>=0 or target>=0)) break;
        for (int j = i+1; j <= nums.size()-3; ++j) {
            if (j>i+1 and nums[j] == nums[j-1]) continue;
            if (nums[i]+nums[j]>target and (nums[i]+nums[j]>=0 or target>=0)) break;
            int left = j+1,right = nums.size()-1;
            while (left<right)
            {
                if (left>j+1 and nums[left]==nums[left-1])
                {
                    left++;
                    continue;
                }
                if (right<nums.size()-1 and nums[right]==nums[right+1   ])
                {
                    right--;
                    continue;
                }
                if ((long)nums[i] + nums[j] + nums[left] + nums[right]<target)
                    left++;
                else if ((long)nums[i] + nums[j] + nums[left] + nums[right]>target)
                    right--;
                else
                {
                    result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                    left++;
                    right--;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    int target= -11;
    vector<vector<int>> result = fourSum(nums,target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
