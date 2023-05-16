/*
@File  :47.cpp
@Author:dfc
@Date  :2023/5/15  10:45
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>&nums, vector<int> &used)
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]==1) continue;
        if (i>0 and  nums[i]==nums[i-1] and used[i-1]==0) continue;
        used[i] = 1;
        path.push_back(nums[i]);
        backtracking(nums,used);
        used[i]= 0;
        path.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<int> used(nums.size(),0);
    backtracking(nums,used);
    return result;
}

