/*
@File  :209_third.cpp
@Author:dfc
@Date  :2023/7/14  22:24
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int start = 0 , end =0;
    int result = INT32_MAX;
    int sum = 0;
    while (end<=nums.size()-1 )
    {
        sum += nums[end];
        while (start<=end and sum>=target)
        {
            result = min(result,end-start+1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    if (result==INT32_MAX) return -1;
    return result;
}

