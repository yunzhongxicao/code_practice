/*
@File  :496.cpp
@Author:dfc
@Date  :2022/11/28  10:29
@Desc  : ��һ������Ԫ��
*/
#include "iostream"
#include "unordered_map"
#include "stack"
#include "vector"

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int,int> my_map;
    stack<int> my_stack;
    vector<int> result(nums1.size(),-1);
    for (int i = 0; i < nums1.size(); ++i) {
        my_map[nums1[i]] = i;
    }
    for (int i = 0; i < nums2.size(); ++i) { // ��nums2ÿ��Ԫ�ص��ұ߸���Ԫ�� ����ֻ�ڴ���num1��ʱ����м�¼
        while (!my_stack.empty() and nums2[i] > nums2[my_stack.top()])
        {
            if (my_map.find(nums2[my_stack.top()]) !=my_map.end() )
            {
                result[my_map[nums2[my_stack.top()]]] = nums2[i];
            }
            my_stack.pop();
        }
        my_stack.push(i );
    }
    return result;
}

