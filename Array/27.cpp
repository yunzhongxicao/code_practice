/*
@File  :27.cpp
@Author:dfc
@Date  :2022/8/22  10:01
@Desc  :  移除元素
*/
#include "iostream"
#include "vector"
using namespace std;
int removeElement_1(vector<int>& nums, int val);
int removeElement_2(vector<int>& nums, int val);


int main()
{
    vector<int> a = {3,2,2,3};
    int val = 3;
    // int size =     removeElement_1(a,val);
    int size =     removeElement_2(a,val);
    // cout<<size;
    // return 0;
}

int removeElement_1(vector<int>& nums, int val)  // 这是暴力解法
{
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        int tmp = nums[i];
        if (tmp == val)
        {
            for (int j = i; j < size-1; ++j) {
                nums[j] = nums[j+1];
            }
            size--;
            i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
        }

    }
    cout<<size;
    return size;
}

int removeElement_2(vector<int>& nums, int val)  //这是双指针法
{
    int size = nums.size();
    int  j = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    cout<< j;
    return j;
}