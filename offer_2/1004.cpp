/*
@File  :1004.cpp
@Author:dfc
@Date  :2023/6/5  10:08
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int longestOnes(vector<int>& nums, int k)
{
    int result = 0;
    int left = 0, right  = 0;
    int count  = 0;
    while (right<=nums.size()-1)
    {
        if (nums[right]==0) count++;
        while (count>k)
        {
            if (nums[left]==0) count--;
            left++;
        }
        result  = max(result, right-left+1);
        right++;
    }
    return result;
}

