/*
@File  :offer_2_084.cpp
@Author:dfc
@Date  :2023/2/9  10:38
@Desc  : 含有重复元素的全排列
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int>path;
vector<vector<int>>result;

void backtracking(vector<int> &nums, vector<int>used)
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]==1)
            continue;
        if (i>0 and nums[i]==nums[i-1] and used[i-1]==0) // 同一层重复的只取第一个没有被使用的，如果前面一个都没使用 自己肯定也不能使用
            continue;
        path.push_back(nums[i]);
        used[i] = 1;
        backtracking(nums,used);
        used[i] = 0;
        path.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<int>used(nums.size(),0);
    backtracking(nums,used);
    return result;
}

int main()
{
    vector<int> nums={1,1,2};
    permuteUnique(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
