/*
@File  :18.cpp
@Author:dfc
@Date  :2022/9/2  9:57
@Desc  :四树之和
*/


#include "map"
#include "string"
#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main()
{
    vector<int> a = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    int target = 1000000000;
    vector<vector<int>> b = fourSum(a,target);
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[i].size(); ++j) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i <= (int)nums.size()-4 ; ++i) {
        if (i>0 and nums[i] == nums[i-1])
        {
            continue;
        }
        if (nums[i]>target and nums[i]>=0)  // 这里的剪枝判断和三数之和不太一样
        {
            break;
        }
        for (int j = i+1; j <= (int)nums.size()-3; ++j) {
            int  tmp = target-nums[i];
            int left = j+1;
            int right = nums.size()-1;
            if (j>i+1 and nums[j]==nums[j-1])
                continue;
            if ((long)nums[i]+nums[j]>target and (long) nums[i]+nums[j]>=0)
                break;
            while (right>left)
            {
                if ((long)nums[j]+nums[left]+nums[right]>tmp)
                {
                   right--;
                } else if ((long)nums[j]+nums[left]+nums[right]<tmp)   // 注意这里类型转换的写法
                {
                    left++;
                } else
                {
                    vector<int> tmp_result= {nums[i],nums[j],nums[left],nums[right]};
                    result.push_back(tmp_result);
                    while (right>left and nums[right]==nums[right-1]) right--;
                    while (right>left and nums[left] == nums[left+1]) left++;
                    left++;
                    right--;
                }
            }
        }
    }
    return result;
}