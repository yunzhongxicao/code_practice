/*
@File  :283_second.cpp
@Author:dfc
@Date  :2023/2/4  11:13
@Desc  : “∆∂Ø ¡„
*/

#include "vector"
#include "iostream"
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int slow = 0, fast= 0;
    while (fast<=nums.size()-1)
    {
        if (nums[fast]==0)
        {
            fast++;
        }
        else
        {
            swap(nums[fast],nums[slow]);
            fast++;
            slow++;
        }
    }
}
