/*
@File  :offer_2_083.cpp
@Author:dfc
@Date  :2023/2/9  10:23
@Desc  : 没有重复元素的全排列
*/
#include "iostream"
#include "vector"
using namespace std;



vector<int>path;
vector<vector<int>>result;

void backtracking(vector<int> &nums, vector<int> &used)
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
        used[i] = 0;
        path.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> used(nums.size(),0);
    backtracking(nums,used);
    return result;
}