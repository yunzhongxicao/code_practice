/*
@File  :1_second.cpp
@Author:dfc
@Date  :2023/2/16  13:55
@Desc  : 两数之和
*/
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std ;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int> my_map;

    vector<int> result(2);
    for (int i = 0; i < nums.size(); ++i) {
        if (my_map.find(target-nums[i]) != my_map.end())
        {
            result[0] =i;
            result[1] = my_map.find(target-nums[i])->second;
            return result;
        }
        my_map[nums[i]] = i;
    }
    return result;
}

int main()
{
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int>result =  twoSum(nums,target);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}

