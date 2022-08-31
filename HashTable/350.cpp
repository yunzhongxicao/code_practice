/*
@File  :350.cpp
@Author:dfc
@Date  :2022/8/30  11:04
@Desc  : 两个数组的交集2
*/
#include "map"
#include "string"
#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int,int> nums1_map;
    vector<int> result;
    for (int i = 0; i < nums1.size(); ++i) {
        nums1_map[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); ++i) {
        if(nums1_map[nums2[i]])   // 如果没有的话， 执行这段话虽然会加入键，但是value为0
        {
            result.push_back(nums2[i]);
            nums1_map[nums2[i]]--;
        }
    }
    return result;

}