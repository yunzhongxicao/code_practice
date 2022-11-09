/*
@File  :494.cpp
@Author:dfc
@Date  :2022/11/8  10:53
@Desc  : Ŀ���
*/
#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

/*

int findTargetSumWays(vector<int>& nums, int target) // ���ö�ά����дһ��
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (sum-target<0) return 0;
    if ((sum-target) % 2 !=0) return 0;

    int bag_size = (sum-target)/2;

    vector<vector<int>> dp(nums.size(),vector<int>(bag_size+1,0)); 0-i��Χ�� ѡȡ������ ʹ�ú�Ϊj�ķ�������

    // ����ע�� �����ʼ��ֻ��Ҫ��ʼ����һ�м��� ��Ϊ�������Ͻ���� ���Ե�һ����ʵ�ǲ���Ҫ��ʼ����

    if (nums[0] !=0) // �ȴ����һ�����ǲ����������  ������֮�����жϺ���Ĳ���������
    {
        dp[0][0]=1;
        if(nums[0] <=bag_size) // ����ж�Ҫд�����棬���ж��ǲ���0 Ȼ�������ʼ����һ���� Ȼ�����жϲ���0���������ô����
            dp[0][nums[0]] = 1;
    }
    else if (nums[0]==0) dp[0][0] =2;

    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j <=bag_size ; ++j) {
            if
                (j-nums[i]<0) dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < dp[i].size()  ; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp.back().back();
}
*/

int findTargetSumWays(vector<int>& nums, int target)
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (sum-target<0) return 0;
    if ((sum-target) % 2 !=0) return 0;

    int bag_size = (sum-target)/2;

    vector<int> dp(bag_size+1,0);

    if (nums[0]==0) dp[0]=2;
    else
    {
        dp[0] =1;
        if (nums[0]<=bag_size)
            dp[nums[0]]=1;
    }

    for (int i = 1; i < nums.size(); ++i) {
        for (int j = bag_size  ; j >=nums[i] ; --j) {
            dp[j] = dp[j] + dp[j-nums[i]];
        }
    }
    return dp.back();

}



int  main()
{
    vector<int> nums = {0,1};
    int target = 1;
    int result = findTargetSumWays(nums,target);
    cout<<endl;
    cout<<result;
}


