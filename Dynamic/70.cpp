/*
@File  :70.cpp
@Author:dfc
@Date  :2022/11/4  10:27
@Desc  :��¥��
*/
#include "iostream"
#include "vector"
using namespace std;


int climbStairs(int n)
{
    if (n<=2) return n;
    int first= 1;
    int second = 2;
    int result = 0;
    for (int i = 3; i <=n ; ++i) {
        result = first+second;
        first = second;
        second = result;
    }
    return result;
}

int climbStairs_2(int n,int m) // n��̨�׸߶� m�������һ���ߵĲ���
{
    vector<int> dp(n+1,0);
    dp[0]=1;
    for (int j = 1; j <=n ; ++j) {
        for (int i = 1; i <=m ; ++i) {
            if (i<=j)
                dp[j] +=dp[j-i];
        }
    }
    return dp[n];
}