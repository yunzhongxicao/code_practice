/*
@File  :347_second.cpp
@Author:dfc
@Date  :2023/2/27  15:36
@Desc  : 前k个高频元素
*/
#include "unordered_map"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

bool static cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second>b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int,int> my_map;
    for (int i = 0; i < nums.size(); ++i) {
        my_map[nums[i]]++;
    }
    vector<pair<int,int>> count;
    for(auto &i :  my_map)
    {
        count.emplace_back(i);
    }
    sort(count.begin(),count.end(),cmp);
    vector<int>result;
    int i = 0;
    while (k>0)
    {
        result.push_back(count[i].first);
        i++;
        k--;
    }
    return result;
}

