/*
@File  :78.cpp
@Author:dfc
@Date  :2023/5/15  10:36
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int> &nums,int start)
{
    if (start>nums.size()-1) return;
    for (int i = start; i <=nums.size()-1  ; ++i) {
        path.push_back(nums[i]);
        result.push_back(path);
        backtracking(nums,i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    result.push_back(path);
    backtracking(nums,0);
    return result;
}

