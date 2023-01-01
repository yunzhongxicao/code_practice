/*
@File  :offer_44.cpp
@Author:dfc
@Date  :2023/1/1  20:05
@Desc  : 数字序列中 某一位的数字
*/
#include "iostream"
#include "cmath"
using namespace std;

int findNthDigit(int n)
{
    if (n==0) return 0;
    long long  count = 9;  // 每一层有多少个 比如9 90 900
    int weishu = 1;  // 占了几位
    long long  rest = n;
    while (rest - count * weishu>0)
    {
        rest = rest - count * weishu;
        count *=10;
        weishu++;
    }
    int count_tmp = rest/weishu;
    int yushu = rest % weishu;
    if (yushu==0) return ((int)pow(10,weishu-1)+count_tmp-1) % 10;
    return (((int)pow(10,weishu-1)+count_tmp) / (int )pow(10,weishu-yushu)) % 10;

}

int main()
{
    cout<<findNthDigit(9+180+2700+5);
}

