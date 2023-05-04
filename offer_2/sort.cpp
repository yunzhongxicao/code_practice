/*
@File  :sort.cpp
@Author:dfc
@Date  :2023/5/4  11:29
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

void bubble_sort(vector<int>& nums)
{
    for (int i = nums.size()-2; i >=0 ; --i) {
        for (int j = 0; j <=i ; ++j) {
            if (nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
}

int divide(vector<int>&nums, int low, int high)
{
    int k = nums[low];
    while (low<high)
    {
        while (high>low and )
    }
}

int main()
{
    vector<int> nums = {1,3,5,2,6,4,2};
    bubble_sort(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout<<nums[i]<<" ";
    }
}

