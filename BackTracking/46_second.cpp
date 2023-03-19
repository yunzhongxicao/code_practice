/*
@File  :46_second.cpp
@Author:dfc
@Date  :2023/3/19  12:15
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

vector<int>path;
vector<vector<int>>result;

void backtracking(vector<int>& nums, vector<int>&used)
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]==1) continue;
        path.push_back(nums[i]);
        used[i] = 1;
        backtracking(nums,used);
        path.pop_back();
        used[i]=0;
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> used(nums.size(),0);
    backtracking(nums,used);
    return result;
}