/*
@File  :53.cpp
@Author:dfc
@Date  :2022/10/27  11:58
@Desc  : ����������
*/

#include "iostream"
#include "vector"

using namespace std;
int maxSubArray(vector<int>& nums);

int maxSubArray(vector<int>& nums)
{
    int max_sum = nums[0]-1; // ���ﲻ�ó�ʼ������С�� ֻ��Ҫ�ȵ�һ��С���� ��Ϊ��һ��һ����ȡ��ȥ�ģ�����һ���ܸ�ֵ����һ������
    int sum =0;
    for (int i = 0; i < nums.size(); ++i) {
        if (sum<0)
            sum=nums[i]; // ���ǰ���sumС��0 �ӵ�ǰ��ʼ���¼���
        else
            sum +=nums[i];
        if (sum>max_sum)
            max_sum=sum;
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {5,4,-1};
    int result = maxSubArray(nums);
    cout<<result;
}


