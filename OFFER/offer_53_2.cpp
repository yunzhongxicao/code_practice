/*
@File  :offer_53_2.cpp
@Author:dfc
@Date  :2023/1/14  19:40
@Desc  : 0-n-1��ȱʧ������
*/
#include "iostream"
#include "vector"
using namespace std;

int missingNumber(vector<int>& nums)
{
    if (nums.size()==1) return abs(1-nums[0]);
    if (nums[nums.size()-1] == nums.size()-1) return nums.size(); // ��������ǲ����жϵ�
    int left = 0, right = nums.size()-1;
    int middle;
    while (left<right)  //�ҵ�һ���������±����ֵ��ȵĵ� �൱����߽�
    {
        middle= (left+right)/2;
        if (nums[middle]>middle)
            right = middle;
        else if (nums[middle]==middle)
            left= middle+1;
    }
    return left;
}

