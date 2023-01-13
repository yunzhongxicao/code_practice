/*
@File  :offer_51.cpp
@Author:dfc
@Date  :2023/1/2  15:28
@Desc  :数组中的逆序对
*/
#include "iostream"
#include "vector"
using namespace std;

/*int reversePairs(vector<int>& nums) // 超时了
{
    if (nums.size()<2) return 0;
    vector<int>dp(nums.size(),0); // dp[i]表示0-> nums[i]的对数
    dp[0] = 0;
    for (int i = 1; i < nums.size(); ++i) {
        int count =0;
        for (int j = 0; j <=i-1 ; ++j) {
            if (nums[j]>nums[i]) count++;
        }
        dp[i] = dp[i-1]+count;
    }
    return dp[nums.size()-1];
}*/


int count=0;
void merge(vector<int>&nums, int left, int middle, int  right)
{
    vector<int>temp(right-left+1);
    int i = left,j=middle+1,k=0;
    while (i<=middle and j<=right)
    {
        if (nums[i]<=nums[j])
        {
            temp[k] = nums[i];
            k++;i++;
        }
        else // 前半段的大于后半段 要统计逆序对了
        {
            count += middle-i+1;
            temp[k] = nums[j];
            k++; j++;
        }
    }
    while (i<=middle)
    {
        temp[k] = nums[i];
        k++; i++;
    }
    while (j<=right)
    {
        temp[k] = nums[j];
        k++; j++;
    }
    for (int l = 0; l < temp.size(); ++l) {
        nums[l+left] = temp[l];
    }
}

void merge_sort(vector<int>&nums,int  left, int  right)
{
    if (left==right) return;
    int  middle = (left+right)/2;
    merge_sort(nums,left,middle);
    merge_sort(nums,middle+1,right);
    merge(nums,left,middle,right);
}
int reversePairs(vector<int>& nums)
{
    if (nums.size()==0) return count;
    merge_sort(nums,0,nums.size()-1);
    return count;
}
int main()
{
    vector<int> nums={7,5,6,4};
    cout<<reversePairs(nums);
}

