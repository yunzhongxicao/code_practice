/*
@File  :1005.cpp
@Author:dfc
@Date  :2022/10/29  9:11
@Desc  : k次取反后最大化的数组和
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool static cmp(const int a, const int b)
{
    return abs(a)> abs(b);
}

int largestSumAfterKNegations(vector<int>& nums, int k)
{
    sort(nums.begin(),nums.end(),cmp); // 先按照绝对值从大到小排
    int result= 0;
    int num_index=0;
    while (k>0 and num_index<=nums.size()-1)
    {
        if (nums[num_index]<0)
        {
            nums[num_index] = -nums[num_index];
            k--;
        }
        num_index++;
    }
    if (k>0)
    {
        if (k%2==1)
        {
            nums[nums.size()-1] = -nums[nums.size()-1];
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        result += nums[i];
    }
    return result;
}

int  main()
{
    vector<int> a = {4,2,3};
    int k =1;
    int  result = largestSumAfterKNegations(a,k);
    cout<<result;
}

