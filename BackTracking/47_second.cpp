/*
@File  :47_second.cpp
@Author:dfc
@Date  :2023/3/19  12:25
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>&nums, vector<int>&used)
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]==1) continue;
        if (i>0 and nums[i]==nums[i-1] and used[i-1]==0)
            continue;
        path.push_back(nums[i]);
        used[i]=1;
        backtracking(nums,used);
        path.pop_back();
        used[i]=0;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<int>used(nums.size(),0);
    backtracking(nums,used);
    return result;
}