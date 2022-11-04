/*
@File  :509.cpp
@Author:dfc
@Date  :2022/11/4  10:04
@Desc  : 斐波拉契数列
*/
#include "iostream"
#include "vector"

using namespace std;

int fib(int n)
{
    if (n<=1) return n; // 要放到前面，不然后面数组赋值会超范围
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for (int i = 2; i <=n ; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int result = fib(5);
    cout<<result;
}