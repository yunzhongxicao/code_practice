/*
@File  :377.cpp
@Author:dfc
@Date  :2022/11/12  9:02
@Desc  : 组合总和
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
/*
int combinationSum4(vector<int>& nums, int target) // 先有二维的思想来强行做一下，强行看成背包问题
{
    sort(nums.begin(),nums.end()); // 这里这个排序是必要的 否则后面j-num[k]会超范围
    vector<vector<unsigned long long >> dp(nums.size(),vector<unsigned long long >(target+1,0));
    dp[0][0]=1;
    int tmp=1;
    while (tmp*nums[0]<=target)
    {
        dp[0][tmp*nums[0]] = 1;
        tmp++;
    }
    for (int i = 1; i <nums.size() ; ++i) {
        for (int j = 0; j <=target ; ++j) {
            if (j<nums[i])
                dp[i][j] = dp[i-1][j];
            else
            {
                for (int k = 0; k <=i ; ++k) {
                    dp[i][j] += dp[i][j-nums[k]];
                }
            }
        }
    }
    return dp[nums.size()-1][target];
}*/

int combinationSum4(vector<int>& nums, int target)
{
    vector<unsigned long long > dp(target+1,0); // dp[j]表示总和和j的排列方案数
    dp[0]=1;

    for (int j = 1; j <=target ; ++j) {
        for (int num : nums) {
            if (j>=num)
                dp[j]+=dp[j-num];
        }
    }
    return (int)dp[target];

}

int main()
{
    vector<int> nums={1,2,3};
    int target = 4;
    cout<<combinationSum4(nums,target);
}

