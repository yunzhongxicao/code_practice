/*
@File  :70.cpp
@Author:dfc
@Date  :2022/11/4  10:27
@Desc  :ÅÀÂ¥Ìİ
*/
#include "iostream"

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