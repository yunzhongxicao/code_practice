/*
@File  :offer_2_008.cpp
@Author:dfc
@Date  :2023/2/15  15:57
@Desc  : 和大于等于target的最短子数组
*/
#include "vector"
#include "iostream"
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int start = 0,end=0;
    int result = nums.size()+1;
    int sum = 0;
    while (end<nums.size())
    {
        sum += nums[end];
        while (sum>=target)
        {
            int temp = end-start+1;
            result = min(result,temp);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    if (result==nums.size()+1) return 0;
    return result;
}

