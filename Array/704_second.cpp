/*
@File  :704_second.cpp
@Author:dfc
@Date  :2023/1/27  23:42
@Desc  :¶þ·Ö²éÕÒ
*/
#include "iostream"
#include "vector"
using namespace std;

int search(vector<int>& nums, int target)
{
    if (nums.size()==0) return -1;
    int left =0, right = nums.size()-1;
    while (left<right)
    {
        int  middle = left+(right-left)/2;
        if (nums[middle]>target) right = middle-1;
        else if (nums[middle]<target) left = middle+1;
        else if (nums[middle]==target) return middle;
    }
    return -1;
}

