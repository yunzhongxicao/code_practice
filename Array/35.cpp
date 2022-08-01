/*
@File  :35.cpp
@Author:dfc
@Date  :2022/8/1  0:26
@Desc  : 搜索插入位置
*/
#include "iostream"
#include "vector"
using namespace std;

int searchInsert_1(vector<int>& nums, int target);
int searchInsert_2(vector<int>& nums, int target);
int main()
{
    vector<int> a = {1,3,5,6};
    int  target = 8;
    searchInsert_2(a,target);
    return 0;
}

int searchInsert_1(vector<int>& nums, int target)  //先通过暴力的方式进行
{
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]>=target)
        {
            cout<<i;
            return i;
        }
    }
    cout<< nums.size();
    return nums.size();
}


int searchInsert_2(vector<int>& nums, int target)  //尝试利用二分的方法
{
    int left = 0;
    int right = nums.size()-1;
    int middle = 0;
    while (left<=right)
    {
        middle = (int )(left+right)/2;
        if (nums[middle] > target)
        {
            right = middle-1;
        }
        else if(nums[middle]<target)
        {
            left = middle +1;
        }
        else if (nums[middle] == target)
        {
            cout<<middle;
            return middle;
        }
    }
    cout<<left;
    return left;
}




