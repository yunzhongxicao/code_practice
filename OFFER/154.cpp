/*
@File  :154.cpp
@Author:dfc
@Date  :2022/12/8  11:39
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int findMin(vector<int>& nums)
{
    int left=0,right = nums.size()-1;
    while (left<right)
    {
        int mid = left+(right-left)/2;
        if (nums[mid] > nums[right]) left = mid+1;
        else if (nums[mid]<nums[right]) right = mid;
        else if (nums[mid] == nums[right]) right--; // mid�����ܵ���right һ���Ǳ�rightС�� ��Ϊmid������ȡ�� ������left
        // ���������:  nums[mid] == nums[right]�������ظ�Ԫ�صĴ��ڣ����Բ���ȷ��nums[mid]����Сֵ����໹���Ҳ࣬������ǲ���çײ�غ���ĳһ���ֵ�Ԫ�ء�����Ψһ����֪�����ǣ�
//                                      �������ǵ�ֵ��ͬ����������nums[right]������Сֵ������һ�����ġ����Ʒ��nums[mid], ������ǿ��Ժ��Զ��ֲ���������Ҷ˵㡣
    }
    return nums[left];
}

