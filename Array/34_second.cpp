/*
@File  :34_second.cpp
@Author:dfc
@Date  :2023/1/28  11:14
@Desc  : �����������в���Ԫ�صĵ�һ�������һ��λ��
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    if (nums.size()==0) return vector<int>{-1,-1};
    int left = 0,right = nums.size()-1;
    while (left<right) // ������߽磬���԰���ֻ������������������ô������
    {
        int middle = left + (right-left)/2;
        if (nums[middle]>target) right=middle-1;
        else if (nums[middle]<target) left =middle+1;
        else if (nums[middle]==target) right = middle;
    }
    if (right<left) return vector<int>{-1,-1};
    else if (nums[left] != target) return vector<int>{-1,-1};
    int left_index = left;
    left = left_index,right=nums.size()-1;

    while (left<right) // ע�� �ұ߽絽ʱ�� �м�ֵҪ�仯 ���ҿ�
    {
        int  middle = left + (right-left)/2 +1;
        if (nums[middle]>target) right=middle-1;
        else if (nums[middle]<target) left =middle+1;
        else if (nums[middle]==target) left=middle;
    }
    int right_index = right; // ����һ�����ҵ�
    return vector<int>{left_index,right_index};
}

