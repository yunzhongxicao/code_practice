/*
@File  :offer_2_006.cpp
@Author:dfc
@Date  :2023/2/15  15:38
@Desc  : 排序数组中两数之和
*/
#include "iostream"
#include "vector"
#include "unordered_map "
using namespace std;

/*vector<int> twoSum(vector<int>& numbers, int target) // 用哈希表 没用到题目中的升序信息
{
    unordered_map<int ,int> my_map;
    for (int i = 0; i < numbers.size(); ++i) {
        my_map[numbers[i]] = i;
    }
    vector<int> result;
    for (int i = 0; i < numbers.size(); ++i) {
        int temp = target-numbers[i];
        if (my_map.find(temp) != my_map.end()   )
        {
            result.push_back(i);
            result.push_back(my_map.find(temp)->second);
            return result;
        }
    }
    return result;
}*/

vector<int> twoSum(vector<int>& numbers, int target)
{
    int start = 0, end=numbers.size()-1;
    vector<int> result(2,0);
    while (start<end)
    {
        if (numbers[start]+numbers[end]>target  )
            end--;
        else if (numbers[start] + numbers[end]<target)
            start++;
        else
        {
            result[0]= start;
            result[1] = end;
            return result;
        }
    }
    return result;
}
