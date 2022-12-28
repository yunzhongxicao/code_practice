/*
@File  :offer_39.cpp
@Author:dfc
@Date  :2022/12/28  11:09
@Desc  : �����г��ִ�������һ�������
*/
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

/*
int majorityElement(vector<int>& nums) // ��ϣ��Ľⷨ
{
    unordered_map<int,int>my_map;
    for (int & num : nums) {
        my_map[num]++;
    }
    for(auto & i : my_map)
    {
        if (i.second>(int )nums.size()/2)
        {
            return i.first;
        }
    }
    return 0;
}*/

int majorityElement(vector<int>& nums)
{
    int votes=0;
    int res;
    for(int & i:nums)
    {
        if (votes==0)
        {
            votes++;
            res=i;
        }
        else
        {
            i==res?votes++:votes--;
        }
    }
    return res;
}