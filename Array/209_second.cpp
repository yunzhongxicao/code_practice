/*
@File  :209_second.cpp
@Author:dfc
@Date  :2023/2/9  13:36
@Desc  : 长度最小的子数组
*/
#include "iostream"
#include "vector"
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int result  = nums.size()+1;
    int start=0,end = 0;
    int sum = 0;
    while (end<nums.size())
    {
        sum += nums[end];
        while (sum>=target)  // 先找到结束位置  然后不断收缩窗口 找到以该位置结束的最小窗口
        {
            int temp =  end-start+1;
            result = min(result,temp);
            sum -= nums[start];
            start++; // 如果是那种一来就一个数比目标大的情况 这里就会变成0
        }
        end++;
    }
    if (result==nums.size()+1) return 0;
    return result;
}

