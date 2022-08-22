/*
@File  :26.cpp
@Author:dfc
@Date  :2022/8/22  10:47
@Desc  : 删除有序数组中的重复元素
*/
#include "iostream"
#include "vector"
using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> a = {1,1,2,3,5,6,6,7};
    removeDuplicates(a);
}

int removeDuplicates(vector<int>& nums)
{
    int j = 1;
    for (int i = 1; i <nums.size(); ++i) {
        if (nums[i] != nums[i-1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    cout<<j<<endl;
    for (int k = 0; k < j; ++k) {
        cout<<nums[k];
    }
    return j;
}

