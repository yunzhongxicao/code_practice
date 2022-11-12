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

int combinationSum4(vector<int>& nums, int target) // 先有二维的思想来强行做一下，强行看成背包问题
{
    sort(nums.begin(),nums.end());
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

}

int main()
{
    vector<int> nums={1,2,3};
    int target = 4;
    cout<<combinationSum4(nums,target);
}

