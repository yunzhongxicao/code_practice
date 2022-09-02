/*
@File  :1.cpp
@Author:dfc
@Date  :2022/8/30  12:00
@Desc  : ����֮��
*/

#include "map"
#include "string"
#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
    vector<int>a = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(a,target);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<"  ";
    }
}

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int> nums_map;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {  // ����˵����Ҫһ��ʼ��ȫ�����ӽ�ȥ������һ��һ����� ��������������ֵ�ظ������
        int tmp = target-nums[i];
        auto iter = nums_map.find(tmp);
        if (iter == nums_map.end())
            nums_map.emplace(nums[i],i);
        else
        {
            result.push_back(iter->second);
            result.push_back(i);
            break;
        }
    }
    return result;
}