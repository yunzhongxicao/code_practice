/*
@File  :1207.cpp
@Author:dfc
@Date  :2022/12/3  10:34
@Desc  : 独一无二的出现次数
*/
#include "vector"
#include "unordered_map"
#include "iostream"

using namespace std;
bool uniqueOccurrences(vector<int>& arr)
{
    unordered_map<int,int> map1,map2;
    for (int i = 0; i < arr.size(); ++i) {
        map1[arr[i]]++;
    }
    for(auto i : map1)
    {
        map2[i.second]++;
        if (map2[i.second]>=2) return false;
    }
    return true;
}


