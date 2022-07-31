/*
@File  :704.cpp
@Author:dfc
@Date  :2022/7/31  15:37
@Desc  : 704-二分查找
*/
#include "iostream"
#include "vector"
using namespace std;
int search_1(vector<int>&nums, int target);
int search_2(vector<int>&nums, int target);


int main()
{
    vector<int> a = {-1,0,3,5,9,12};
    int  target = 8;
    search_2(a,target);
}

int search_1(vector<int>&nums, int target)  // 这里是没有用到二分法的
{
    int num_length = nums.size();
    for (int i = 0; i < num_length; ++i) {
        if (nums[i] == target)
        {
            cout<<i;
            return i;
        } else if (i==num_length-1)
        {
            cout<<-1;
            return -1;
        }
    }

}

int search_2(vector<int>&nums, int target)  //这个是左闭右闭的二分法写法
{
    int left =  0;
    int right = nums.size()-1;
    while (left<=right)
    {
        int middle = (int ) (left+right)/2;
        if (nums[middle] < target)
        {
            left = middle+1;
        }
        else if (nums[middle]>target)
        {
            right = middle-1;
        } else if (nums[middle] == target)
        {
            cout<<middle;
            return middle;
            break;
        }
    }
    cout<<-1;
    return -1;

}

