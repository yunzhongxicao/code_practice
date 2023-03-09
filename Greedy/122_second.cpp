/*
@File  :122_second.cpp
@Author:dfc
@Date  :2023/3/9  11:07
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;
int maxProfit(vector<int>& prices)
{
    int result =0;
    for (int i = 1; i < prices.size() ; ++i) {
        if (prices[i] -  prices[i-1]>0)
            result += prices[i] -  prices[i-1];
    }
    return result;
}

