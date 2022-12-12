/*
@File  :offer_16.cpp
@Author:dfc
@Date  :2022/12/12  21:44
@Desc  : 数值的整数次方
*/
#include "iostream"
using namespace std;

double myPow(double x, int n)
{
    long n_copy = (long )n;
    if (n_copy==0) return 1;
    if (n_copy<0)
    {
        x = 1/x;
        n_copy = -n_copy;
    }
    double result = 1;
    while (n_copy>=1)
    {
        if (n_copy&1==1)
        {
            result = result*x;
            n_copy=n_copy-1;
        }
        else
        {
            x = x * x;
            n_copy = n_copy>>1;
        }
    }
    return result;
}

int main()
{
    cout<<myPow(2.10000,3);
}