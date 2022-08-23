/*
@File  :977.cpp
@Author:dfc
@Date  :2022/8/23  9:42
@Desc  : 有序数组的平方
*/

#include "iostream"
#include "vector"
using namespace std;
vector<int> sortedSquares(vector<int>& nums);

int main()
{
    vector<int> a = {-7,-3,2,3,11};
    sortedSquares(a);
}

vector<int> sortedSquares(vector<int>& nums)
{
    int left = 0;
    int right = nums.size()-1;
    vector<int> result(nums.size());
    int k = nums.size()-1;
    while (left<= right)
    {
        if (nums[left] * nums[left] >= nums[right] * nums[right])
        {
            result[k] = nums[left] * nums[left];
            k--;
            left++;
        } else
        {
            result[k] = nums[right] * nums[right];
            k--;
            right--;
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<"   " ;
    }
    return result;
}
