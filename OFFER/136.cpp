/*
@File  :136.cpp
@Author:dfc
@Date  :2023/1/13  15:37
@Desc  : ֻ����һ�ε�����
*/
#include "iostream"
#include "vector"

using namespace std;

int singleNumber(vector<int>& nums)
{
    int  result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        result = (result ^ nums[i]);
    }
    return result;
}

