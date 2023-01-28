/*
@File  :367_second.cpp
@Author:dfc
@Date  :2023/1/28  12:20
@Desc  : 有效的完全平方数
*/
#include "iostream"
using namespace std;

bool isPerfectSquare(int num)
{
    int left = 1, right  = num;
    while (left<=right)
    {
        int  middle = left+(right-left)/2;
        long long temp = (long long )middle*middle;
        if (temp<num) left = middle+1;
        else if (temp>num) right = middle -1;
        else if (temp==num) return true;
    }
    // 最后跳出来一定是在一个 区间里面了
    return false;
}


