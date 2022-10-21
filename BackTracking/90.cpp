/*
@File  :90.cpp
@Author:dfc
@Date  :2022/10/21  15:54
@Desc  : ×Ó¼¯2
*/

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int> nums, int start_index)
{
    result.push_back(path);
    if (start_index==nums.size()) return;

    for (int i = start_index; i < nums.size(); ++i) {
        if (i>start_index and nums[i] == nums[i-1]) continue;
        path.push_back(nums[i]);
        backtracking(nums,i+1);
        path.pop_back();
    }

}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    backtracking(nums,0);
    return result;
}

int main()
{
    vector<int> nums = {1,2,2};
    subsetsWithDup(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}