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
        while (high>low and nums[high]>=k) high--;
        if (high>low)
        {
            swap(nums[low],nums[high]);
            low++;
        }
        while (high>low and nums[low]<=k) low ++;
        if (high>low)
        {
            swap(nums[low],nums[high]);
            high--;
        }
    }
    return low;
}

void quick_sort(vector<int>&nums, int low, int high)
{
    if (low>=high) return; // 如果某一侧没有东西  会出现low>high的情况
    int middle = divide(nums,low,high);
    quick_sort(nums,low,middle-1);
    quick_sort(nums,middle+1,high);
}

int RS(vector<int>&nums, int low, int high,int k)
{
    if (low==high) return nums[low];
    int middle = divide(nums,low,high);
    int temp = high-middle; // middle 后半部分的长度
    if (temp>=k)
        return RS(nums,middle+1,high,k);
    else
        return RS(nums,low,middle,k-temp  );
}

int main()
{
    vector<int> nums = {3,2,5,2,6,4,1};
//    bubble_sort(nums);
    //quick_sort(nums,0,nums.size()-1);
    cout<<RS(nums,0,nums.size()-1,7)<<endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout<<nums[i]<<" ";
    }
}

