/*
@File  :350_second.cpp
@Author:dfc
@Date  :2023/2/16  11:37
@Desc  : 两个数组的交集
*/
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int,int>my_map;
    for (int i = 0; i < nums1.size(); ++i) {
        my_map[nums1[i]]++;
    }
    vector<int> result;
    for (int i = 0; i < nums2.size(); ++i) {
        if (my_map.find(nums2[i]) != my_map.end() and my_map.find(nums2[i])->second>0)
        {
            my_map.find(nums2[i])->second--;
            result.push_back(nums2[i]);
        }
    }
    return result;
}

