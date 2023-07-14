/*
@File  :977_third.cpp
@Author:dfc
@Date  :2023/7/14  21:57
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int left =0, right = nums.size()-1;
    vector<int> result(nums.size(),0);
    int k = nums.size()-1;
    while (left<=right)
    {
        if (abs(nums[left])<abs(nums[right]))
        {
            result[k] = nums[right] * nums[right];
            right--;
        }
        else if (abs(nums[left])>abs(nums[right]))
        {
            result[k] = nums[left] * nums[left];
            left++;
        }
        else if (abs(nums[left])==abs(nums[right]))
        {
            result[k] = nums[right] * nums[right];
            right--;
        }
        k--;
    }
    return result;
}

