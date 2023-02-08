/*
@File  :offer_2_010.cpp
@Author:dfc
@Date  :2023/2/8  11:00
@Desc  : ��Ϊk��������
*/
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int,int>my_map;
    int sum = 0;
    my_map[sum]  = 1;
    int diff = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        diff = sum - k;  // ���ǲ�ľ���
        result += my_map[diff];
        my_map[sum] ++;
    }
    return result;
}
