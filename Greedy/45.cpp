/*
@File  :45.cpp
@Author:dfc
@Date  :2022/10/28  11:56
@Desc  : 跳跃游戏2
*/

#include "iostream"
#include "vector"

using namespace std;

int jump(vector<int>& nums)
{
    int cur_jump= 0; // 当前能跳的最远距离
    int next_jump = 0; // 下一次能跳到的最远距离

    int result=0 ;
    for (int i = 0; i < nums.size(); ++i) {
        // 是在一次跳的过程中记录下一次跳的最远距离 如果这一次跳没到终点， 那么下一次跳就就到这个过程中记录的最远距离
        next_jump = max(i+nums[i],next_jump);
        if (i==cur_jump) // 达到第一次起跳的终点
        {
            if (cur_jump<nums.size()-1)
            {
                result++; // 需要再次起跳
                cur_jump = next_jump; // 下一次起跳的最远距离
                if (next_jump>=nums.size()-1) break; //  如果下一次起跳的最远距离到终点了，就直接结束，起跳次数以及算进去了
            }
            else break;
        }
    }
    return result;
}


