/*
@File  :1365.cpp
@Author:dfc
@Date  :2022/12/1  10:28
@Desc  : �ж���С�ڵ�ǰ���ֵ�����
*/
#include "vector"
#include "iostream"
#include "unordered_map"
#include "algorithm"
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums)
{
    vector<int> nums_copy = nums;
    sort(nums_copy.begin(),nums_copy.end());
    unordered_map<int,int> my_map;
    for (int i = 0; i < nums_copy.size(); ++i) {
        if (my_map.find(nums_copy[i]) == my_map.end()) // û�ҵ��Ų��룬Ҳ���ԴӺ���ǰ���� ��ô�ͻᱻ���ǵ�
        {
            my_map[nums_copy[i]] = i;
        }
    }
    vector<int> result(nums_copy.size());
    for (int i = 0; i < nums.size(); ++i) {
        result[i] = my_map[nums[i]];
    }
    return result;
}

int main()
{
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> result = smallerNumbersThanCurrent(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}



