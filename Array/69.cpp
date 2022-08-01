/*
@File  :69.cpp
@Author:dfc
@Date  :2022/8/1  16:13
@Desc  :给你一个非负整数 x ，计算并返回 x 的 算术平方根
*/
#include "iostream"
#include "vector"
using namespace std;

int mySqrt(int x);

int main()
{
    int a = mySqrt(257);
    cout<<a;
}

int mySqrt(int x)
{
    int left = 0;
    int right = x;
    int middle;
    if (x<=1)
        return x;
    while (left<=right)
    {
        middle = (int)(left+right)/2;
        if (middle >x/middle)
        {
            right = middle-1;
        }
        else if (middle  < x/middle)  //注意这里用除法 防止溢出
        {
            left = middle +1;
        }
        else
        {
            return middle;
        }
    }
    return right;
}