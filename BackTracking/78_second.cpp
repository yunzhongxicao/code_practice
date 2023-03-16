/*
@File  :78_second.cpp
@Author:dfc
@Date  :2023/3/16  10:54
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

vector<int>path;
vector<vector<int>>result;

void backtracking(vector<int> &nums,int  start)
{
    result.push_back(path);
    if (start==nums.size())
        return;
    for (int i = start; i <nums.size() ; ++i) {
        path.push_back(nums[i]);
        backtracking(nums,i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    backtracking(nums,0);
    return result;
}

