/*
@File  :53.cpp
@Author:dfc
@Date  :2022/10/27  11:58
@Desc  : 最大子数组和
*/

#include "iostream"
#include "vector"

using namespace std;
int maxSubArray(vector<int>& nums);

int maxSubArray(vector<int>& nums)
{
    int max_sum = nums[0]-1; // 这里不用初始化到最小的 只需要比第一个小就行 因为第一个一定是取进去的，所以一定能赋值到第一个上面
    int sum =0;
    for (int i = 0; i < nums.size(); ++i) {
        if (sum<0)
            sum=nums[i]; // 如果前面的sum小于0 从当前开始重新计算
        else
            sum +=nums[i];
        if (sum>max_sum)
            max_sum=sum;
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {5,4,-1};
    int result = maxSubArray(nums);
    cout<<result;
}


