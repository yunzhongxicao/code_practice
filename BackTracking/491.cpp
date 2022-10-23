/*
@File  :491.cpp
@Author:dfc
@Date  :2022/10/21  16:15
@Desc  : 401递增子序列
*/

#include "iostream"
#include "vector"

using namespace std;

vector<int>path;
vector<vector<int>> result;
//int last_value= -1000;

void backtracking(vector<int>nums, int start_index,int last_value)
{
    if (path.size()>=2) result.push_back(path);

    int u_vec[201]={0};

    for (int i = start_index; i < nums.size(); ++i) {
//        if (i>start_index and nums[i]== nums[i-1]) continue; 注意 这种写法前提是要排序
        if (u_vec[nums[i]+100] ==1) continue;
        if (nums[i]>=last_value )
        {
            path.push_back(nums[i]);
            u_vec[nums[i]+100] = 1;
            backtracking(nums,i+1,nums[i]);
            path.pop_back();
        }
        else
        {
            continue;
        }
    }

}

vector<vector<int>> findSubsequences(vector<int>& nums)
{
    backtracking(nums,0,-1000);
    return result;
}

int main()
{
    vector<int> nums = {1,3,2,2};
    findSubsequences(nums);
    for (auto & i : result) {
        for (int j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

