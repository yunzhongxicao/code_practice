/*
@File  :offer_2_011.cpp
@Author:dfc
@Date  :2023/2/19  17:46
@Desc  : 0和1 个数相同的子数组
*/
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;
/*int findMaxLength(vector<int>& nums)
{
    vector<int>new_nums(nums.size(),1);
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]==0) new_nums[i] = -1;
    }
    int sum = 0;
    int diff = 0;
    int result = 0;
    unordered_map<int ,int>my_map;
    my_map[0] = -1;
    for (int i = 0; i < new_nums.size(); ++i) {
        sum += new_nums[i];
        diff = sum- 0;
        if (my_map.find(diff) != my_map.end())
        {
            result = max(result, i-my_map.find(diff)->second);
        }
        else
        {
            // 没找到这个前缀 说明长度为0
        }
        if (my_map.find(sum) == my_map.end())
        {
            my_map[sum] = i;
            // 如果前面没有这个和 就更新插入 如果有的话就不更新了 因为最长子数组肯定起始位置尽量小 所以只存第一个的位置
        }
    }
    return result;
}*/

int findMaxLength(vector<int>& nums)
{
    int count_0, count_1;
    unordered_map<int,int>my_map;
    my_map[0] = -1;
    int result =  0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]==0) count_0++;
        else count_1++;
        int diff = count_0 - count_1;
        if (my_map.find(diff) != my_map.end())
        {
            result = max(result,i-my_map.find(diff)->second);
        }
        else
        {
            my_map[diff] = i;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {0,1};
    cout<<findMaxLength(nums);
}

