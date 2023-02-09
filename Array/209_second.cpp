/*
@File  :209_second.cpp
@Author:dfc
@Date  :2023/2/9  13:36
@Desc  : ������С��������
*/
#include "iostream"
#include "vector"
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int result  = nums.size()+1;
    int start=0,end = 0;
    int sum = 0;
    while (end<nums.size())
    {
        sum += nums[end];
        while (sum>=target)  // ���ҵ�����λ��  Ȼ�󲻶��������� �ҵ��Ը�λ�ý�������С����
        {
            int temp =  end-start+1;
            result = min(result,temp);
            sum -= nums[start];
            start++; // ���������һ����һ������Ŀ������� ����ͻ���0
        }
        end++;
    }
    if (result==nums.size()+1) return 0;
    return result;
}

