/*
@File  :977_second.cpp
@Author:dfc
@Date  :2023/2/4  12:02
@Desc  : 有序数组的平方
*/
#include "vector"
#include "iostream"
using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int start = 0,end = nums.size()-1;
    vector<int>result(nums.size());
    int k = nums.size()-1;
    while (start<end)
    {
        if (abs(nums[start]) >= abs(nums[end]))
        {
            result[k] = nums[start] * nums[start];
            k--;
            start++;
        }
        else
        {
            result[k] = nums[end] * nums[end];
            k--;
            end--;
        }
    }
    result[0] = nums[start] * nums[start];
    return result;
}

