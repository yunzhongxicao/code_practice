/*
@File  :offer_61.cpp
@Author:dfc
@Date  :2023/1/25  21:56
@Desc  : 扑克牌中的顺子
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool isStraight(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    int zero_num = 0;
    int first_index =0;
    while (nums[first_index]==0)
        first_index++;
    zero_num = first_index;
    if (zero_num==5 or  zero_num==4) return true;
    int diff = 0;
    for (int i = first_index+1; i <nums.size() ; ++i) {
        if(nums[i]== nums[i-1]) return false;
        diff += nums[i]-nums[i-1]-1;
    }
    return zero_num>=diff;
}

