/*
@File  :offer_62.cpp
@Author:dfc
@Date  :2023/1/16  20:03
@Desc  : ԲȦ�����ʣ�µ�����
*/
#include "iostream"
using namespace std;

int lastRemaining(int n, int m)
{
    int pos= 0;
    for (int i = 2; i <=n ; ++i) {
        pos = (pos+m) % (i+1);
    }
    return pos;
}

