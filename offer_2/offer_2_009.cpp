/*
@File  :offer_2_009.cpp
@Author:dfc
@Date  :2023/2/16  15:33
@Desc  : �˻�С��k��������
*/
#include "iostream"
#include "vector"
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int  start =0,end=0;
    int pro = 1;
    int  result=0;
    while (end<nums.size())
    {
        pro *= nums[end];  // ÿ�ζ�������end��β�Ĵ��ڵ���߽�
        while (start<=end and pro>=k) // ע�� ��β��ȵ�ʱ��ҲҪ�����ж� ��end����ҲҪ��ȥ�ж�
        {
            pro /= nums[start];
            start++;
        }
        result += end-start+1;
        end++;
    }
    return result;
}

