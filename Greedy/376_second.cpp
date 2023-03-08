/*
@File  :376_second.cpp
@Author:dfc
@Date  :2023/3/8  20:23
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
    if (nums.size()==1) return 1;
    int cur_diff=0;
    int last_diff=0;
    int result=0;
    for (int i = 1; i < nums.size(); ++i) {
        cur_diff = nums[i] - nums[i-1];
        if ((cur_diff>0 and last_diff<=0) or (cur_diff<0 and last_diff>=0) )
        {
            result++;
            last_diff = cur_diff;
        }
    }
    result++;
    return result;
}