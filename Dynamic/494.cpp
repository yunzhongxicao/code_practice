/*
@File  :494.cpp
@Author:dfc
@Date  :2022/11/8  10:53
@Desc  : 目标和
*/
#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

/*

int findTargetSumWays(vector<int>& nums, int target) // 先用二维的来写一下
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (sum-target<0) return 0;
    if ((sum-target) % 2 !=0) return 0;

    int bag_size = (sum-target)/2;

    vector<vector<int>> dp(nums.size(),vector<int>(bag_size+1,0)); 0-i范围内 选取几个数 使得和为j的方案数量

    // 而且注意 这里初始化只需要初始化第一行即可 因为都是左上角相关 所以第一列其实是不需要初始化的

    if (nums[0] !=0) // 先处理第一个数是不是零的问题  处理完之后再判断后面的不是零的情况
    {
        dp[0][0]=1;
        if(nums[0] <=bag_size) // 这个判断要写在里面，先判断是不是0 然后决定初始化第一个数 然后再判断不是0的情况下怎么处理
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


