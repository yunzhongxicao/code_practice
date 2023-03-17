/*
@File  :491_second.cpp
@Author:dfc
@Date  :2023/3/17  14:20
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

vector<int> path;
vector<vector<int>>result;

void backtracking(vector<int>&nums, int start, int last_num) // ��Ҫ����һ��Ľڵ㴫����һ��
{
    if (path.size()>=2)
        result.push_back(path);
    map<int,int>my_map;
    for (int i = start; i < nums.size(); ++i) {
        if (my_map[nums[i]]==1) continue;
        if (nums[i]>=last_num)
        {
            my_map[nums[i]] =1; // �������Ҫ���� ��Ϊ��ͬһ��ȥ��
            path.push_back(nums[i]);
            backtracking(nums,i+1,nums[i]);
            path.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums)
{
    backtracking(nums,0,-101); // �ʼ��һ�������е�һ�㶼С����
    return result;

}

