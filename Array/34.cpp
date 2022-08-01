/*
@File  :34.cpp
@Author:dfc
@Date  :2022/8/1  14:38
@Desc  :在排序数组中查找元素的第一个和最后一个位置
*/
#include "iostream"
#include "vector"
using namespace std;
int getRightBorder(vector<int>& nums, int target);
int getLeftBorder(vector<int>& nums, int target);
vector<int> searchRange(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {1};
    int target = 1;
    searchRange(nums,target);
}
int getRightBorder(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size()-1;
    int middle = 0;
    int right_border = -2;
    while (left<=right)
    {
        middle = (int)(left+right)/2;
        if(nums[middle] > target)
        {
            right = middle-1;
        }
        else
        {
            left = middle +1;
            right_border = left;
        }
    }
    return right_border;
}

int getLeftBorder(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size()-1;
    int middle = 0;
    int left_border = -2;
    while (left<=right)
    {
        middle = (int)(left+right)/2;
        if(nums[middle] < target)
        {
            left = middle+1;
        }
        else
        {
            right = middle-1;
            left_border = right;
        }
    }
    return left_border;

}

vector<int> searchRange(vector<int>& nums, int target)
{
    int left_border = getLeftBorder(nums,target);
    int right_border = getRightBorder(nums,target);
    if (left_border==-2 or  right_border==-2)
    {
        cout<<-1<<" "<<-1;
        return {-1,-1};
    }
    else if (right_border-left_border>1)
    {
        cout<< left_border+1<< " " << right_border-1;
        return {left_border+1,right_border-1};
    }
    else
    {
        cout<<-1<<" "<<-1;
        return {-1,-1};
    }
}

