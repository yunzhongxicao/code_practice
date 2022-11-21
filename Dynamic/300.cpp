/*
@File  :300.cpp
@Author:dfc
@Date  :2022/11/20  14:03
@Desc  : �����������
*/
#include "iostream"
#include "vector"

using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    vector<int>dp(nums.size(),1);  // ��ʾ��nums[i]��β��������г��� ���ǳ���Ϊi��nums�������еĳ���
                                            // �ѽ�βд�� �Ż��������������ƹ�ʽ
    dp[0] =1;
    int result = 1;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j <=i-1; ++j) {
            if (nums[j]<nums[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
        result = max(result,dp[i]);
    }
    return result;
}

int main()
{
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout<<lengthOfLIS(nums);
}