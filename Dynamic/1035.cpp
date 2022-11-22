/*
@File  :1035.cpp
@Author:dfc
@Date  :2022/11/22  11:49
@Desc  : 不相交的线
*/
#include "vector"
#include "iostream"
using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
{
    vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),1));
    int tmp=0;
    while (tmp<nums1.size() and  nums1[tmp]!=nums2[0])
    {
        dp[tmp][0] = 0;
        tmp++;
    }
    tmp=0;
    while (tmp<nums2.size() and  nums2[tmp]!=nums1[0])
    {
        dp[0][tmp] = 0;
        tmp++;
    }
    for (int i = 1; i < nums1.size(); ++i) {
        for (int j = 1; j < nums2.size(); ++j) {
            if (nums1[i] == nums2[j]) dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[nums1.size()-1][nums2.size()-1];
}



