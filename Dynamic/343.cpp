/*
@File  :343.cpp
@Author:dfc
@Date  :2022/11/6  12:50
@Desc  : 拆分整数
*/
#include "vector"
#include "iostream"
using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n+1);
//    dp[0]=0;  //这两个初始化没有意义
//    dp[1]=1;
    dp[2]=1;
    for (int i = 3; i <=n ; ++i) {
        int max_value = 0; // max_value只负责每次计算dp[i]的时候进行判断
        for (int j = 1; j <i-1 ; ++j) { // 这里只到n-2即可 因为n-1在j=1的时候判断过了 也可以避开dp[1]没有意义的问题
            max_value= max(max_value, max(j*(i-j),j*dp[i-j]));
        }
        dp[i] = max_value;
    }
    return dp[n];
}

int main()
{
    int result = integerBreak(10);
    cout<<result;
}