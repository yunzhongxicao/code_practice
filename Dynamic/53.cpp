/*
@File  :53.cpp
@Author:dfc
@Date  :2022/11/22  11:59
@Desc  : ��������
*/
#include "vector"
#include "iostream"
using namespace std;
/*
int maxSubArray(vector<int>& nums) // ����̰�ĵķ�����һ��
{
    int result = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (sum <=0)
        {
            sum = nums[i];
            result = sum;
            continue;
        }
        sum  += nums[i];
        result = max(result,sum);
    }
    return result;
}*/

int maxSubArray(vector<int>& nums)  // ��̬�滮
{
    vector<int> dp(nums.size()); // ��nums[i]��β�����ֵ
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); ++i) { // ��ʵֻ����ǰ׺������  ��ǰnums[i]����������ϵ
        dp[i] = max(dp[i-1]+nums[i],nums[i]);  // Ҫô ���ں��棻Ҫô�����ں��棬�Ǿ������¿�ʼ
        result = max(result,dp[i]);
    }
    return result;
}

