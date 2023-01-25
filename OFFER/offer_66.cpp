/*
@File  :offer_66.cpp
@Author:dfc
@Date  :2023/1/25  11:02
@Desc  : 构建乘积数组
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> constructArr(vector<int>& a)
{
    vector<int> v1(a.size(),0);
    vector<int> v2(a.size(),0);
    int  temp =1;
    for (int i = 0; i < a.size(); ++i) {
        temp = temp * a[i];
        v1[i] = temp;
    }
    temp =1;
    for (int i = a.size()-1; i >=0 ; --i) {
        temp = a[i] * temp;
        v2[i] = temp;
    }
    vector<int> result(a.size(),0);

    for (int i = 0; i < a.size(); ++i) {
        temp =1;
        if (i-1>=0)
            temp *= v1[i-1];
        if (i+1<=a.size()-1)
            temp*= v2[i+1];
        result[i] = temp;
    }
    return result;
}

