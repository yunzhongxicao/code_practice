/*
@File  :offer_65.cpp
@Author:dfc
@Date  :2023/1/17  20:10
@Desc  : 不用加减乘除做加法
*/
#include "iostream"
using namespace std;

int add(int a, int b)
{
    while (b!=0)
    {
        int temp1 = a^b;
        //LC c++不支持负值左移，需要强制转换为无符号数
        int temp2 = (unsigned int )(a&b)<<1;// 求与 再左移 最多32次就为0
        a = temp1;
        b = temp2;
    }
    return a;

}

