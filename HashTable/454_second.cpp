/*
@File  :454_second.cpp
@Author:dfc
@Date  :2023/2/16  15:20
@Desc  : 四数相加2
*/
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    unordered_map<int,int>sum_1,sum_2;
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            sum_1[nums1[i] +  nums2[j]] ++;
        }
    }
    for (int i = 0; i < nums3.size(); ++i) {
        for (int j = 0; j < nums4.size(); ++j) {
            sum_2[nums3[i] +  nums4[j]] ++;
        }
    }
    int result = 0;
    for(auto &iter:sum_1)
    {
        if (sum_2.find(-1*iter.first) != sum_2.end())
        {
            result += iter.second * sum_2.find(-1*iter.first)->second;
        }
    }
    return result;
}

