/*
@File  :offer_15.cpp
@Author:dfc
@Date  :2022/12/12  11:54
@Desc  : 二进制中1的个数
*/
#include "iostream"
using namespace std;
int hammingWeight(uint32_t n)
{
    int mod=0;
    int count =0;
    while (n !=0)
    {
        mod = n % 2;
        if (mod==1) count++;
        n = n/2;
    }
    return count;
}


