/*
@File  :209.cpp
@Author:dfc
@Date  :2022/8/23  9:56
@Desc  : 长度最小的子数组
*/

#include "iostream"
#include "vector"
using namespace std;

int minSubArrayLen(int target, vector<int>& nums);

int main()
{
    vector<int> a = {1,1,1,1,1,1,1};
    int b = 11;
    minSubArrayLen(b,a);
}

int minSubArrayLen(int target, vector<int>& nums)
{
    int j = 0;
    int sum = 0;
    int result = INT32_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        while (sum >= target)   // 每次找到一个结束位置后，就要不断循环把初始位置找出来
        {
            int sub_length = i-j+1;
            sum = sum - nums[j];
            j++;
            result = result<sub_length ?result:sub_length;
        }


    }
    result = result==INT32_MAX?0:result;
    cout<<result;
}

