/*
@File  :78.cpp
@Author:dfc
@Date  :2022/10/21  0:52
@Desc  : 子集
*/

#include "vector"
#include "iostream"

using namespace std;

vector<int> path={};
vector<vector<int>> result;

void backtracking(vector<int> nums, int start_index)
{
    if (start_index==nums.size())
    {
        return;
    }
    for (int i = start_index; i <nums.size() ; ++i) {
        vector<int> sub_vector;
        if (i==start_index) sub_vector= {nums[i]};
        else
        {
            vector<int>::const_iterator Fist = nums.begin() + start_index; // 找到第二个迭代器
            vector<int>::const_iterator Second = nums.begin() + i; // 找到第三个迭代器
            sub_vector.assign(Fist,Second);
        }
        // sub_vector.assign;
        result.push_back(sub_vector);
        backtracking(nums,i+1);
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{

    backtracking(nums,0);
    // result.emplace_back(path);

}

int main()
{
    vector<int> nums = {1,2};
    subsets(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

