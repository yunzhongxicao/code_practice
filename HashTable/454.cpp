/*
@File  :454.cpp
@Author:dfc
@Date  :2022/8/31  10:16
@Desc  : 四数相加
*/
#include "map"
#include "string"
#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include <algorithm>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);

int main()
{
    vector<int> a = {1,2};
    vector<int>b = {-2,-1};
    vector<int>c={-1,2} ,d={0,2};
    int e = fourSumCount(a,b,c,d);
    cout<<e;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    unordered_map<int,int>map1,map2;
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            int tmp = nums1[i]+nums2[j];
            map1[tmp]++;
        }
    }
    for (int i = 0; i < nums3.size(); ++i) {
        for (int j = 0; j < nums4.size(); ++j) {
            int tmp = nums3[i]+nums4[j];
            map2[tmp]++;
        }
    }
    int count= 0;
    for(auto i=map1.begin();i!=map1.end();i++)
    {
        int tmp = 0-i->first;
        auto iter = map2.find(tmp);
        if (iter != map2.end())
        {
            count = count + i->second * iter->second;
        }
    }
    return count;
}