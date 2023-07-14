/*
@File  :27_third.cpp
@Author:dfc
@Date  :2023/7/10  19:14
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int fast = 0 ,slow = 0;
    while (fast<=int (nums.size())-1)
    {
        if (nums[fast]==val)
        {
            fast++;
            continue;
        } else
        {
            swap(nums[slow],nums[fast]);
            slow++;
            fast++;
        }
    }
    return slow;
}

