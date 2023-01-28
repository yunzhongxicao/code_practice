/*
@File  :69_second.cpp
@Author:dfc
@Date  :2023/1/28  11:59
@Desc  : x的平方根
*/
#include "iostream"
using namespace std;

int mySqrt(int x)
{
    if (x==0) return 0;
    int left=1,right=x;
    while (left<=right) // 最后的结果是在right->left
    {
        int middle = left+(right-left)/2;
/*        int  temp =x / middle;
        if (temp<middle) right = middle-1;
        else if (temp>middle) left = middle+1;
        else if (temp==middle) return middle;*/

        long long  temp = (long long )middle * middle;
        if (temp>x) right = middle-1;
        else if (temp<x) left = middle+1;
        else if (temp==x) return middle;
    }
    return right;
}

