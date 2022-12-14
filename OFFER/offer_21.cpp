/*
@File  :offer_21.cpp
@Author:dfc
@Date  :2022/12/14  19:58
@Desc  :��������˳��ʹ����λ��ż��ǰ��
*/
#include "vector"
#include "iostream"
using namespace std;

/*
vector<int> exchange(vector<int>& nums) // ����ָ��ķ���
{
    int slow=0,fast=0;
    if (nums.size()==0)return nums;
    int tmp;
    while (fast<=nums.size()-1)
    {
        if ((nums[fast]&1)==1) // ����
        {
            tmp = nums[slow];
            nums[slow]=nums[fast];
            nums[fast] = tmp;
            slow++;
        }
        fast++;
    }
    return nums;
}*/

vector<int> exchange(vector<int>& nums)
{
    int left=0,right = nums.size()-1;
    while (left<right)
    {

        if ((nums[left]&1) == 0 and (nums[right]&1)==1)
        {
            swap(nums[left], nums[right]);
            right--;
            left++;
        }
        else if ((nums[left]&1) == 1)
            left++;
        else if ((nums[right]&1)==0)
            right--;
    }
    return nums;
}

