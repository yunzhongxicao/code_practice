/*
@File  :offer_15.cpp
@Author:dfc
@Date  :2022/12/12  11:54
@Desc  : 二进制中1的个数
*/
#include "iostream"
using namespace std;

/*int hammingWeight(uint32_t n) // 这是不涉及位运算 直接把每一位都求出来 模拟了一下求的过程
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
}*/

/*int hammingWeight(uint32_t n)// 从右往左 把每一位都取出来进行比较
{
    int count= 0;
    for (int i = 0; i < 32; ++i) {
        count += ((n>>i) & 1); 与00001进行与运算 前面都是0 只用看最后一位是不是1 是1结果就为1 直接加上去 不是1结果为0 也可以加上去
    }
    return count;
}*/

int hammingWeight(uint32_t n) // 比到高位为0就结束
{
    int count = 0;
    while (n !=0)
    {
        count += n&1;
        n = n>>1;
    }
    return count;

}


