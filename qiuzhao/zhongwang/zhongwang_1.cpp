/*
@File  :zhongwang_1.cpp
@Author:dfc
@Date  :2023/8/15  23:07
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int solution(vector<int> &nums)
{
    int sum = nums[0];
    int result = sum;
    for (int i = 1; i <=nums.size()-1 ; ++i) {
        if (sum<=0)
        {
            sum = nums[i];
        }
        else
        {
            sum += nums[i];
        }
        result = max(result,sum);
    }
    return result;
}

int main()
{
    vector<int>  nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<solution(nums);
}

