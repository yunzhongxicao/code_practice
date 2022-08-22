/*
@File  :367.cpp
@Author:dfc
@Date  :2022/8/1  17:01
@Desc  :给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
*/
#include "iostream"
#include "vector"
using namespace std;

bool isPerfectSquare(int x);

int main()
{
    bool a = isPerfectSquare(5);
    cout<<a;
}
bool isPerfectSquare(int x)
{
    int left = 0;
    int right = x;
    int middle;
    if (x<=1)
        return true;
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
            if (x%middle == 0)  //这里要判断一下是否有余数
            {
                return true;
            }
            else
            {
               left = middle+1;
            }
        }
    }
    return false;
}