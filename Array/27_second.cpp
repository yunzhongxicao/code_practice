/*
@File  :27_second.cpp
@Author:dfc
@Date  :2023/2/4  10:40
@Desc  :ÒÆ³ýÔªËØ
*/
#include "iostream"
#include "vector"
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    if (nums.size()==0) return 0;
    int slow =0  ,fast = 0;
    while (fast<=nums.size()-1)
    {
        if (nums[fast]==val)
        {
            fast++;
        } else
        {
            nums[slow] =nums[fast];
            slow++;
            fast++;
        }
    }
    return slow;
}

