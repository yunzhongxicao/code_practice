/*
@File  :offer_40.cpp
@Author:dfc
@Date  :2022/12/28  11:36
@Desc  : 最小的k个数
*/
#include "iostream"
#include "set"
#include "vector"
using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    set<int>my_set(arr.begin(),arr.end());
    vector<int> result;
    int count= 1;
    for(auto iter=my_set.begin();iter !=my_set.end() and count<=k;++iter)
    {
        result.push_back(*iter);
        count++;
    }
    return result;
}