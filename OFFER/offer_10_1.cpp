/*
@File  :offer_10_1.cpp
@Author:dfc
@Date  :2022/12/5  11:47
@Desc  : 斐波拉契数列
*/
#include "iostream"
#include "vector"
using namespace std;

int fib(int n)
{
    if (n<=1) return n; // 数组初始化会超范围
    vector<int> result(n+1);
    result[0] = 0;
    result[1] = 1;
    for (int i = 2; i <=n ; ++i) {
        result[i] = (result[i-1] + result[i-2]) % (1000000007);
    }
    return result[n];
}


