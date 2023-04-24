/*
@File  :496_second.cpp
@Author:dfc
@Date  :2023/4/24  10:43
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"
#include "unordered_map"
using namespace std;

/*
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> my_map;
    for (int i = 0; i < nums2.size(); ++i) {
        my_map[nums2[i]] = i;
    }
    vector<int> result(nums1.size(),-1);
    for (int i = 0; i < nums1.size(); ++i) {
        int index = my_map[nums1[i]];
        for (int j = index+1; j <nums2.size()  ; ++j) {
            if (nums2[j]>nums1[i])
            {
                result[i] = nums2[j];
                break;
            }
        }
    }
    return result;
}
*/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int,int>my_map;
    for (int i = 0; i < nums1.size(); ++i) {
        my_map[nums1[i]] = i;
    }
    stack<int> my_stack;
    vector<int> result(nums1.size(),-1);
    for (int i = 0; i < nums2.size(); ++i) {
        while (!my_stack.empty() and nums2[i]>my_stack.top())
        {
            if (my_map.find(my_stack.top()) != my_map.end())
            {
                result[my_map[my_stack.top()]] = nums2[i];
            }
            my_stack.pop();
        }
        my_stack.push(nums2[i]);
    }
    return result;
}