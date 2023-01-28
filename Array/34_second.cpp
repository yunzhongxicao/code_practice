/*
@File  :34_second.cpp
@Author:dfc
@Date  :2023/1/28  11:14
@Desc  : 在排序数组中查找元素的第一个和最后一个位置
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    if (nums.size()==0) return vector<int>{-1,-1};
    int left = 0,right = nums.size()-1;
    while (left<right) // 先找左边界，可以按照只有两个数来看结束怎么跳出来
    {
        int middle = left + (right-left)/2;
        if (nums[middle]>target) right=middle-1;
        else if (nums[middle]<target) left =middle+1;
        else if (nums[middle]==target) right = middle;
    }
    if (right<left) return vector<int>{-1,-1};
    else if (nums[left] != target) return vector<int>{-1,-1};
    int left_index = left;
    left = left_index,right=nums.size()-1;

    while (left<right) // 注意 右边界到时候 中间值要变化 往右靠
    {
        int  middle = left + (right-left)/2 +1;
        if (nums[middle]>target) right=middle-1;
        else if (nums[middle]<target) left =middle+1;
        else if (nums[middle]==target) left=middle;
    }
    int right_index = right; // 这里一定能找到
    return vector<int>{left_index,right_index};
}

