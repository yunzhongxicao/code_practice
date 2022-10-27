/*
@File  :376.cpp
@Author:dfc
@Date  :2022/10/27  11:37
@Desc  : 摆动序列
*/


#include "iostream"
#include "vector"
#include "string"

using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
    int pre_diff =0; // 只有在最开始的时候 会是0，相当于-1的地方补了一个nums[0]
    int cur_diff =0;
    int result= 0;
    for (int i = 1; i < nums.size(); ++i) { // i要从1开始 记录i-1，i不是转折点
        cur_diff= nums[i] - nums[i-1];
        if ((cur_diff>0 and pre_diff<=0) or (cur_diff<0 and pre_diff>=0)) // 这个0只有在最开始的时候会出现，后面cur只有在不为0的时候才会赋值给pre
        {
            result++;   // 要特别注意的是 这时候记录的转折点其实是i-1
            pre_diff= cur_diff;
        }
    }
    result++; // 因为最后一个点一定是转折点 因为中间删除也是只取了单调峰的两端 所以最后一个点一定要取到
    return result;
}