/*
@File  :offer_03.cpp
@Author:dfc
@Date  :2022/12/4  16:54
@Desc  : 数组中 重复的数字
*/
#include "iostream"
#include "vector"
using namespace std;

int findRepeatNumber(vector<int>& nums)
{
    int repeat[100000]={0};
    for (int i = 0; i < nums.size(); ++i) {
        repeat[nums[i]] ++;
        if (repeat[nums[i]]>=2)
            return nums[i];
    }
    return 0;
}

