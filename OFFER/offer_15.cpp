/*
@File  :offer_15.cpp
@Author:dfc
@Date  :2022/12/12  11:54
@Desc  : ��������1�ĸ���
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


