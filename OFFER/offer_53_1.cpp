/*
@File  :offer_53_1.cpp
@Author:dfc
@Date  :2023/1/13  22:21
@Desc  : �����������в�������1
*/
#include "iostream"
#include "vector"
using namespace std;

int search(vector<int>& nums, int target)
{
    if (nums.size()==0) return 0;
    if (nums.size()==1) return nums[0]==target;
    // ������߽磬
    int left_index,right_index;
    int left=0, right = nums.size()-1;
    while (left<right)
    {
        int middle = (left+right)/2; // ����ȡ��
        if (nums[middle]<target)
            left = middle+1;
        else if (nums[middle]>target)
            right = middle-1;
        else
            right = middle;
    }
    // ֻ��������������� ��ô�����������
    if (nums[left]!=target) return 0;
    left_index =left;

    // ���ұ߽�
    left=left_index, right = nums.size()-1;
    while (left<right)
    {
        int middle = (left+right)/2+1; // ����ȡ��
        if (nums[middle]<target)
            left = middle+1;
        else if (nums[middle]>target)
            right = middle-1;
        else
            left = middle;
    }
    right_index = left;
    return right_index-left_index+1;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    cout<<search(nums,target);
}

