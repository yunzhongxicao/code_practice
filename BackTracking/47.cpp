/*
@File  :47.cpp
@Author:dfc
@Date  :2022/10/22  0:45
@Desc  : È«ÅÅÁÐ2
*/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


vector<int>  path;
vector<vector<int>>result;

void backtracking(vector<int> nums, vector<int> used)
{
    if (path.size()== nums.size())
    {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]==1) continue;
        if (i>0 and nums[i]  == nums[i-1] and used[i-1]==0)
        {

            continue;
        }
        path.push_back(nums[i]);
        used[i] = 1;
        backtracking(nums,used);
        path.pop_back();
        used[i] = 0;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<int> used(nums.size(),0);
    backtracking(nums,used);
    return result;
}

int main()
{
    vector<int> nums = {1,1,3};
    permuteUnique(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

