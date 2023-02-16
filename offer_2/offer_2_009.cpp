/*
@File  :offer_2_009.cpp
@Author:dfc
@Date  :2023/2/16  15:33
@Desc  : 乘积小于k的子数组
*/
#include "iostream"
#include "vector"
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int  start =0,end=0;
    int pro = 1;
    int  result=0;
    while (end<nums.size())
    {
        pro *= nums[end];  // 每次都是找以end结尾的窗口的左边界
        while (start<=end and pro>=k) // 注意 首尾相等的时候也要进入判断 即end自身也要进去判断
        {
            pro /= nums[start];
            start++;
        }
        result += end-start+1;
        end++;
    }
    return result;
}

