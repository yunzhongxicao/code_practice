/*
@File  :283.cpp
@Author:dfc
@Date  :2022/8/22  11:20
@Desc  : “∆∂Ø ¡„
*/
#include "iostream"
#include "vector"
using namespace std;

void moveZeroes(vector<int>& nums);

int main()
{
    vector<int> a = {0};
    moveZeroes(a);
}

void moveZeroes(vector<int>& nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] !=0)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    for (int i = j; i < nums.size(); ++i) {
        nums[i] = 0;
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout<<nums[i];
    }
}

