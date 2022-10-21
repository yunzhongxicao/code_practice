/*
@File  :78.cpp
@Author:dfc
@Date  :2022/10/21  0:52
@Desc  : ×Ó¼¯
*/

#include "vector"
#include "iostream"

using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int> nums, int start_index)
{
    result.push_back(path);
    if (start_index==nums.size())
    {
        return;
    }
    for (int i = start_index; i <nums.size() ; ++i) {
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

int main()
{
    vector<int> nums = {1,2,3};
    subsets(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

