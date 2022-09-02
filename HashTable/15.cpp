/*
@File  :15.cpp
@Author:dfc
@Date  :2022/9/1  21:08
@Desc  : 三数之和
*/
#include "map"
#include "string"
#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
    vector<int> a = {0,1,-1};
    vector<vector<int>> b = threeSum(a);
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[i].size(); ++j) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i <= nums.size()-3; ++i) {
        int left = i+1;
        int right = nums.size()-1;
        if (i>0 and nums[i]==nums[i-1])  // 这个i>0一定要判断
        {
            continue;
        }
        while (right>left)
        {
            if (nums[i]+nums[left]+nums[right]>0)
            {
                right--;
            } else if (nums[i]+nums[left]+nums[right]<0)
            {
                left++;
            } else{
                vector<int> tmp= {nums[i],nums[left],nums[right]};
                result.push_back(tmp);
                while (right>left and nums[right]==nums[right-1]) right--;
                while (right>left and nums[left] == nums[left+1]) left++;
                left++;
                right--;
            }
        }
    }
    return result;
}