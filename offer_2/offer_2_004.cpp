/*
@File  :offer_2_004.cpp
@Author:dfc
@Date  :2023/2/8  11:42
@Desc  : 只出现一次的数字
*/
#include "iostream"
#include "vector"
using namespace std;

int singleNumber(vector<int>& nums)
{
    vector<int> count(32,0);
    for (int i = 0; i < 32; ++i) {
        int temp=0;
        for (int j = 0; j < nums.size(); ++j) {
            temp += (nums[j]>>i)&1;
        }
        count[31-i] = temp;
    }
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        result =  (result<<1);
        result = result | (count[i] % 3);
    }
    return result;
}

int main()
{
    vector<int> nums = {2,2,3,2};
    cout<<singleNumber(nums);
}

