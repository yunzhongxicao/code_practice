/*
@File  :26_third.cpp
@Author:dfc
@Date  :2023/7/10  19:44
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int slow = 0 ,fast = 0;
    while (fast<=nums.size()-1)
    {
        while (fast+1<=nums.size()-1 and nums[fast+1] == nums[fast] )
        {
            fast++;
        }
        nums[slow] = nums[fast];
        slow++; fast++;
    }
    return slow;
}

