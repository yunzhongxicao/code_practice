/*
@File  :46_third.cpp
@Author:dfc
@Date  :2023/7/18  22:09
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>&nums, vector<int>&visited)
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i <=nums.size()-1   ; ++i) {
        if (visited[i]==1) continue;
        path.push_back(nums[i]);
        visited[i] = 1;
        backtracking(nums,visited);
        path.pop_back();
        visited[i] = 0;
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> visited(nums.size(),0);
    backtracking(nums,visited);
    return result;
}