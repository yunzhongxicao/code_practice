/*
@File  :349.cpp
@Author:dfc
@Date  :2022/8/30  10:51
@Desc  :两个数组的交集
*/
#include "map"
#include "string"
#include "iostream"
#include "vector"
#include "unordered_set"
#include <algorithm>

using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main()
{

}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int>result;
    unordered_set<int>nums1_set(nums1.begin(),nums1.end());
    for (int i = 0; i < nums2.size(); ++i) {
        if (nums1_set.find(nums2[i]) != nums1_set.end())
        {
            result.insert(nums2[i]);
        }
    }
    return vector<int>(result.begin(),result.end());  //这里这两种迭代器赋值的写法可以学习一下
}