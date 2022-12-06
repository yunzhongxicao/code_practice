/*
@File  :offer_11.cpp
@Author:dfc
@Date  :2022/12/6  10:53
@Desc  : 寻找旋转数组中的最小数字
*/
#include "iostream"
#include "vector"
using namespace std;
int minArray(vector<int>& numbers)
{
    int result = numbers[0];  // 我的想法是 前一段递增 后一段递增  那么只要找到第一个让它下降的点 就是旋转点了
    for (int i = 1; i < numbers.size(); ++i) {
        if (numbers[i]<numbers[i-1])
        {
            result = numbers[i];
            break;
        }
    }
    return result;
}

